using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Almostengr.AlmostengrWebsite.Common.GardeningData.DomainServices.Resources;
using System.Threading.Tasks;
using System.Text;
using Almostengr.AlmostengrWebsite.Common.GardeningData.DomainServices.Interfaces;
using Almostengr.AlmostengrWebsite.Common.Common.Infrastructure.Interfaces;

namespace Almostengr.AlmostengrWebsite.Common.GardeningData.DomainServices;

public sealed class AddDataToFileService : IAddDataToFileService
{
    private readonly IAeJson _aeJson;

    public AddDataToFileService(IAeJson aeJson)
    {
        _aeJson = aeJson;
    }

    public async Task<int> ExecuteAsync()
    {
        DateTime currentDate = DateTime.Now.Date;

        try
        {
            const string weatherObservationsUri = "https://api.weather.gov/stations/kmgm/observations";
            NwsObservationResource observation = await _aeJson.GetRequestAsync<NwsObservationResource>(weatherObservationsUri);
            if (observation == null)
            {
                return 2;
            }

            List<Feature> yesterdayData = GetYesterdayWeatherData(observation);
            if (yesterdayData.Count == 0)
            {
                return 3;
            }

            StringBuilder blogPostText = new();
            StringBuilder csvFileText = new();

            if (currentDate.Day == 2)
            {
                CreateBlogPostHeader(blogPostText, yesterdayData);
                CreateCsvHeader(csvFileText);
            }

            ProcessBlogPostData(blogPostText, yesterdayData);
            ProcessCsvData(csvFileText, yesterdayData);

            DateTime yesterdayDate = yesterdayData.Select(d => d.Properties.Timestamp.Date).First();
            DateOnly firstDayOfMonth = DateOnly.FromDateTime(new DateTime(yesterdayDate.Year, yesterdayDate.Month, 01));

            string blogFilename = string.Concat(firstDayOfMonth.ToString("yyyy.MM.dd"), "-", firstDayOfMonth.ToString("MMMM-yyyy").ToLower(), "-weather.md");
            string csvFilename = string.Concat(firstDayOfMonth.ToString("yyyyMMMM").ToLower(), "-weather.csv");

            WriteDataToFile(blogPostText, blogFilename);
            WriteDataToFile(csvFileText, csvFilename);

            return 0;
        }
        catch (Exception ex)
        {
            Console.WriteLine(ex.Message);
            Console.WriteLine(ex);
            return 1;
        }
    }

    private static void WriteDataToFile(StringBuilder content, string filename)
    {
        const string GardenBlogDirectory = "website/docs/gardening/";
        string logFile = GardenBlogDirectory + filename;

        Console.WriteLine("Writing data to " + logFile);

        using (StreamWriter file = new StreamWriter(logFile, true))
        {
            file.WriteLine(content.ToString());
        }

        Console.WriteLine("Done writing data to " + filename);
    }

    private static void CreateCsvHeader(StringBuilder content)
    {
        Console.WriteLine("Building CSV file header");

        content.AppendLine("DateTime,Temperature,TempUnit,Precipitation,PrecipUnit,Humidity,HumidityUnit,");

        Console.WriteLine("Done buliding CSV file header");
    }

    private static void CreateBlogPostHeader(StringBuilder content, List<Feature> features)
    {
        Console.WriteLine("Building blog post header");

        DateTime reportingDate = features.Select(f => f.Properties.Timestamp).First();
        string monthYear = new DateTime(reportingDate.Year, reportingDate.Month, 01).ToString("MMMM yyyy");

        content.Append("---");
        content.Append("title: Weather Data for " + monthYear);
        content.Append("posted: " + DateTime.Now.ToString("yyyy-MM-dd"));
        content.Append("author: automation");
        content.Append("category: gardening");
        content.Append("description: Weather data from the National Weather Service for " + monthYear);
        content.Append("---");
        content.Append(string.Empty);
        content.Append("Weather data as reported from the National Weather Service for the weather station ");
        content.Append("that is cloest to my garden. Data is pulled via API from the NWS and saved to this ");
        content.Append("blog post daily.");
        content.Append(string.Empty);
        content.Append("|Date|Min Temp C (F)|Max Temp C (F)|Avg Temp C (F)|Min RH|Max RH|Avg RH|Precip M (In)|Avg Precip/Hr|");
        content.Append("|---|---|---|---|---|---|---|---|---|");

        Console.WriteLine("Done building blog post header");
    }

