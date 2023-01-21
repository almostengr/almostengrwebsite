using System;
using NUnit.Framework;
using OpenQA.Selenium;

namespace Almostengr.AlmostengrWebsite.Tests;

internal class IndexTests : BaseTest
{
    [Test]
    public void LoadHomePage_NavigateToProjectPage()
    {
        // arrange (setup)

        // act (attempt)
        driver.Navigate().GoToUrl(HomePageUrl);
        driver.FindElement(By.LinkText("my projects")).Click();

        // assert (verify)
        var heading1 = driver.FindElement(By.TagName("h1")).Text;
        Assert.AreEqual("Projects", heading1);
    }

    [Test]
    public void LoadHomePage_NavigateToContactPage()
    {
        driver.Navigate().GoToUrl(HomePageUrl);
        driver.FindElement(By.LinkText("Contact")).Click();

        var heading1 = driver.FindElement(By.TagName("h1")).Text;
        Assert.AreEqual("Contact", heading1);
    }

    [Test]
    public void LoadHomePage_NavigateToLifestylePage()
    {
        driver.Navigate().GoToUrl(HomePageUrl);
        driver.FindElement(By.LinkText("Lifestyle")).Click();

        var heading1 = driver.FindElement(By.TagName("h1")).Text;
        Assert.AreEqual("Lifestyle", heading1);
    }

    [Test]
    public void LoadHomePage_NavigateToResourcesPage()
    {
        driver.Navigate().GoToUrl(HomePageUrl);
        driver.FindElement(By.LinkText("Resources")).Click();

        var heading1 = driver.FindElement(By.TagName("h1")).Text;
        Assert.AreEqual("Resources", heading1);
    }

    [Test]
    public void LoadHomePage_NavigateToServicesPage()
    {
        driver.Navigate().GoToUrl(HomePageUrl);
        driver.FindElement(By.LinkText("Services")).Click();

        var heading1 = driver.FindElement(By.TagName("h1")).Text;
        Assert.AreEqual("Services", heading1);
    }

    [Test]
    public void LoadHomePage_NavigateToTechnologyPage()
    {
        driver.Navigate().GoToUrl(HomePageUrl);
        driver.FindElement(By.LinkText("Technology")).Click();

        var heading1 = driver.FindElement(By.TagName("h1")).Text;
        Assert.AreEqual("Technology", heading1);
    }

    [Test]
    public void LoadHomePage_NavigateToUsesPage()
    {
        driver.Navigate().GoToUrl(HomePageUrl);
        driver.FindElement(By.LinkText("Uses")).Click();


        var heading1 = driver.FindElement(By.TagName("h1")).Text;
        Assert.AreEqual("Uses", heading1);

        var haHeading = driver.FindElement(By.Id("home-assistant")).Text;
        Assert.AreEqual("Home Assistant", haHeading);

        var techToolsHeading = driver.FindElement(By.Id("technology-tools")).Text;
        Assert.AreEqual("Technology Tools", techToolsHeading);
    }

    [Test]
    public void CopyrightYearsIncludeCurrentYear()
    {
        driver.Navigate().GoToUrl(HomePageUrl);
        var copyrightText = driver.FindElement(By.ClassName("md-footer-copyright__highlight")).Text;

        Assert.IsTrue(copyrightText.Contains("2010"));
        Assert.IsTrue(copyrightText.Contains(DateTime.Now.Year.ToString()));
    }

    [Test]
    public void CanReachRhtServicesWebsite()
    {
        driver.Navigate().GoToUrl(HomePageUrl);
        driver.FindElement(By.LinkText("Robinson Handy and Technology Services")).Click();
        driver.SwitchTo().Window(driver.WindowHandles[1]);
        
        string pageTitle = driver.Title;
        Assert.AreEqual(
            "Handyman and Technology Services serving Montgomery, Prattville, Wetumpka, and Millbrook | Robinson Handy and Technology Services LLC",
            pageTitle);
    }
}