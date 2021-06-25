using System;
using static Almostengr.AlmostengrWebsite.Common.AeJson;
using System.Collections.Generic;
using System.IO;

namespace Almostengr.AlmostengrWebsite.GardenWeather
{
    class Program
    {
        static DateTime currentDate = DateTime.Now.Date;

        static async System.Threading.Tasks.Task<int> Main(string[] args)
        {
            try
            {
                const string weatherObservationsUri = "https://api.weather.gov/stations/kmgm/observations";
                NwsObservation observation = await GetRequestAsync<NwsObservation>(weatherObservationsUri);

                if (observation == null)
                {
                    return 2;
                }

                List<Feature> yesterdayData = GetYesterdayWeatherData(observation);

                if (yesterdayData.Count == 0)
                {
                    return 3;
                }

                List<string> blogPostText = new List<string>();
                List<string> csvFileText = new List<string>();

                if (currentDate.Day == 2)
                {
                    blogPostText = CreateBlogPostHeader(yesterdayData);
                    csvFileText = CreateCsvHeader(yesterdayData);
                }

                blogPostText = ProcessBlogPostData(blogPostText, yesterdayData);
                csvFileText = ProcessCsvData(csvFileText, yesterdayData);

                string blogFilename = string.Empty, csvFilename = string.Empty;

                foreach (var feature in yesterdayData)
                {
                    blogFilename = string.Concat(
                        new DateTime(feature.Properties.Timestamp.Year, feature.Properties.Timestamp.Month, 01).ToString("yyyy-MM-dd"),
                        "-",
                        new DateTime(feature.Properties.Timestamp.Year, feature.Properties.Timestamp.Month, 01).ToString("MMMM-yyyy").ToLower(),
                        "-precipitation.md"
                        );

                    csvFilename = string.Concat(
                        new DateTime(feature.Properties.Timestamp.Year, feature.Properties.Timestamp.Month, 01).ToString("yyyyMMMM").ToLower(),
                        "-precipitation.csv"
                        );

                    break;
                }

                WriteDataToFile(blogPostText, blogFilename);
                WriteDataToFile(csvFileText, csvFilename);

                return 0;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                return 1;
            }
        }

        private static void WriteDataToFile(List<string> fileText, string filename)
        {
            const string GardenBlogDirectory = "Almostengr.AlmostengrWebsite/docs/gardening/";
            string logFile = GardenBlogDirectory + filename;

            Console.WriteLine("Writing data to " + logFile);

            using (StreamWriter file = new StreamWriter(logFile, true))
            {
                foreach (string line in fileText)
                {
                    file.WriteLine(line);
                }
            }

            Console.WriteLine("Done writing data to " + filename);
        }

        private static List<string> CreateCsvHeader(List<Feature> yesterdayData)
        {
            Console.WriteLine("Building CSV file header");

            List<string> output = new List<string>();
            output.Add("DateTime,Temperature,TempUnit,Precipitation,PrecipUnit,Humidity,HumidityUnit,");

            Console.WriteLine("Done buliding CSV file header");

            return output;
        }

        private static List<string> CreateBlogPostHeader(List<Feature> features)
        {
            Console.WriteLine("Building blog post header");

            int reportedMonth = 0;
            int reportedYear = 0;

            foreach (var feature in features)
            {
                reportedMonth = feature.Properties.Timestamp.Month;
                reportedYear = feature.Properties.Timestamp.Year;
                break;
            }

            string monthYear = new DateTime(reportedYear, reportedMonth, 01).ToString("MMMM yyyy");
            List<string> output = new List<string>();

            output.Add("---");
            output.Add("title: Precipitation Data for " + monthYear);
            output.Add("posted: " + currentDate.ToString("yyyy-MM-dd"));
            output.Add("author: Kenny Robinson (via automation)");
            output.Add("category: gardening");
            output.Add("description: Weather data from the National Weather Service for  " + monthYear);
            output.Add("---");
            output.Add(string.Empty);
            output.Add("Weather data as reported from the National Weather Service for the weather station ");
            output.Add("that is cloest to my garden.");
            output.Add(string.Empty);
            output.Add("|Date|Min Temp|Max Temp|Avg Temp|Min Humidity|Max Humidity|Avg Humidity|Precip (M)|Precip (Inches)|Avg Precip / Hr|");
            output.Add("|---|---|---|---|---|---|---|---|---|");

            Console.WriteLine("Done building blog post header");

            return output;
        }

