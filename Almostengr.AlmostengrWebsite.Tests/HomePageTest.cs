using System;
using NUnit.Framework;
using OpenQA.Selenium;

namespace Almostengr.AlmostengrWebsite.Tests
{
    [TestFixture]
    public class HomePageTest : TestBase
    {
        private IWebDriver _driver;

        [OneTimeSetUp]
        public void SetUp()
        {
            _driver = StartBrowser();
        }

        [Test]
        public void CheckCopyRight()
        {
            // arrange
            DateTime currentDate = DateTime.Now;

            // act
            GoToHomePage(_driver);

            // assert
            Assert.True(_driver.PageSource.Contains(currentDate.Year.ToString() + " " + "Kenny Robinson"));
        }

        [Test]
        public void CheckBuildDate()
        {
            DateTime currentDate = DateTime.Now.Date;

            GoToHomePage(_driver);

            Assert.True(_driver.PageSource.Contains("Build Date UTC : " + currentDate.ToString("yyyy-MM-dd")));
        }

        [OneTimeTearDown]
        public void TearDown()
        {
            CloseBrowser(_driver);
        }
    }
}