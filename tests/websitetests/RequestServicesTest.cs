using NUnit.Framework;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;

namespace Almostengr.WebsiteTests
{
    [TestFixture]
    public class RequestServicesTest
    {
        private IWebDriver _driver = null;

        [OneTimeSetUp]
        public void Setup()
        {
            _driver = new ChromeDriver();
        }

        public void GoHome()
        {
            string websiteUrl = "http://192.168.57.117:8000/";
            _driver.Navigate().GoToUrl(websiteUrl);
        }

        [Test]
        public void ClickRequestService()
        {
            // arrange
            string placeholderPhone = "555-555-5555";
            string placeholderLastName = "Last Name";

            // act
            GoHome();
            _driver.FindElement(By.Id("requestservice")).Click();

            // assert
            Assert.IsTrue(_driver.PageSource.Contains(placeholderPhone));
            Assert.IsTrue(_driver.PageSource.Contains(placeholderLastName));
        }

        [OneTimeTearDown]
        public void Close()
        {
            _driver.Quit();
        }
    }
}