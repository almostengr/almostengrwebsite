---
title: Creating Cronjob
description: Details on how to set up the application as a cronjob
---

This application is designed to run as a system service. However, it can run as a cronjob. See the
[Creating System Service](/falconpitwitter/systemservice) page for details.

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