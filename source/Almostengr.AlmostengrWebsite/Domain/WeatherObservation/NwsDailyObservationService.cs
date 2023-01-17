using System.Text;
using Almostengr.AlmostengrWebsite.Domain.Common.Interfaces;
using Almostengr.AlmostengrWebsite.Domain.WeatherObservation.Exceptions;

namespace Almostengr.AlmostengrWebsite.Domain.WeatherObservation;

internal sealed class NwsDailyObservationService : INwsDailyObservationService
{
    private readonly INwsObservationHttpClient _httpClient;

    public NwsDailyObservationService(INwsObservationHttpClient nwsObservationHttpClient)
    {
        _httpClient = nwsObservationHttpClient;
    }

    public async Task<int> GetWeatherDataAsync()
    {
        try
        {
            NwsDailyObservationDto observation =
                await _httpClient.GetAsync<NwsDailyObservationDto>("https://api.weather.gov/stations/kmgm/observations");

            if (observation == null)
            {
                throw new NwsObservationIsNullException();
            }

            DateTime observationDate = observation.Features.First().properties.Timestamp;

            if (observationDate == null)
            {
                throw new ObservationDateInvalidException();
            }

            StringBuilder blogPostText = new();
            StringBuilder csvFileText = new();

            if (observationDate.Day == 2)
            {
                blogPostText.Append(CreateBlogPostHeader(observationDate));
                csvFileText.Append(CreateCsvHeader());
            }

            // blogPostText.Append(observation.ProcessBlogPostData());
            // csvFileText.Append(observation.ProcessCsvData());

            DateTime firstOfTheMonth = new DateTime(observationDate.Year, observationDate.Month, 01);

            string blogFilename = string.Concat(
                firstOfTheMonth.ToString("yyyy.MM.dd"),
                "-",
                firstOfTheMonth.ToString("MMMM-yyyy").ToLower(),
                "-weather.md"
                );

            string csvFilename = string.Concat(
                firstOfTheMonth.ToString("yyyyMMMM").ToLower(),
                "-weather.csv"
                );

            WriteDataToFile(blogPostText.ToString(), blogFilename);
            WriteDataToFile(csvFileText.ToString(), csvFilename);

            return 0;
        }
        catch (Exception ex)
        {
            Console.WriteLine(ex.InnerException);
            Console.WriteLine(ex.Message);
            return 1;
        }
    }

    private void WriteDataToFile(string fileText, string fileName)
    {
        const string GardenBlogDirectory = "/var/tmp";
        // const string GardenBlogDirectory = "website/docs/lifestyle/";
        string logFile = GardenBlogDirectory + fileName;

        Console.WriteLine("Writing data to " + logFile);

        using (StreamWriter file = new StreamWriter(logFile, true))
        {
            file.Write(fileText);
        }

        Console.WriteLine("Done writing data to " + fileName);
    }

    private string CreateCsvHeader()
    {
        Console.WriteLine("Building CSV file header");

        StringBuilder output = new StringBuilder();
        output.Append("DateTime,Temperature,TempUnit,Precipitation,PrecipUnit,Humidity,HumidityUnit,");

        Console.WriteLine("Done buliding CSV file header");

        return output.ToString();
    }

    private string CreateBlogPostHeader(DateTime dateTime)
    {
        Console.WriteLine("Building blog post header");

        string monthYear = new DateTime(dateTime.Year, dateTime.Month, 01).ToString("MMMM yyyy");

        StringBuilder output = new StringBuilder();
        output.Append("---");
        output.Append("title: Weather Data for " + monthYear);
        output.Append("posted: " + dateTime.ToString("yyyy-MM-dd"));
        output.Append("author: automation");
        output.Append("category: gardening");
        output.Append("description: Weather data from the National Weather Service for " + monthYear);
        output.Append("---");
        output.Append(string.Empty);
        output.Append("Weather data as reported from the National Weather Service for the weather station ");
        output.Append("that is closest to my garden. Data is pulled via API from the NWS and saved to this ");
        output.Append("blog post daily.");
        output.Append(string.Empty);
        output.Append("|Date|Min Temp C (F)|Max Temp C (F)|Avg Temp C (F)|Min RH|Max RH|Avg RH|Precip M (In)|Avg Precip/Hr|");
        output.Append("|---|---|---|---|---|---|---|---|---|");

        Console.WriteLine("Done building blog post header");

        return output.ToString();
    }
}