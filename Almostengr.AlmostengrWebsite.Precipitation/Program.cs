using System;
using static Almostengr.AlmostengrWebsite.Common.AeJson;
using System.Collections.Generic;
using System.IO;

namespace Almostengr.AlmostengrWebsite.Precipitation
{
    class Program
    {
        static DateTime currentDate = DateTime.Now.Date;

        static async System.Threading.Tasks.Task<int> Main(string[] args)
        {
            try
            {
                const string weatherObservations = "https://api.weather.gov/stations/kmgm/observations";
                NwsObservation observation = await GetRequestAsync<NwsObservation>(weatherObservations);

                List<Feature> yesterdayData = GetYesterdayWeatherData(observation);

                WriteWeatherDataToBlog(yesterdayData);

                return 0;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                return 1;
            }
        }

        private static List<Feature> GetYesterdayWeatherData(NwsObservation observation)
        {
            List<Feature> yesterdayData = new List<Feature>();

            foreach (var feature in observation.Features)
            {
                if (feature.Properties.Timestamp.Date == currentDate.AddDays(-1) &&
                    feature.Properties.PrecipitationLastHour.Value > 0)
                {
                    yesterdayData.Add(feature);
                }
            }

            return yesterdayData;
        }

        private static void WriteWeatherDataToBlog(List<Feature> features)
        {
            Console.WriteLine("Creating blog post");

            if (features.Count == 0)
            {
                Console.WriteLine("No records to document");
                return;
            }

            const string GardenBlogDirectory = "Almostengr.AlmostengrWebsite/docs/gardening/";
            string postTitle = "Precipitation Data for " + currentDate.AddDays(-1).Date.ToString("yyyy-MM-dd");

            List<string> textFile = new List<string>();
            textFile.Add("---");
            textFile.Add("title: " + postTitle);
            textFile.Add("posted: " + currentDate.ToString("yyyy-MM-dd"));
            textFile.Add("author: Kenny Robinson (via automation)");
            textFile.Add("category: gardening");
            textFile.Add("description: Previous days precipitation data from the National Weather Service on " + DateTime.Now);
            textFile.Add("---");
            textFile.Add(string.Empty);
            
            textFile.Add("Data was pulled from the National Weather Service (NWS) at " + DateTime.Now);
            textFile.Add(string.Empty);

            textFile.Add("## Precipitation By Hour");
            textFile.Add(string.Empty);

            textFile.Add("|Date|Rainfail|Rainfall Converted|");
            textFile.Add("---|---|---");

            double? valueTotalM = 0.0;
            double? valueTotalInches = 0.0;

            foreach (var feature in features)
            {
                valueTotalM += feature.Properties.PrecipitationLastHour.Value;

                double? inches = feature.Properties.PrecipitationLastHour.Value * 39.370078740157;
                valueTotalInches += inches;

                string line = string.Concat(
                    "|",
                    feature.Properties.Timestamp,
                    "|",
                    string.Format("{0:N5}", feature.Properties.PrecipitationLastHour.Value),
                    " ",
                    feature.Properties.PrecipitationLastHour.UnitCode.Replace("unit:", ""),
                    "|",
                    string.Format("{0:N5}", inches),
                    " inches",
                    "|"
                );

                textFile.Add(line);
            }

            textFile.Add(string.Empty);

            textFile.Add("## Precipitation By Day");
            textFile.Add(string.Empty);
            textFile.Add(string.Format("{0:N5}", valueTotalM) + " m, " + string.Format("{0:N5}", valueTotalInches) + " inches");
            textFile.Add(string.Empty);

            try
            {
                string fileName = string.Concat(
                    currentDate.ToString("yyyy-MM-dd"),
                    "-",
                    postTitle.ToLower().Replace(" ", "-").Replace(":", string.Empty),
                    ".md");

                FileStream logFile = File.Create(GardenBlogDirectory + fileName);
                StreamWriter file = new StreamWriter(logFile);
                foreach (string line in textFile)
                {
                    file.WriteLine(line);
                }

                file.Close();
                file.Dispose();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.WriteLine("Done creating blog post");
        }

    }
}
