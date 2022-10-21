using System.Text;
using Almostengr.AlmostengrWebsite.WeatherObservation.Exceptions;
using Newtonsoft.Json;

namespace Almostengr.AlmostengrWebsite.WeatherObservation;

internal sealed class NwsObservationService
{
    private static HttpClient _httpClient;
    private static DateTime _currentDate;

    public NwsObservationService()
    {
        _httpClient = new HttpClient();
        _currentDate = DateTime.Now;
    }

    public static async Task<T> GetRequestAsync<T>(string url) where T : class
    {
        _httpClient.DefaultRequestHeaders.Clear();
        _httpClient.DefaultRequestHeaders.UserAgent.ParseAdd("(blog, tharam04@yahoo.com)");
        _httpClient.DefaultRequestHeaders.Accept.ParseAdd("applicatoin/ld+json");

        Console.WriteLine("Getting requested data");

        HttpResponseMessage repsonse = await _httpClient.GetAsync(url);

        if (repsonse.IsSuccessStatusCode == false)
        {
            throw new BadRequestException(repsonse.StatusCode + " " + repsonse.ReasonPhrase);
        }

        T? result = JsonConvert.DeserializeObject<T>(repsonse.Content.ReadAsStringAsync().Result);

        if (result == null)
        {
            throw new JsonResultIsNullOrWhiteSpaceException();
        }

        return result;
    }

    internal async Task<int> GetWeatherDataAsync()
    {
        try
        {
            const string weatherObservationsUri = "https://api.weather.gov/stations/kmgm/observations";
            NwsDailyObservationDto observation = await GetRequestAsync<NwsDailyObservationDto>(weatherObservationsUri);

            if (observation == null)
            {
                throw new NwsObservationIsNullException();
            }

            DateTime observationDate = observation.Features.First().Properties.Timestamp;

            // List<Feature> yesterdayData = observation.GetYesterdayWeatherData();
            // NwsDailyObservationEntity entity = observation.YesterdayWeatherDataAsEntity();

            // List<string> blogPostText = new List<string>();
            // List<string> csvFileText = new List<string>();

            StringBuilder blogPostText = new();
            StringBuilder csvFileText = new();

            if (_currentDate.Day == 2)
            {
                blogPostText.Append(CreateBlogPostHeader(observationDate));
                // blogPostText = CreateBlogPostHeader(yesterdayData);
                csvFileText.Append(CreateCsvHeader());
                // csvFileText = CreateCsvHeader(yesterdayData);
            }

            // blogPostText = ProcessBlogPostData(blogPostText, yesterdayData);
            // csvFileText = ProcessCsvData(csvFileText, yesterdayData);

            string blogFilename = string.Concat(
                new DateTime(observationDate.Year, observationDate.Month, 01).ToString("yyyy.MM.dd"),
                "-",
                new DateTime(observationDate.Year, observationDate.Month, 01).ToString("MMMM-yyyy").ToLower(),
                "-weather.md"
                );

            string csvFilename = string.Concat(
                new DateTime(observationDate.Year, observationDate.Month, 01).ToString("yyyyMMMM").ToLower(),
                "-weather.csv"
                );

            blogPostText.Append(observation.ProcessBlogPostData());
            csvFileText.Append(observation.ProcessCsvData());


            // foreach (var feature in yesterdayData)
            // {
            //     blogFilename = string.Concat(
            //         new DateTime(feature.Properties.Timestamp.Year, feature.Properties.Timestamp.Month, 01).ToString("yyyy.MM.dd"),
            //         "-",
            //         new DateTime(feature.Properties.Timestamp.Year, feature.Properties.Timestamp.Month, 01).ToString("MMMM-yyyy").ToLower(),
            //         "-weather.md"
            //         );

            //     csvFilename = string.Concat(
            //         new DateTime(feature.Properties.Timestamp.Year, feature.Properties.Timestamp.Month, 01).ToString("yyyyMMMM").ToLower(),
            //         "-weather.csv"
            //         );

            //     break;
            // }

            WriteDataToFile(blogPostText.ToString(), blogFilename);
            WriteDataToFile(csvFileText.ToString(), csvFilename);

            return 0;
        }
        catch (Exception ex)
        {
            Console.WriteLine(ex.Message);
            return 1;
        }
    }

