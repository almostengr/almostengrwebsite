using Almostengr.AlmostengrWebsite.Common;
using Almostengr.AlmostengrWebsite.Infrastructure.Exceptions;
using Almostengr.AlmostengrWebsite.Infrastructure.Interfaces;
using Newtonsoft.Json;

namespace Almostengr.AlmostengrWebsite.Infrastructure;

public sealed class NwsObservationHttpClient : INwsObservationHttpClient
{
    private readonly HttpClient _httpClient;

    public NwsObservationHttpClient()
    {
        _httpClient = new HttpClient();
    }

    public async Task<T> GetAsync<T>(string url) where T : BaseDto
    {
        _httpClient.DefaultRequestHeaders.Clear();
        _httpClient.DefaultRequestHeaders.Add("User-Agent", "(thealmostengineer.com, tharam04@yahoo.com)");
        _httpClient.DefaultRequestHeaders.Add("Accept", "application/ld+json");

        Console.WriteLine("Getting requested data");

        HttpResponseMessage response = await _httpClient.GetAsync(url);
        // var response = await _httpClient.GetAsync(url);

        if (response.IsSuccessStatusCode == false)
        {
            throw new BadRequestException(response.StatusCode + " " + response.ReasonPhrase);
        }


        // T? result = System.Text.Json.JsonSerializer.Deserialize<T>(
        //     await response.Content.ReadAsStringAsync(),
        //     new JsonSerializerOptions
        //     { PropertyNameCaseInsensitive = true });

        T result = JsonConvert.DeserializeObject<T>(response.Content.ReadAsStringAsync().Result);

        // if (result == null)
        // {
        //     throw new JsonResultIsNullOrWhiteSpaceException();
        // }

        return result;
    }
}