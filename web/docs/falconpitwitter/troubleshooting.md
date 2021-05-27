---
title: Troubleshooting
---

## Exception on First Run

An exception may occur and written in the log if the Wifi connection has not been established before the first run. 
Confirm in the log that ```HttpRequestException``` is not repeating in the logs after 2 or 3 attempts. If the 
message continues to appear, double check your Wifi or ethernet connection.

## System Service Output / Log

To see the logged output from the system service, run the command: 

```sh
journalctl -u Almostengr.FalconPiTwitter -b
```

or

```sh
journalctl -u Almostengr.FalconPiTwitter -b -f
```

If an error occurs in the application, the exception message will show here.

## Issue Queue

Additional bugs that you discover should be reported to the project
[Issues Queue](https://github.com/almostengr/falconpitwitter/issues).
