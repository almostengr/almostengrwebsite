using System;
using NUnit.Framework;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;

namespace Almostengr.WebsiteTests
{
    public class BaseTest
    {
        private string[] cmdArgs;
        public string WebsiteUrl = "https://thealmostengineer.com";
        public string ChromeDriverPath = "";

        public TestContext TestContext;

        public IWebDriver StartBrowser()
        {
            // WebsiteUrl = TestContext.Parameters["websiteurl"];
            WebsiteUrl = Environment.GetEnvironmentVariable("AEWEBSITEURL");

            ChromeOptions options = new ChromeOptions();
            options.AddArgument("--headless");

            if (ChromeDriverPath != "")
                return new ChromeDriver(ChromeDriverPath);
            else
                return new ChromeDriver();
        }
    }
}