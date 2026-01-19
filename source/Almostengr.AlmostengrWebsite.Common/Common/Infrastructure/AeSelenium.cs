using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;

namespace Almostengr.AlmostengrWebsite.Common.Common.Infrastructure;

public static class AeSelenium
{

    public static void CloseBrowser(IWebDriver driver)
    {
        if (driver != null)
        {
            driver.Quit();
        }
    }

    public static IWebDriver StartBrowser()
    {
        ChromeOptions options = new ChromeOptions();
        IWebDriver driver = null;

#if RELEASE
        options.AddArgument("--headless");
#endif

        driver = new ChromeDriver();

        return driver;
    }
}