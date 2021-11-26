# Falcon Pi Twitter

![](/images/20201220presentation/twittertweets.jpg)

This project is designed for Falcon Pi Player to provide updates via Twitter on the light show that 
you are running. Those updates include posting the current song and providing alerts when problems
are detected.

This application is ONLY designed to run on Falcon Pi Players that are installed on Raspberry Pi, but it 
may be possible to run it on Beagle Bone Black (BBB).

## Problem

I wanted to have a way for the visitors to my light show are able to find out the information about the 
song that was currently playing.

Some other Light Show Creators use screens or equipment that will display the song information on a 
visitor's radio using RDS (Radio Data System). 

## Solution

I did not want to have to invest heavy into this project, so after I found out that Falcon Pi Player
came with an API, I decided to build a .NET Core application that would post the song information to Twitter. 
Then create a PSA (Public Service Announcement) in my show that lets visitors know about the Twitter page
and that song and show information is available on this page.

While most of the plugins for Falcon Pi Player are written in PHP or Shell (Bash) Script, this application 
is written in .NET Core 3.1. While I do know how to program in PHP and Bash, C# and .NET Core is what 
I primarily use. Thus using this language and framework for the application.

### Twitter Example

Follow my Light Show account [@hplightshow](https://twitter.com/hplightshow) to see what this 
application can do.


## System Requirements

In order to use Falcon Pi Twitter, you will need to have 

* an internet connection
* a <a href="https://developer.twitter.com" target="_blank">Twitter developer account</a>
* <a href="https://github.com/FalconChristmas/fpp" target="_blank">Falcon Pi Player</a> version 4 (confirmed working with version 4.6.1)

### Installation Steps

* Download the latest release from the <a href="https://github.com/almostengr/falconpitwitter" target="_blank">project repo</a>
that is available in zip or tar format.
* Copy the archive file to your Falcon Pi Player instance(s).
* Extract the archive file contents. Ideally extract them to a folder in the /home/fpp directory.
* Login to your <a href="https://developer.twitter.com" target="_blank">Twitter Developer Account</a>.
* Once your account is approved, create a project. 
Within that project, create Consumer Key (aka API Key), Consumer Secret (aka API Secret), Access Token and Access Secret.
Also within that project, update the App Permissions to "Read and Write". By default, permissions are "Read", 
which does not permit posting tweets.
* Copy [appsettings.template.json](#configuration) to [appsettings.json](#configuration).
* Add the key, secrets, and token that you got from your Twitter developer account to the appsettings.json file.
See the [Configuration](#configuration) section
for explainations and details.
* Create a [system service](#system-service) that will run the applicaton on startup.
* Reboot your Raspberry Pi
* Once the Pi has come back online, log in and check the log file to confirm that the monitor has started. 
You should see output similar to the below near the beginning of the log file.

```
Connected to Twitter as HP Light Show
```

The "Connected to Twitter" message in the log file, confirms that your account has been properly configured
to access Twitter. If there are exception messages in the log, double check the configuration file and your 
internet connection.

## System Service

This application is designed to be run as a system service. Below are the steps to install or 
remove it.

### Create System Service

To install the system service, run the below commands. Note that the commands are designed to be ran from 
the directory that you have copied the application files to.

```bash
sudo cp falconpitwitter.service /lib/systemd/system
sudo systemctl daemon-reload
sudo systemctl enable falconpitwitter
sudo systemctl start falconpitwitter
sudo systemctl status falconpitwitter
```

### Remove System Service

To uninstall the system service, run the below commands

```sh
sudo systemctl disable falconpitwitter
sudo systemctl stop falconpitwitter
sudo systemctl status falconpitwitter
sudo systemctl daemon-reload
sudo rm /lib/systemd/system/falconpitwitter.service
```

### System Service Logs

To see the output from the logs, visit the [Troubleshooting](#troubleshooting) section.

### CronJob

This application is designed to run as a system service. However, it can run as a cronjob. See the
[Creating System Service](#system-service) page for details.

Create a cronjob that runs on reboot. On your FPP, open a SSH session. Once logged in, enter

```sh
crontab -e
```

When the text editor opens, add the following to the bottom of the file. Change the directory to match 
where you extracted the FP Monitor.

```
@reboot /home/fpp/fpmonitor/falconpitwitter > /home/fpp/media/logs/falconpitwitter.log 2>&1
```

Then save and exit the text editor.

## Configuration

To get started, copy the ```appsettings.template.json``` file to a file named ```appsettings.json```.
Then update the JSON file to have the values that you would like. The details for each setting are
mentioned below.

### appsettings.json File Breakdown

The appsettings.json file has multiple configuration values in it. Each of the sections below describe
what values are expected in the file and how to configure them accordingly.

```json
"MonitorOnly": false,
```

* When set to ```false```, this will tweet out song information in addition to alerts.
* When set to ```true```, this will **only** tweet out alerts. (no song information)

When no value is provided, the application will default to ```false```.

```json
"Twitter": {
    "ConsumerKey": "8W4tZQ6xp7",
    "ConsumerSecret": "qJz6nDw2T7",
    "AccessToken": "KBiEB6jn28",
    "AccessSecret": "8nftJzHOAI",
},
```

This section holds the values to access the Twitter API. Visit the
[Twitter for Developers](https://developer.twitter.com) page to sign up and get the needed keys an tokens.
You will need to get a Consumer Key (aka API Key), Consumer Secret (aka API Secret), Access Token and Access Secret
for this section.

When no value is provided for any of the properties, the application will display and error and will not run.

```json
"FalconPiPlayerUrls": [
    "http://localhost"
],
```

List each of the Falcon Pi Players that you want to be monitored. If you are using a master-remote setup,
then the master instance, which has the music and sequence files, needs to be listed first. All remote
instances need to be listed after. The URLs can be the hostname or the IP address to each player.
If your FPP does not have an
assigned or static IP address, then it is recommended to use the hostname.

```json
"Alarm": {
    "TwitterAlarmUser": "@XrGOEz2Wc7",
    "MaxTemperature": 55.0,
    "MaxAlarms": 5
}
```

```TwitterAlarmUser``` should be the name of the Twitter account(s) that can be mentioned if
there is an issue with the show (e.g. Raspberry Pi having high CPU temperature). Value needs to include
the at (@) symbol.

When no value has been provided, then alerts will show up as public tweets instead of mentions.

```MaxTemperature``` should be the threshold that has to be reached before a high temperature alert is triggered.
In warmer climates, you will want to set this value higher to prevent false alerts.
This value needs to be in degrees Celsius. Per the Raspberry Pi documentation, 60 to 65
degrees Celsius is close to the safe upper operating limit of the Pi.

When no value has been provided, this will default to 55.0 degrees.

```MaxAlarms``` is the number alarms that you will be notified about within an hour. Once this threshold
has been reached, you will not be notified again until the next hour. The alarms will still be reported
in the application log. To receive infinite alerts, set this value to ```0```.

When no value has been provided, this will default to 5 alerts per hour.

### Example appsettings.json File

Once you have finished updating the appsettings.json file, it should look similar to the example below.

```json
{
    "Logging": {
        "LogLevel": {
            "Default": "Information",
            "Microsoft": "Warning",
            "Microsoft.Hosting.Lifetime": "Information"
        }
    },
    "AppSettings": {
        "MonitorOnly": false,
        "Twitter": {
            "ConsumerKey": "8W4tZQ6xp7",
            "ConsumerSecret": "qJz6nDw2T7",
            "AccessToken": "KBiEB6jn28",
            "AccessSecret": "8nftJzHOAI",
        },
        "FalconPiPlayerUrls": [
            "http://localhost"
        ],
        "Alarm": {
            "TwitterAlarmUser": "@XrGOEz2Wc7",
            "MaxTemperature": 55.0,
            "MaxAlarms": 5
        }
    }
}
```## Troubleshooting 

### Exception on First Run

An exception may occur and written in the log if the Wifi connection has not been established before the first run. 
Confirm in the log that ```HttpRequestException``` is not repeating in the logs after 2 or 3 attempts. If the 
message continues to appear, double check your Wifi or ethernet connection to the internet.

### System Service Output / Log

To see the logged output from the system service, login to FPP via SSH and run the command: 

```sh
journalctl -u falconpitwitter -b
```

If an error occurs in the application, the exception message will show here.

### Issue Queue

Additional bugs that you discover should be reported to the project
[Issues Queue](https://github.com/almostengr/falconpitwitter/issues).


## FAQs (Frequently Asked Questions)

### Tweeting Song Information

This application calls the Falcon Pi Player API to get the meta data for the song that is current playing. 
Then it uses that information to compose a tweet. If the song that is playing does not have ID3 tag 
information entered, then will not display part or all of the song data. If you need to add the song 
meta data to the file, you can use a program like [Audacity](https://www.audacityteam.org/) to do so.

### Tweeting Alarms (or Alerts)

The application calls the Falcon Pi Player API to get the current temperature of the Raspberry Pi. 
If it is above the threshold that is specified in the [appsettings.json](#configuration)
file, then it will send a tweet
that mentions the users specified in the [appsettings.json](#configuration)
file a message to let them know if the 
current temperature.

### How frequently are checks done? 

Songs are checked every 15 seconds to see if it has changed. If the same song is playing from the
previous check, then no tweet is posted. 

Vitals are checked every 5 minutes. Alarms are based on the settings that you have defined in the
[configuration file](#configuration).

### I don't want certain playlists to post song information. How do I accomplish this? 

Any playlist that has "offline" or "testing" (case insensitive) in the name of it, will not post 
the song information to 
Twitter. The vitals alarms can still be triggered when "offline" or "testing" playlists are active.

### Where is the source code?

Source code for this project is hosted on 
<a href="https://github.com/almostengr/falconpitwitter" target="_blank">Github</a>. The latest release
can also be downloaded from here.

### "Are you connected to internet? HttpRequest Exception occured" shows in the log. What does this mean? 

This means that your Falcon Pi Player instance attempted to connect to the internet or another device but 
was not able to do so. Double check your network and internet connection to ensure that data can be sent.
Also double check your configuration file as the hostname(s) may be incorrect or mistyped.

### Why did you build a standalone application instead of an FPP plugin?

I work as a software developer primarily building web-based applications in C#. 
Based on what I have seen, most (if not all) of the FPP plugins are build with PHP. While I do know PHP and
have worked with it in the past, I chose to go with building a C# application. 
as it gave me an opportunity to use my existing skills and 
expand them by applying them to something different than what I am used to.

### I have a question not answered. Where do I ask it?

Please file an [Issue on the repo](https://github.com/almostengr/falconpitwitter/issues)
with your comment, question, or bug report.
You may also reach out to the developer via Twitter [@almostengr](https://twitter.com/almostengr) or 
[@hplightshow](https://twitter.com/hplightshow).
