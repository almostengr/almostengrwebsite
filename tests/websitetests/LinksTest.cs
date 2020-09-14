using NUnit.Framework;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;

namespace Almostengr.WebsiteTests
{
    [TestFixture]
    public class LinksTest
    {
        private IWebDriver _driver = null;

        [OneTimeSetUp]
        public void Setup()
        {
            _driver = new ChromeDriver();
        }

        [Test]
        public void NavigateUsesPage()
        {
            // arrange
            string websiteUrl = "http://192.168.57.117:8000/links";

            // act
            _driver.Navigate().GoToUrl(websiteUrl);

            // assert
            Assert.AreEqual(_driver.FindElement(By.TagName("h1")).Text, "Links for @almostengr");
        }

        [OneTimeTearDown]
        public void TearDown()
        {
            _driver.Quit();
        }
    }
}