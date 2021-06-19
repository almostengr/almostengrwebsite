---
title: Troubleshooting
---

## Exception on First Run

An exception may occur and written in the log if the Wifi connection has not been established before the first run. 
Confirm in the log that ```HttpRequestException``` is not repeating in the logs after 2 or 3 attempts. If the 
message continues to appear, double check your Wifi or ethernet connection to the internet.

## System Service Output / Log

To see the logged output from the system service, login to FPP via SSH and run the command: 

```sh
journalctl -u falconpitwitter -b
```

If an error occurs in the application, the exception message will show here.

## Issue Queue

Additional bugs that you discover should be reported to the project
[Issues Queue](https://github.com/almostengr/falconpitwitter/issues).
