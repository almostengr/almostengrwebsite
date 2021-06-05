using System;
using NUnit.Framework;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;

namespace Almostengr.AlmostengrWebsite.Tests
{
    public abstract class TestBase
    {
        internal const string WebsiteUrl = "https://thealmostengineer.com";
<<<<<<< HEAD
        internal string ChromeDriverPath = "";
=======
        internal const string ChromeDriverPath = "";
>>>>>>> be4334262756e733e54dd3a5d76a4cd2b647fd9a

        public IWebDriver StartBrowser()
        {
            try
            {
                ChromeOptions options = new ChromeOptions();

#if RELEASE
                options.AddArgument("--headless");
<<<<<<< HEAD
                ChromeDriverPath = "/usr/local/share/chrome_driver"; // path for GH Actions on ubuntu 20.04
=======
>>>>>>> be4334262756e733e54dd3a5d76a4cd2b647fd9a
#endif

                if (ChromeDriverPath != "")
                {
                    return new ChromeDriver(ChromeDriverPath);
                }
                else
                {
                    return new ChromeDriver();
                }
            }
            catch (Exception ex)
            {
                Assert.Fail("Unable to start browser. {0}", ex.Message);
                return null;
            }
        }

        public void GoToHomePage(IWebDriver driver)
        {
            driver.Navigate().GoToUrl(WebsiteUrl);
        }

        public void CloseBrowser(IWebDriver driver)
        {
            if (driver != null)
            {
                driver.Close();
            }
        }
    }
}