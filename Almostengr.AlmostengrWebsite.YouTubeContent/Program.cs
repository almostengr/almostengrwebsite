using System;
using System.Collections.Generic;
using System.IO;
using System.Net.Http;
using System.Threading.Tasks;
using Almostengr.AlmostengrWebsite.YouTubeContent.Models;
using static Almostengr.AlmostengrWebsite.Common.AeSelenium;
using static Almostengr.AlmostengrWebsite.Common.AeJson;
using OpenQA.Selenium;

namespace Almostengr.AlmostengrWebsite.YouTubeContent
{
    public class Program
    {
        static HttpClient _httpClient;
        public static async Task<int> Main(string[] args)
        {
            _httpClient = new HttpClient();

            try
            {
                const string latestVideos =
                    "https://feed2json.org/convert?url=https%3A%2F%2Fwww.youtube.com%2Ffeeds%2Fvideos.xml%3Fchannel_id%3DUC4HCouBLtXD1j1U_17aBqig";
                YtLatestVideoFeed latestVideoFeed = await GetRequestAsync<YtLatestVideoFeed>(latestVideos);

                Console.WriteLine($"Found {latestVideoFeed.Items.Count} video items");

                DateTime currentDate = DateTime.Now;

                foreach (YtVideo video in latestVideoFeed.Items)
                {
                    if (video.Date_Published.Date == currentDate.Date)
                    {
                        // video.Keywords = GetVideoKeywords(video.Url);
                        WriteVideoToBlog(video);
                        break;
                    }
                }

                return 0;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                return 1;
            }
        }

        private static string GetVideoKeywords(string webpageUrl)
        {
            string keywords = string.Empty;
            IWebDriver driver = null;

            try
            {
                driver = StartBrowser();
                driver.Navigate().GoToUrl(webpageUrl);
                keywords = driver.FindElement(By.Name("keywords")).Text;
                CloseBrowser(driver);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                CloseBrowser(driver);
            }

            return keywords;
        }

        private static void WriteVideoToBlog(YtVideo blogVideo)
        {
            Console.WriteLine("Creating blog post");

            List<string> textFile = new List<string>();
            textFile.Add("---");
            textFile.Add("title: " + blogVideo.Title.ToString());
            textFile.Add("posted: " + blogVideo.Date_Published.ToString("yyyy-MM-dd"));
            textFile.Add("author: Kenny Robinson");
            textFile.Add("youtube: " + blogVideo.Url);

            string category = DateTime.Now.DayOfWeek == DayOfWeek.Saturday ? "category: handyman" : "category: technology";
            Console.WriteLine(category);
            textFile.Add(category);

            textFile.Add("keywords: " + blogVideo.Keywords);

            textFile.Add("---");
            textFile.Add(string.Empty);
            textFile.Add("## Video");
            textFile.Add(string.Empty);
            textFile.Add($"<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/{blogVideo.VideoId}\" frameborder=\"0\" allow=\"autoplay; encrypted-media\" allowfullscreen class=\"youtube\"></iframe>");
            textFile.Add(string.Empty);

            string logPath = "../Almostengr.AlmostengrWebsite/drafts/";

            Console.WriteLine(logPath);

            try
            {
                string fileName = string.Concat(
                    blogVideo.Date_Published.ToString("yyyy.MM.dd"),
                    "-",
                    blogVideo.Title.ToLower().Replace(" ", "-").Replace(":", string.Empty),
                    ".md");

                FileStream logFile = File.Create(logPath + fileName);
                StreamWriter file = new StreamWriter(logFile);
                foreach (string line in textFile)
                {
                    file.WriteLine(line);
                }

                file.Close();
                file.Dispose();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.WriteLine("Done creating blog post");
        }
    }
}
