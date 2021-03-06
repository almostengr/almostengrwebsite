using NUnit.Framework;
using OpenQA.Selenium;

namespace Almostengr.WebsiteTests
{
    [TestFixture]
    public class BlogTest : BaseTest
    {
        private IWebDriver _driver = null;

        [OneTimeSetUp]
        public void Setup()
        {
            _driver = StartBrowser();
        }

        [Test]
        public void CheckTechnologyTab()
        {
            // arrange

            // act
            _driver.Navigate().GoToUrl(WebsiteUrl);
            _driver.FindElement(By.LinkText("BLOG")).Click();

            // assert
            Assert.True(_driver.PageSource.Contains("[2018-10-20] Upgrade Ubuntu 16.04 To 18.04"));
            Assert.True(_driver.PageSource.Contains("[2018-01-14] Farmos Nws 2.0"));
            Assert.False(_driver.PageSource.Contains("[2010-07-23] Every Developer Needs A Blog"));
        }

        [Test]
        public void ChangeToHandyManTab()
        {
            // arrange

            // act
            _driver.Navigate().GoToUrl(WebsiteUrl);
            _driver.FindElement(By.LinkText("BLOG")).Click();
            _driver.FindElement(By.LinkText("DIY/Handyman")).Click();

            // assert
            Assert.True(_driver.FindElement(By.TagName("h1")).Text.Contains("Blog"));
            Assert.True(_driver.PageSource.Contains("How To Replace Toilet Gasket And Bolts"));
            Assert.False(_driver.PageSource.Contains("Window Fan Installation With Downrod"));
        }

        [Test]
        public void ChangeToAllTab()
        {
            // arrange

            // act
            _driver.Navigate().GoToUrl(WebsiteUrl);
            _driver.FindElement(By.LinkText("BLOG")).Click();
            _driver.FindElement(By.LinkText("All")).Click();

            // assert
            Assert.True(_driver.FindElement(By.TagName("h1")).Text.Contains("Blog"));
            Assert.True(_driver.PageSource.Contains("How To Replace Toilet Gasket And Bolts"));
            Assert.True(_driver.PageSource.Contains("Ceiling Fan Installation With Downrod"));
            Assert.True(_driver.PageSource.Contains("[2019-02-27] Drupal 8 Tutorial Series"));
            Assert.True(_driver.PageSource.Contains("[2018-04-04] Install Plex On Ubuntu 16.04 Server Or Desktop"));
            Assert.True(_driver.PageSource.Contains("[2015-06-28] Search Engine Optimization"));
            Assert.True(_driver.PageSource.Contains("[2011-03-07] Free Software For Web Development"));
        }

        [Test]
        public void ChangeToYoutubeTab()
        {
            // arrange

            // act
            _driver.Navigate().GoToUrl(WebsiteUrl);
            _driver.FindElement(By.LinkText("BLOG")).Click();
            _driver.FindElement(By.LinkText("YouTube Videos")).Click();

            // assert
            Assert.True(_driver.FindElement(By.TagName("h1")).Text.Contains("Blog"));
            Assert.True(_driver.PageSource.Contains("[2020-08-11] Civicrm Configuration Checklist"));
            Assert.True(_driver.PageSource.Contains("[2018-10-20] Upgrade Ubuntu 16.04 To 18.04"));
            Assert.True(_driver.PageSource.Contains("[2018-08-14] Install Hdhrviewer Plug-In For Live Tv On Plex Media Server "));
        }

        [OneTimeTearDown]
        public void Close()
        {
            _driver.Quit();
        }
    }
}