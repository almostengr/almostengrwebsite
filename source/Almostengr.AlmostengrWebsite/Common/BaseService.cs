using System.Text.Json;
using Almostengr.AlmostengrWebsite.WeatherObservation.Exceptions;
// using Newtonsoft.Json;

namespace Almostengr.AlmostengrWebsite.Common;

public abstract class BaseService
{
    private readonly HttpClient _httpClient;

    protected BaseService()
    {
        _httpClient = new HttpClient();
    }

    public async Task<T> GetRequestAsync<T>(string url) where T : BaseDto
    {
        _httpClient.DefaultRequestHeaders.Clear();
        _httpClient.DefaultRequestHeaders.UserAgent.ParseAdd("(blog, tharam04@yahoo.com)");
        _httpClient.DefaultRequestHeaders.Accept.ParseAdd("applicatoin/ld+json");

        Console.WriteLine("Getting requested data");

        // HttpResponseMessage response = await _httpClient.GetAsync(url);
        var response = await _httpClient.GetAsync(url);

        if (response.IsSuccessStatusCode == false)
        {
            throw new BadRequestException(response.StatusCode + " " + response.ReasonPhrase);
        }

        // T? result = JsonConvert.DeserializeObject<T>(response.Content.ReadAsStringAsync().Result);
        T? result = JsonSerializer.Deserialize<T>(response.Content.ReadAsStringAsync().Result);

        if (result == null)
        {
            throw new JsonResultIsNullOrWhiteSpaceException();
        }

        return result;
    }
}