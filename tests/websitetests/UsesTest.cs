using NUnit.Framework;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;

namespace Almostengr.WebsiteTests
{
    [TestFixture]
    public class UsesTest
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
        public void NavigateUsesPage()
        {
            GoHome();
            _driver.FindElement(By.LinkText("Uses")).Click();

            Assert.AreEqual(_driver.FindElement(By.Id("handyman-tools")).Text, "Handyman Tools");
            Assert.AreEqual(_driver.FindElement(By.Id("technology-tools")).Text, "Technology Tools");
            Assert.AreEqual(_driver.FindElement(By.Id("other-uses-pages")).Text, "Other Uses Pages");
        }

        [OneTimeTearDown]
        public void TearDown()
        {
            _driver.Quit();
        }
    }
}