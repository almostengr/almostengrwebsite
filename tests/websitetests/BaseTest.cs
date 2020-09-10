using System.IO;
using System.Reflection;
using NUnit.Framework;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;

namespace Almostengr.websitetests
{
    [TestFixture]
    public class BaseTest
    {

        private string homeUrl = "http://192.168.57.117:8000/";
        static IWebDriver _driver = null;
        private readonly string driverPath = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);

        [SetUp]
        public void Setup()
        {
            _driver = new ChromeDriver(driverPath);
        }

        public void GoHome()
        {
            _driver.Navigate().GoToUrl(homeUrl);
        }

        [TearDown]
        public void Close()
        {
            _driver.Quit();
        }
    }
}