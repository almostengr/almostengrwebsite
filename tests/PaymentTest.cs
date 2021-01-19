using NUnit.Framework;
using OpenQA.Selenium;

namespace Almostengr.WebsiteTests
{
    [TestFixture]
    public class PaymentTest : BaseTest
    {
        private IWebDriver _driver = null;

        [OneTimeSetUp]
        public void Setup()
        {
            _driver = StartBrowser();
        }

        [Test]
        public void CheckPayPal()
        {
            // arrange 

            // act
            _driver.Navigate().GoToUrl(WebsiteUrl);
            _driver.FindElement(By.LinkText("Make Payment")).Click();

            // assert
            Assert.True(_driver.PageSource.Contains("PayPal"));
            Assert.True(_driver.PageSource.Contains("CashApp"));
        }

        [OneTimeTearDown]
        public void TearDown()
        {
            _driver.Quit();
        }
    }
}