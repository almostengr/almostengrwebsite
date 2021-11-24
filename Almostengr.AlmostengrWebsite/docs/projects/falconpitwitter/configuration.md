---
title: Configuration
---

To get started, copy the ```appsettings.template.json``` file to a file named ```appsettings.json```.
Then update the JSON file to have the values that you would like. The details for each setting are
mentioned below.

## appsettings.json File Breakdown

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

## Example appsettings.json File

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
```