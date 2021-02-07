# Falcon Pi Monitor

![](/images/20201220presentation/twittertweets.jpg)

This project is designed for Falcon Pi Player to provide updates via Twitter on the light show that 
you are running. Those updates include posting the current song and providing alerts when problems
are detected.

This application is ONLY designed to run on Falcon Pi Players that are installed on Raspberry Pi.

## How Does It Work

### Tweeting Song Information

This application calls the Falcon Pi Player API to get the meta data for the song that is current playing. 
Then it uses that information to compose a tweet. If the song that is playing does not have ID3 tag 
information entered, then will not display part or all of the song data. If you need to add the song 
meta data to the file, you can use a program like Audacity to do so.

### Tweeting Temperature Alerts

The application calls the Falcon Pi Player API to get the current temperature of the Raspberry Pi. 
If it is above the threshold that is specified in the appsettings.json file, then it will send a tweet
that mentions the users specified in the appsettings.json file a message to let them know if the 
current temperature. When the temperature drops below the threshold, then another tweet is sent.

## Source Code

Source code for this project is hosted on 
<a href="https://github.com/almostengr/falconpimonitor" target="_blank">Github</a>.

## Installation Instructions

* Download the latest release that is available in zip or tar format.
* Copy the archive file to your Raspberry Pi.
* Extract the archive file contents. Ideally extract them to a folder in the /home/fpp directory.
* Create a [Twitter Developer account](https://developer.twitter.com/). 
* Once approved, create a project. 
Within that project, create Consumer Key (aka API Key), Consumer Secret (aka API Secret), Access Token and Access Secret.
Also within that project, update the App Permissions to "Read and Write". By default, permissions are "Read".
* Copy appsettings.template.json to appsettings.json.
* Add the key, secrets, and token that you got from your Twitter developer account to the appsettings.json file.
See [Example appsettings.json File](#example-appsettingsjson-file) and 
[About appsettings.json File](#about-appsettingsjson-file) for explainations and details.
* Create a cronjob that will run the automation on startup. See [Creating Cronjob](#creating-cronjob) for explaination.
* Reboot your Raspberry Pi
* Once the Pi has come back online, check the log file to confirm that the monitor has started. 
You should see output similar to the below at the beginning of the log file.
```
Starting service. Exit program by pressing Ctrl+C
Connected to Twitter as hpchristmas
```

The "Connected to Twitter" message in the log file, confirms that your account has been properly configured
and can post to Twitter.

### Creating Cronjob

Create a cronjob that runs on reboot. On your FPP, open a SSH session. Once logged in, enter

```sh
crontab -e
```

When the text editor opens, add the following to the bottom of the file. Change the directory to match 
where you extracted the FP Monitor.

```
@reboot /home/fpp/fpmonitor/falconpimonitor > /home/fpp/media/logs/falconpimonitor.log 2>&1
```

Then save and exit the text editor.

### Example appsettings.json File

Once you have added the Twitter key, token, and secrets to the appsettings.json file, it should look like 
the following: 

```json
{
    "Logging": {
        "LogLevel": {
            "Default": "Information",
            "Microsoft": "Warning",
            "Microsoft.Hosting.Lifetime": "Information"
        }
    },
    "TwitterSettings": {
        "ConsumerKey": "8W4tZQ6xp7",
        "ConsumerSecret": "qJz6nDw2T7",
        "AccessToken": "KBiEB6jn28",
        "AccessSecret": "8nftJzHOAI",
    },
    "AlarmSettings": {
        "TwitterUser": "@XrGOEz2Wc7",
        "TempThreshold": 55.0
    },
    "FppMonitorSettings":{
        "PostOffline": false,
        "RefreshInterval": 15
    },
    "FalconPiPlayerSettings":{
        "FalconUri": "http://falconpi/"
    }
}
```

### About appsettings.json File

* "TwitterUser" should be the name of the Twitter account that can be mentioned if 
there is an issue with the show (e.g. Raspberry Pi having high CPU temperature). Value needs to include 
the at (@) symbol.
* "FalconUri" should be the hostname or IP address to your Falcon Pi Player. If your FPP does not have an 
assigned or static IP address, then it is recommended to use the hostname.
* "TempThreshold" should be the threshold that has to be reached before a high temperature alert is triggered.
In warmer climates, you will want to set this value higher to prevent false alerts.
 This value needs to be in degrees Celsius. Per the Raspberry Pi documentation, 60 to 65
degrees Celsius is close to the safe upper operating limit of the Pi.

## Twitter Examples

Follow my Christmas Light Show account [@hpchristmas](https://twitter.com/hpchristmas) to see what this 
application can do.

## Known Bugs

### Exception on First Run

An exception will occur in the log if the Wifi connection has not been established before the first run. Confirm
in the log that HttpRequestException is not repeating in the logs after 2 or 3 attempts.

### Duplicate Log Entries

Log entries are duplicated after project refactoring. Issue #11 has been opened to track the work on 
this effort.

## Questions / Comments

Please file an Issue on the repo if you have questions, comments, or bug reports about this application.

You can also reach out to the developer via Twitter [@almostengr](https://twitter.com/almostengr).