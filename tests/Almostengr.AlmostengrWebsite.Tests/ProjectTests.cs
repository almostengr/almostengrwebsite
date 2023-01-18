using NUnit.Framework;
using OpenQA.Selenium;

namespace Almostengr.AlmostengrWebsite.Tests;

internal class ProjectsTests : BaseTest
{

    [Test]
    public void LoadHomePage_NavigateToProjectsClickThermometerPiLink()
    {
        driver.Navigate().GoToUrl(HomePageUrl);

        driver.FindElement(By.LinkText("Projects")).Click();

        driver.FindElement(By.PartialLinkText("Thermometer Pi")).Click();

        var source = driver.PageSource;

        Assert.IsTrue(source.Contains("DS18S20 Temperature Sensor"));
    }
}