    // private static void WriteDataToFile(List<string> fileText, string filename)
    private static void WriteDataToFile(string fileText, string filename)
    {
        const string GardenBlogDirectory = "website/docs/lifestyle/";
        string logFile = GardenBlogDirectory + filename;

        Console.WriteLine("Writing data to " + logFile);

        using (StreamWriter file = new StreamWriter(logFile, true))
        {
            // foreach (string line in fileText)
            // {
            //     file.WriteLine(line);
            // }
            file.Write(fileText);
        }

        Console.WriteLine("Done writing data to " + filename);
    }

    // private static List<string> CreateCsvHeader(List<Feature> yesterdayData)
    private string CreateCsvHeader()
    {
        Console.WriteLine("Building CSV file header");

        // List<string> output = new List<string>();
        StringBuilder output = new StringBuilder();
        output.Append("DateTime,Temperature,TempUnit,Precipitation,PrecipUnit,Humidity,HumidityUnit,");

        Console.WriteLine("Done buliding CSV file header");

        return output.ToString();
    }

    // private static List<string> CreateBlogPostHeader(List<Feature> features)
    private string CreateBlogPostHeader(DateTime dateTime)
    {
        Console.WriteLine("Building blog post header");

        // int reportedMonth = dateTime.Month;
        // int reportedYear = dateTime.Year;

        // foreach (var feature in features)
        // {
        //     reportedMonth = feature.Properties.Timestamp.Month;
        //     reportedYear = feature.Properties.Timestamp.Year;
        //     break;
        // }

        string monthYear = new DateTime(dateTime.Year, dateTime.Month, 01).ToString("MMMM yyyy");
        // List<string> output = new List<string>();

        // output.Add("---");
        // output.Add("title: Weather Data for " + monthYear);
        // output.Add("posted: " + _currentDate.ToString("yyyy-MM-dd"));
        // output.Add("author: automation");
        // output.Add("category: gardening");
        // output.Add("description: Weather data from the National Weather Service for " + monthYear);
        // output.Add("---");
        // output.Add(string.Empty);
        // output.Add("Weather data as reported from the National Weather Service for the weather station ");
        // output.Add("that is cloest to my garden. Data is pulled via API from the NWS and saved to this ");
        // output.Add("blog post daily.");
        // output.Add(string.Empty);
        // output.Add("|Date|Min Temp C (F)|Max Temp C (F)|Avg Temp C (F)|Min RH|Max RH|Avg RH|Precip M (In)|Avg Precip/Hr|");
        // output.Add("|---|---|---|---|---|---|---|---|---|");

        StringBuilder output = new StringBuilder();
        output.Append("---");
        output.Append("title: Weather Data for " + monthYear);
        output.Append("posted: " + _currentDate.ToString("yyyy-MM-dd"));
        output.Append("author: automation");
        output.Append("category: gardening");
        output.Append("description: Weather data from the National Weather Service for " + monthYear);
        output.Append("---");
        output.Append(string.Empty);
        output.Append("Weather data as reported from the National Weather Service for the weather station ");
        output.Append("that is cloest to my garden. Data is pulled via API from the NWS and saved to this ");
        output.Append("blog post daily.");
        output.Append(string.Empty);
        output.Append("|Date|Min Temp C (F)|Max Temp C (F)|Avg Temp C (F)|Min RH|Max RH|Avg RH|Precip M (In)|Avg Precip/Hr|");
        output.Append("|---|---|---|---|---|---|---|---|---|");

        Console.WriteLine("Done building blog post header");

        return output.ToString();
    }

    // private static List<string> ProcessCsvData(List<string> text, List<Feature> features)
    // {
    //     const string Separator = ",";

