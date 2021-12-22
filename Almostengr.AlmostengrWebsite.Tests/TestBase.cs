using System;
using NUnit.Framework;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;

namespace Almostengr.AlmostengrWebsite.Tests
{
    public abstract class TestBase
    {
        internal const string WebsiteUrl = "https://thealmostengineer.com";
        internal string ChromeDriverPath = "";

        public IWebDriver StartBrowser()
        {
            try
            {
                ChromeOptions options = new ChromeOptions();

#if RELEASE
                options.AddArgument(Constants.HeadlessArgument);
#endif

                IWebDriver driver = new ChromeDriver(options);

                driver.Manage().Timeouts().ImplicitWait = TimeSpan.FromSeconds(15);
                driver.Manage().Window.Maximize();

                return driver;
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