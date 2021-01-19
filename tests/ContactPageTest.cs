using System;
using System.Threading;
using NUnit.Framework;
using OpenQA.Selenium;

namespace Almostengr.WebsiteTests
{
    [TestFixture]
    public class ContactPageTest : BaseTest
    {
        private IWebDriver _driver = null;

        [OneTimeSetUp]
        public void Setup()
        {
            _driver = StartBrowser();
        }

        [Test]
        public void LoadContactPage()
        {
            // arrange 

            // act 
            _driver.Navigate().GoToUrl(WebsiteUrl);
            _driver.FindElement(By.LinkText("CONTACT")).Click();

            // assert
            Assert.True(_driver.FindElement(By.TagName("h1")).Text.Equals("Contact"));
            Assert.True(_driver.FindElement(By.LinkText("@almostengr on Instagram")).GetAttribute("href").Equals("https://instagram.com/almostengr"));
            Assert.True(_driver.FindElement(By.LinkText("@almostengr on Twitter")).GetAttribute("href").Equals("https://twitter.com/almostengr"));
        }

        [Test]
        public void TestInstagram()
        {
            // arrange
            string igPageTitle = "Kenny Robinson (@almostengr) • Instagram photos and videos";

            // act
            _driver.SwitchTo().Window(_driver.WindowHandles[0]);
            _driver.Navigate().GoToUrl(WebsiteUrl);
            _driver.FindElement(By.LinkText("CONTACT")).Click();
            _driver.FindElement(By.PartialLinkText("on Instagram")).Click();
            _driver.SwitchTo().Window(_driver.WindowHandles[1]);

            // assert
            Assert.AreEqual(igPageTitle, _driver.Title);

            _driver.SwitchTo().Window(_driver.WindowHandles[1]).Close();
        }

        [Test]
        public void TestTwitterLink()
        {
            // arrange
            string twitterPageTitle = "Kenny Robinson (@almostengr) / Twitter";
            string linkText = "thealmostengineer.com/links";

            // act
            _driver.SwitchTo().Window(_driver.WindowHandles[0]);
            _driver.Navigate().GoToUrl(WebsiteUrl);
            _driver.FindElement(By.LinkText("CONTACT")).Click();
            _driver.FindElement(By.PartialLinkText("on Twitter")).Click();
            _driver.SwitchTo().Window(_driver.WindowHandles[1]);
    
            // loop to handle slash screen that may appear
            for (int i = 1; i < 5; i++){
                try{
                    _driver.FindElement(By.PartialLinkText(linkText));
                    break;
                } catch (Exception ex){
                    Console.WriteLine(ex.Message);
                    Thread.Sleep(TimeSpan.FromSeconds(1));
                }
            }

            // assert
            Assert.AreEqual(twitterPageTitle, _driver.Title);
            Assert.True(_driver.PageSource.Contains("thealmostengineer.com/links"));

            _driver.SwitchTo().Window(_driver.WindowHandles[1]).Close();
        }

        [Test]
        public void TestYoutubeLink()
        {
            // arrange
            string ytLinkText = "Tech and DIY Videos on YouTube";
            string ytPageTitle = "Kenny The Almost Engineer - YouTube";

            // act
            _driver.SwitchTo().Window(_driver.WindowHandles[0]);
            _driver.Navigate().GoToUrl(WebsiteUrl);
            _driver.FindElement(By.LinkText("CONTACT")).Click();
            _driver.FindElement(By.LinkText(ytLinkText)).Click();
            _driver.SwitchTo().Window(_driver.WindowHandles[1]);

            // assert
            Assert.AreEqual(ytPageTitle, _driver.Title);
        }

        [OneTimeTearDown]
        public void Close()
        {
            _driver.Quit();
        }
    }
}
