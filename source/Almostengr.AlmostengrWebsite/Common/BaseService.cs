namespace Almostengr.AlmostengrWebsite;

public abstract class BaseService
{
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
}