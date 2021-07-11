using NUnit.Framework;
using OpenQA.Selenium;

namespace Almostengr.AlmostengrWebsite.Tests
{
    public class ProjectsPageTest : TestBase
    {
        private IWebDriver _driver;

        [OneTimeSetUp]
        public void SetUp()
        {
            _driver = StartBrowser();
        }

        [Test]
        public void ShowProjects()
        {
            GoToHomePage(_driver);
            
            _driver.FindElement(By.ClassName("navbar-toggler")).Click();

            _driver.FindElement(By.LinkText("PROJECTS")).Click();

            IWebElement pageHeading = _driver.FindElement(By.TagName("h1"));

            Assert.True(pageHeading.Text.Equals("Projects"));
        }

        [Test]
        public void CheckProjectList()
        {
            GoToHomePage(_driver);

            _driver.FindElement(By.ClassName("navbar-toggler")).Click();
            
            _driver.FindElement(By.LinkText("PROJECTS")).Click();

            Assert.True(_driver.PageSource.Contains("Coding Challenges"));
        }

        [OneTimeTearDown]
        public void TearDown()
        {
            CloseBrowser(_driver);
        }
    }
}