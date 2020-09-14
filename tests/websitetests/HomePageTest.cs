using System;
using NUnit.Framework;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;

namespace Almostengr.WebsiteTests
{
    [TestFixture]
    public class HomePageTest
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
        public void CheckCopyRight()
        {
            // arrange
            DateTime currentDate = DateTime.Now;

            // act
            GoHome();

            // assert
            Assert.True(_driver.PageSource.Contains(currentDate.Year.ToString()));
        }

        [Test]
        public void ReadMoreBlog()
        {
            // arrange

            // act
            GoHome();
            _driver.FindElement(By.Id("readmoreblog")).Click();

            // assert
            Assert.True(_driver.FindElement(By.TagName("h1")).Text.Equals("Blog"));
            Assert.True(_driver.FindElement(By.Id("content-area")).Text.Contains("blog post"));
        }

        [Test]
        public void ClickServices()
        {
            // arrange

            // act
            GoHome();
            _driver.FindElement(By.LinkText("SERVICES")).Click();

            // assert
            Assert.True(_driver.FindElement(By.TagName("h1")).Text.Equals("About / Services"));
            Assert.True(_driver.FindElement(By.Id("handyman-services-offered")).Text.Equals("Handyman Services Offered"));
            Assert.True(_driver.FindElement(By.Id("technology-services")).Text.Equals("Technology Services"));
        }

        [Test]
        public void ClickContact()
        {
            // arrange 

            // act 
            GoHome();
            _driver.FindElement(By.LinkText("CONTACT")).Click();

            // assert
            Assert.True(_driver.FindElement(By.TagName("h1")).Text.Equals("Contact"));
            Assert.True(_driver.FindElement(By.LinkText("@almostengr on Instagram")).GetAttribute("href").Equals("https://instagram.com/almostengr"));
            Assert.True(_driver.FindElement(By.LinkText("@almostengr on Twitter")).GetAttribute("href").Equals("https://twitter.com/almostengr"));
        }

        [OneTimeTearDown]
        public void Close()
        {
            _driver.Quit();
        }
    }
}
