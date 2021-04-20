---
title: Getting Started
---

## System Requirements

In order to use Falcon Pi Twitter, you will need to have 

* an internet connection
* a Twitter developer account
* Falcon Pi Player version 4 (confirmed working with version 4.6.1)

## Installation Steps

* Download the latest release from the [project repo](https://github.com/almostengr/falconpitwitter) 
that is available in zip or tar format.
* Copy the archive file to your Falcon Pi Player instance(s).
* Extract the archive file contents. Ideally extract them to a folder in the /home/fpp directory.
* Login to your [Twitter Developer account](https://developer.twitter.com/).
* Once your account is approved, create a project. 
Within that project, create Consumer Key (aka API Key), Consumer Secret (aka API Secret), Access Token and Access Secret.
Also within that project, update the App Permissions to "Read and Write". By default, permissions are "Read", 
which does not permit posting tweets.
* Copy [appsettings.template.json](falconpitwitter/configuration) to [appsettings.json](/falconpitwitter/configuration).
* Add the key, secrets, and token that you got from your Twitter developer account to the appsettings.json file.
See the [Configuration](/falconpitwitter/configuration#example-appsettingsjson-file) page 
for explainations and details.
* Create a [system service](/falconpitwitter/systemservice) that will run the applicaton on startup. 
    * NOTE: If you do not want to create a system service, then you can create cronjob that will run the automation on startup. See [Creating Cronjob](/falconpitwitter/cronjob) for explaination.
* Reboot your Raspberry Pi
* Once the Pi has come back online, log in and check the log file to confirm that the monitor has started. 
You should see output similar to the below near the beginning of the log file.

```
Connected to Twitter as hplightshow
```

The "Connected to Twitter" message in the log file, confirms that your account has been properly configured
to access Twitter. If there are exception messages in the log, double check the configuration file and your 
internet connection.

