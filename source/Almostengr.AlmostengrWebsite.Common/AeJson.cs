using System;
using System.Net.Http;
using System.Threading.Tasks;
using Newtonsoft.Json;

namespace Almostengr.AlmostengrWebsite.Common
{
    public static class AeJson
    {
        static HttpClient _httpClient = new HttpClient();
        
        public static async Task<T> GetRequestAsync<T>(string url) where T : class
        {
            _httpClient.DefaultRequestHeaders.Clear();
            _httpClient.DefaultRequestHeaders.UserAgent.ParseAdd("(blog, tharam04@yahoo.com)");
            _httpClient.DefaultRequestHeaders.Accept.ParseAdd("applicatoin/ld+json");

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
}