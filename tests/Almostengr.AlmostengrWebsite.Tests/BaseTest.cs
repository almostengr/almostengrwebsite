using NUnit.Framework;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;

namespace Almostengr.AlmostengrWebsite.Tests;

internal abstract class BaseTest
{
    internal readonly string HomePageUrl;
    internal readonly string ChromeDriverPath;

    internal IWebDriver? driver;

    protected BaseTest()
    {
        driver = null;

        if(IsReleaseConfiguration())
        {
            HomePageUrl = "https://thealmostengineer.com";
            ChromeDriverPath = string.Empty;
            return ;
        }

        HomePageUrl = "http://192.168.2.103:8000";
        ChromeDriverPath = "/home/almostengineer/Downloads/chromedriver_linux64";
    }

    private bool IsReleaseConfiguration()
    {
#if RELEASE
    return true;
#else
        return false;
#endif
    }

    [OneTimeSetUp]
    public void OneTimeSetUp()
    {
        driver = new ChromeDriver(ChromeDriverPath);
        driver.Manage().Window.Maximize();
    }

    [OneTimeTearDown]
    public void OneTimeTearDown()
    {
        if (driver != null)
        {
            driver.Quit();
        }
    }
}