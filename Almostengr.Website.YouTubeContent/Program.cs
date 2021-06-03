using System;
using System.Collections.Generic;
using System.IO;
using System.Net.Http;
using System.Threading.Tasks;
using Almostengr.Website.YouTubeContent.Models;
using Newtonsoft.Json;

namespace Almostengr.Website.YouTubeContent
{
    public class Program
    {
        static HttpClient _httpClient;
        public static async Task Main(string[] args)
        {
            _httpClient = new HttpClient();

            try
            {
                YtLatestVideoFeed latestVideoFeed = await GetYtChannelFeed();

                Console.WriteLine($"Found {latestVideoFeed.Items.Count} video items");

                DateTime currentDate = DateTime.Now;

                foreach (var video in latestVideoFeed.Items)
                {
                    if (video.Date_Published.Date == currentDate.Date)
                    {
                        await WriteVideoToBlog(video);
                        break;
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            await Task.CompletedTask;
        }

        private static async Task WriteVideoToBlog(YtVideo blogVideo)
        {
            Console.WriteLine("Creating blog post");

            const string TechBlogDirectory = "../web/docs/technology/";
            const string HandyBlogDirectory = "../web/docs/handyman/";

            List<string> textFile = new List<string>();
            textFile.Add("---");
            textFile.Add("title: " + blogVideo.Title.ToString());
            textFile.Add("posted: " + blogVideo.Date_Published.ToString("yyyy-MM-dd"));
            textFile.Add("author: Kenny Robinson");
            textFile.Add("youtube: " + blogVideo.Url);

            string category = DateTime.Now.DayOfWeek == DayOfWeek.Saturday ? "category: handyman" : "category: technology";
            Console.WriteLine(category);
            textFile.Add(category);

            textFile.Add("---");
            textFile.Add(string.Empty);
            textFile.Add("## Video");
            textFile.Add(string.Empty);
            textFile.Add($"<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/{blogVideo.VideoId}\" frameborder=\"0\" allow=\"autoplay; encrypted-media\" allowfullscreen class=\"youtube\"></iframe>");
            textFile.Add(string.Empty);

            var logPath = DateTime.Now.DayOfWeek == DayOfWeek.Saturday ? HandyBlogDirectory : TechBlogDirectory;

            Console.WriteLine(logPath);

            try
            {
                string fileName = string.Concat(
                    blogVideo.Date_Published.ToString("yyyy.MM.dd"),
                    "-",
                    blogVideo.Title.ToLower().Replace(" ", "-").Replace(":", string.Empty),
                    ".md");

                var logFile = File.Create(logPath + fileName);
                StreamWriter file = new StreamWriter(logFile);
                foreach (string line in textFile)
                {
                    await file.WriteLineAsync(line);
                }
                file.Close();

                await file.DisposeAsync();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.WriteLine("Done creating blog post");
        }

        private static async Task<YtLatestVideoFeed> GetYtChannelFeed()
        {
            try
            {
                Console.WriteLine("Getting latest feed");

                const string latestVideos =
                    "https://feed2json.org/convert?url=https%3A%2F%2Fwww.youtube.com%2Ffeeds%2Fvideos.xml%3Fchannel_id%3DUC4HCouBLtXD1j1U_17aBqig";
                HttpResponseMessage repsonse = await _httpClient.GetAsync(latestVideos);

                if (repsonse.IsSuccessStatusCode == false)
                {
                    Console.WriteLine(repsonse.StatusCode + " " + repsonse.ReasonPhrase);
                }

                YtLatestVideoFeed latestVideo =
                    JsonConvert.DeserializeObject<YtLatestVideoFeed>(repsonse.Content.ReadAsStringAsync().Result);
                return latestVideo;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                return null;
            }
        }

    }
}
