using NUnit.Framework;
using OpenQA.Selenium;

namespace Almostengr.WebsiteTests
{
    [TestFixture]
    public class RequestServicesTest : BaseTest
    {
        private IWebDriver _driver = null;

        [OneTimeSetUp]
        public void Setup()
        {
            _driver = StartBrowser();
        }

        [Test]
        public void ClickRequestService()
        {
            // arrange
            string placeholderPhone = "555-555-5555";
            string placeholderLastName = "Last Name";

            // act
            _driver.Navigate().GoToUrl(WebsiteUrl);
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