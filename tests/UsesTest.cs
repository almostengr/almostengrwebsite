using NUnit.Framework;
using OpenQA.Selenium;

namespace Almostengr.WebsiteTests
{
    [TestFixture]
    public class UsesTest : BaseTest
    {
        private IWebDriver _driver = null;

        [OneTimeSetUp]
        public void Setup()
        {
            _driver = StartBrowser();
        }

        [Test]
        public void NavigateUsesPage()
        {
            _driver.Navigate().GoToUrl(WebsiteUrl);
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