    private static void ProcessCsvData(StringBuilder content, List<Feature> features)
    {
        foreach (Feature feature in features)
        {
            content.Append(feature.Properties.Timestamp.ToString("yyyy-MM-dd HH:mm:ss"));
            content.Append(',');
            content.Append(feature.Properties.Temperature.Value);
            content.Append(',');
            content.Append(feature.Properties.Temperature.UnitCode.Replace("unit:", string.Empty));
            content.Append(',');
            content.Append(feature.Properties.PrecipitationLast3Hours.Value.HasValue ? feature.Properties.PrecipitationLast3Hours.Value : 0);
            content.Append(',');
            content.Append(feature.Properties.PrecipitationLast3Hours.UnitCode.Replace("unit:", string.Empty));
            content.Append(',');
            content.Append(feature.Properties.RelativeHumidity.Value);
            content.Append(',');
            content.Append(feature.Properties.RelativeHumidity.UnitCode.Replace("unit:", string.Empty));
            content.AppendLine(",");
        }
    }

    private static void ProcessBlogPostData(StringBuilder content, List<Feature> features)
    {
        Feature firstFeature = features.FirstOrDefault();
        if (firstFeature == null)
        {
            return;
        }

        string reportDate = new DateTime(
            firstFeature.Properties.Timestamp.Year,
            firstFeature.Properties.Timestamp.Month,
            firstFeature.Properties.Timestamp.Day)
            .ToString("yyyy-MM-dd");

        double? sumTemperature = features.Sum(f => f.Properties.Temperature.Value.HasValue ? f.Properties.Temperature.Value : 0);
        double? maxTemperature = features.Max(f => f.Properties.Temperature.Value.HasValue ? f.Properties.Temperature.Value : 0);
        double? minTemperature = features.Min(f => f.Properties.Temperature.Value.HasValue ? f.Properties.Temperature.Value : 0);

        double? sumHumidity = features.Sum(f => f.Properties.RelativeHumidity.Value.HasValue ? f.Properties.RelativeHumidity.Value : 0);
        double? maxHumidity = features.Max(f => f.Properties.RelativeHumidity.Value.HasValue ? f.Properties.RelativeHumidity.Value : 0);
        double? minHumidity = features.Min(f => f.Properties.RelativeHumidity.Value.HasValue ? f.Properties.RelativeHumidity.Value : 0);

        double? sumPrecipitation = features.Sum(f => f.Properties.PrecipitationLast3Hours.Value.HasValue ? f.Properties.PrecipitationLast3Hours.Value : 0);

        double? sumPrecipInch = sumPrecipitation * 39.370078740157;

        content.Append("|");
        content.Append(reportDate);
        content.Append("|");
        content.Append(string.Format("{0:N1}", minTemperature));
        content.Append(" (" + string.Format("{0:N1}", ((minTemperature * 1.8) + 32)) + ")");
        content.Append("|");
        content.Append(string.Format("{0:N1}", maxTemperature));
        content.Append(" (" + string.Format("{0:N1}", ((maxTemperature * 1.8) + 32)) + ")");
        content.Append("|");
        content.Append(string.Format("{0:N1}", sumTemperature / features.Count));
        content.Append(" (" + string.Format("{0:N1}", (((sumTemperature / features.Count) * 1.8) + 32)) + ")");
        content.Append("|");
        content.Append(string.Format("{0:N0}", minHumidity));
        content.Append("|");
        content.Append(string.Format("{0:N0}", maxHumidity));
        content.Append("|");
        content.Append(string.Format("{0:N0}", sumHumidity / features.Count));
        content.Append("|");
        content.Append(string.Format("{0:N3}", sumPrecipitation));
        content.Append(" (" + string.Format("{0:N3}", sumPrecipInch) + ")");
        content.Append("|");
        content.Append(string.Format("{0:N3}", sumPrecipInch / features.Count));
        content.Append(" (" + string.Format("{0:N3}", sumPrecipInch / features.Count) + ")");
        content.AppendLine("|");
    }

    private static List<Feature> GetYesterdayWeatherData(NwsObservationResource observation)
    {
        List<Feature> yesterdayData = new List<Feature>();

        foreach (var feature in observation.Features)
        {
            if (feature.Properties.Timestamp.Date == DateTime.Now.AddDays(-1))
            {
                yesterdayData.Add(feature);
            }
        }

        return yesterdayData;
    }
}
