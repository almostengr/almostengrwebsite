using NUnit.Framework;
using OpenQA.Selenium;

namespace Almostengr.AlmostengrWebsite.Tests;

internal sealed class AboutPageTests : BaseTest
{
    [Test]
    public void LoadHomePage_NavigateToAboutPageAndFindElements()
    {
        // arrange, setup
        driver.Navigate().GoToUrl(HomePageUrl);

        // act
        driver.FindElement(By.LinkText("About")).Click();

        // assert, verify
        Assert.IsTrue(driver.PageSource.Contains("Blogs I Read"));
    }
}