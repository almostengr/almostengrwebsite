using System;
using NUnit.Framework;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;

namespace Almostengr.WebsiteTests
{
    [TestFixture]
    public class PaymentTest
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
        public void CheckPayPal()
        {
            // arrange 

            // act
            GoHome();
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