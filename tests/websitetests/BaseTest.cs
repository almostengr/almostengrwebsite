using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;

namespace Almostengr.WebsiteTests
{
    public class BaseTest
    {
       
        public string WebsiteUrl = "https://thealmostengineer.com";

        public IWebDriver StartBrowser(){
            return new ChromeDriver();
        }
    }
}