using System;
using System.Net.Http;
using System.Threading.Tasks;
using Almostengr.AlmostengrWebsite.Common.Common.Infrastructure.Interfaces;
using Newtonsoft.Json;

namespace Almostengr.AlmostengrWebsite.Common.Common.Infrastructure;

public sealed class AeJson : IAeJson
{
    private readonly HttpClient _httpClient;

    public AeJson(
        HttpClient httpClient
    )
    {
        _httpClient = httpClient;
    }

    public async Task<T> GetRequestAsync<T>(string url) where T : class
    {
        _httpClient.DefaultRequestHeaders.Clear();
        _httpClient.DefaultRequestHeaders.UserAgent.ParseAdd("(blog, info@rhtservices.net)");
        _httpClient.DefaultRequestHeaders.Accept.ParseAdd("application/ld+json");

        try
        {
            Console.WriteLine("Getting requested data");

            HttpResponseMessage repsonse = await _httpClient.GetAsync(url);

            if (repsonse.IsSuccessStatusCode == false)
            {
                Console.WriteLine(repsonse.StatusCode + " " + repsonse.ReasonPhrase);
                return null;
            }

            T entity = JsonConvert.DeserializeObject<T>(repsonse.Content.ReadAsStringAsync().Result);
            return entity;
        }
        catch (Exception ex)
        {
            Console.WriteLine(ex.Message);
            return null;
        }
    }
}