    //     foreach (Feature feature in features)
    //     {
    //         StringBuilder sb = new StringBuilder(feature.Properties.Timestamp.ToString("yyyy-MM-dd HH:mm:ss"));
    //         sb.Append(Separator);
    //         sb.Append(feature.Properties.Temperature.Value);
    //         sb.Append(Separator);
    //         sb.Append(feature.Properties.Temperature.UnitCode.Replace("unit:", ""));
    //         sb.Append(Separator);
    //         sb.Append((string.IsNullOrEmpty(feature.Properties.PrecipitationLastHour.Value.ToString()) ? 0 : feature.Properties.PrecipitationLastHour.Value));
    //         sb.Append(Separator);
    //         sb.Append(feature.Properties.PrecipitationLastHour.UnitCode.Replace("unit:", ""));
    //         sb.Append(Separator);
    //         sb.Append(feature.Properties.RelativeHumidity.Value);
    //         sb.Append(Separator);
    //         sb.Append(feature.Properties.RelativeHumidity.UnitCode.Replace("unit:", ""));
    //         sb.Append(Separator);

    //         text.Add(sb.ToString());
    //     }

    //     return text;
    // }

    // private static List<string> ProcessBlogPostData(List<string> text, List<Feature> features)
    // {
    //     string reportDate = string.Empty;

    //     foreach (var feature in features)
    //     {
    //         reportDate = new DateTime(
    //             feature.Properties.Timestamp.Year,
    //             feature.Properties.Timestamp.Month,
    //             feature.Properties.Timestamp.Day)
    //             .ToString("yyyy-MM-dd");
    //         break;
    //     }

    //     double? sumTemperature = 0.0;
    //     double? maxTemperature = null;
    //     double? minTemperature = null;

    //     double? sumHumidity = 0.0;
    //     double? maxHumidity = null;
    //     double? minHumidity = null;

    //     double? sumPrecipM = 0.0;

    //     foreach (var feature in features)
    //     {
    //         // temperature

    //         maxTemperature = (maxTemperature == null || feature.Properties.Temperature.Value > maxTemperature) ?
    //             feature.Properties.Temperature.Value : maxTemperature;
    //         minTemperature = (minTemperature == null || feature.Properties.Temperature.Value < minTemperature) ?
    //             feature.Properties.Temperature.Value : minTemperature;
    //         sumTemperature += feature.Properties.Temperature.Value;

    //         // humidity

    //         maxHumidity = (maxHumidity == null || feature.Properties.RelativeHumidity.Value > maxHumidity) ?
    //             feature.Properties.RelativeHumidity.Value : maxHumidity;
    //         minHumidity = (minHumidity == null || feature.Properties.RelativeHumidity.Value < minHumidity) ?
    //             feature.Properties.RelativeHumidity.Value : minHumidity;
    //         sumHumidity += feature.Properties.RelativeHumidity.Value;

    //         // precipitation

    //         sumPrecipM += feature.Properties.PrecipitationLastHour.Value > 0 ? feature.Properties.PrecipitationLastHour.Value : 0;
    //     }

    //     double? sumPrecipInch = sumPrecipM * 39.370078740157;

    //     string line = "|";
    //     line += reportDate;
    //     line += "|";
    //     line += string.Format("{0:N1}", minTemperature);
    //     line += " (" + string.Format("{0:N1}", ((minTemperature * 1.8) + 32)) + ")";
    //     line += "|";
    //     line += string.Format("{0:N1}", maxTemperature);
    //     line += " (" + string.Format("{0:N1}", ((maxTemperature * 1.8) + 32)) + ")";
    //     line += "|";
    //     line += string.Format("{0:N1}", sumTemperature / features.Count);
    //     line += " (" + string.Format("{0:N1}", (((sumTemperature / features.Count) * 1.8) + 32)) + ")";
    //     line += "|";
    //     line += string.Format("{0:N0}", minHumidity);
    //     line += "|";
    //     line += string.Format("{0:N0}", maxHumidity);
    //     line += "|";
    //     line += string.Format("{0:N0}", sumHumidity / features.Count);
    //     line += "|";
    //     line += string.Format("{0:N3}", sumPrecipM);
    //     line += " (" + string.Format("{0:N3}", sumPrecipInch) + ")";
    //     line += "|";
    //     line += string.Format("{0:N3}", sumPrecipInch / features.Count);
    //     line += " (" + string.Format("{0:N3}", sumPrecipInch / features.Count) + ")";
    //     line += "|";

    //     text.Add(line);

    //     return text;
    // }

}