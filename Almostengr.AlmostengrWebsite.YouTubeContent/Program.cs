using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Net.Http;
using System.Threading.Tasks;
using Almostengr.AlmostengrWebsite.YouTubeContent.Models;
using Newtonsoft.Json;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;

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
                YtLatestVideoFeed latestVideoFeed = await GetYtChannelFeed();

                Console.WriteLine($"Found {latestVideoFeed.Items.Count} video items");

                DateTime currentDate = DateTime.Now;

                foreach (YtVideo video in latestVideoFeed.Items)
                {
                    if (video.Date_Published.Date == currentDate.Date)
                    {
                        // video.Keywords = GetVideoKeywords(video.Url);
                        WriteVideoToBlog(video);
                        // StageAndCommitFiles();
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

        private static void StageAndCommitFiles()
        {
            Process process;

            List<string> commandsToRun = new List<string>();
            commandsToRun.Add("config user.name github-actions");
            commandsToRun.Add("config user.email github-actions@github.com");
            commandsToRun.Add("add .");
            commandsToRun.Add("commit -m \"AutocommitGH\"");
            commandsToRun.Add("push");

            foreach (string singleLine in commandsToRun)
            {
                process = new Process()
                {
                    StartInfo = new ProcessStartInfo()
                    {
                        FileName = "git",
                        Arguments = singleLine,
                        RedirectStandardError = true,
                        RedirectStandardOutput = true,
                        UseShellExecute = false,
                        CreateNoWindow = true,
                    }
                };

                Console.WriteLine("Running command: {0}", singleLine);

                process.Start();
                process.WaitForExit();

                Console.WriteLine(process.StandardError.ReadToEnd().ToString()); // print output from process
            }
        }

        private static string GetVideoKeywords(string webpageUrl)
        {
            string keywords = string.Empty;
            IWebDriver driver = null;

            try
            {
                ChromeOptions options = new ChromeOptions();

#if RELEASE
            options.AddArgument("--headless");
#endif

                driver = new ChromeDriver();
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

        private static void CloseBrowser(IWebDriver driver)
        {
            if (driver != null)
            {
                driver.Quit();
            }
        }

        private static void WriteVideoToBlog(YtVideo blogVideo)
        {
            Console.WriteLine("Creating blog post");

            const string TechBlogDirectory = "../Almostengr.AlmostengrWebsite/docs/technology/";
            const string HandyBlogDirectory = "../Almostengr.AlmostengrWebsite/docs/handyman/";

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

            string logPath = DateTime.Now.DayOfWeek == DayOfWeek.Saturday ? HandyBlogDirectory : TechBlogDirectory;

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