        private static List<string> ProcessCsvData(List<string> text, List<Feature> features)
        {
            foreach (Feature feature in features)
            {
                string line = feature.Properties.Timestamp.ToString("yyyy-MM-dd hh:mm:ss");
                line += ",";
                line += feature.Properties.Temperature.Value;
                line += ",";
                line += feature.Properties.Temperature.UnitCode.Replace("unit:", "");
                line += ",";
                line += (string.IsNullOrEmpty(feature.Properties.PrecipitationLastHour.Value.ToString()) ? 0 : feature.Properties.PrecipitationLastHour.Value);
                line += ",";
                line += feature.Properties.PrecipitationLastHour.UnitCode.Replace("unit:", "");
                line += ",";
                line += feature.Properties.RelativeHumidity.Value;
                line += ",";
                line += feature.Properties.RelativeHumidity.UnitCode.Replace("unit:", "");
                line += ",";

                text.Add(line);
            }

            return text;
        }

        private static List<string> ProcessBlogPostData(List<string> text, List<Feature> features)
        {
            string reportDate = string.Empty;

            foreach (var feature in features)
            {
                reportDate = new DateTime(
                    feature.Properties.Timestamp.Year,
                    feature.Properties.Timestamp.Month,
                    feature.Properties.Timestamp.Day)
                    .ToString("yyyy-MM-dd");
                break;
            }

            double? sumTemperature = 0.0;
            double? maxTemperature = null;
            double? minTemperature = null;

            double? sumHumidity = 0.0;
            double? maxHumidity = null;
            double? minHumidity = null;

            double? sumPrecipM = 0.0;

            foreach (var feature in features)
            {
                // temperature

                maxTemperature = (maxTemperature == null || feature.Properties.Temperature.Value > maxTemperature) ?
                    feature.Properties.Temperature.Value : maxTemperature;
                minTemperature = (minTemperature == null || feature.Properties.Temperature.Value < minTemperature) ?
                    feature.Properties.Temperature.Value : minTemperature;
                sumTemperature += feature.Properties.Temperature.Value;

                // humidity

                maxHumidity = (maxHumidity == null || feature.Properties.RelativeHumidity.Value > maxHumidity) ?
                    feature.Properties.RelativeHumidity.Value : maxHumidity;
                minHumidity = (minHumidity == null || feature.Properties.RelativeHumidity.Value < minTemperature) ?
                    feature.Properties.RelativeHumidity.Value : minHumidity;
                sumHumidity += feature.Properties.RelativeHumidity.Value;

                // precipitation

                sumPrecipM += feature.Properties.PrecipitationLastHour.Value;
            }

            sumPrecipM = sumPrecipM == null ? 0 : sumPrecipM;

            double? sumPrecipInch = sumPrecipM * 39.370078740157;

            string line = "|";
            line += reportDate;
            line += "|";
            line += string.Format("{0:N1}", minTemperature);
            line += "|";
            line += string.Format("{0:N1}", maxTemperature);
            line += "|";
            line += string.Format("{0:N1}", sumTemperature / features.Count);
            line += "|";
            line += string.Format("{0:N0}", minHumidity);
            line += "|";
            line += string.Format("{0:N0}", maxHumidity);
            line += "|";
            line += string.Format("{0:N0}", sumHumidity / features.Count);
            line += "|";
            line += string.Format("{0:N5}", sumPrecipM);
            line += "|";
            line += string.Format("{0:N5}", sumPrecipInch);
            line += "|";
            line += string.Format("{0:N5}", sumPrecipInch / features.Count);
            line += "|";

            text.Add(line);

            return text;
        }

        private static List<Feature> GetYesterdayWeatherData(NwsObservation observation)
        {
            List<Feature> yesterdayData = new List<Feature>();

            foreach (var feature in observation.Features)
            {
                if (feature.Properties.Timestamp.Date == currentDate.AddDays(-1))
                {
                    yesterdayData.Add(feature);
                }
            }

            return yesterdayData;
        }

    }
}
