# Initial Setup

## Install Raspbian

You will need to install Raspbian on your SD. Once you have completed this install,
Then you can insert the SD card into the Raspberry Pi and power it on.

To install Raspbian using Ubuntu, I made a video tutorial which you can watch
at [https://www.youtube.com/watch?v=Wy1_MWWlkNI](https://www.youtube.com/watch?v=Wy1_MWWlkNI).

## Pin Setup

Below is the mapping for the connections to the Raspberry Pi. The Pin numbers
listed are the physical pin numbers on the board, not the GPIO pin numbers. If
you are not using a relay board, the connections can be made directly to a
breadboard with LEDs connected.

Pi Pin (Board) | GPIO | Device Connection
-- |  | -
2 | -- | LCD Display VCC (+5V)
3 | -- | LCD Display SDA
4 | -- | Relay Board VCC (+5V)
5 | -- | LCD Display SLC
19 | 11 | Red Signal
21 | 9 | Yellow Signal
23 | 10 | Green Signal
30 | -- | LCD Display GND
34 | -- | Relay Board GND

Visual of Pin Connections to Relay Board

![Image of connections on Raspberry Pi board](/images/trafficpi/circuitry.jpg)

## System Service

To set up the application as a service, run the below commands. If you see error messages
when running the commands, you may need to run them with "sudo" privileges. See the
[System Service](/trafficpi/systemservice) page for details on how to add or remove the
application as a system service.

### Create System Service

```sh
sudo cp almostengrtrafficpiweb.service /lib/systemd/system
sudo systemctl daemon-reload
sudo systemctl enable almostengrtrafficpiweb.service
sudo systemctl start almostengrtrafficpiweb.service
sudo systemctl status almostengrtrafficpiweb.service
```

### System Service Output / Log

To see the logged output from the system service, run the command:

```sh
journalctl -u almostengrtrafficpiweb.service -b
```

or

```sh
journalctl -u almostengrtrafficpiweb.service -b -f
```

If an error occurs in the application, the exception message will show here.

## Run App On Pi

To run the applicatoin via the command line (not using the system service), then you
can run the commands below.

```sh
cd trafficpi
./Almostengr.TrafficPi.Web
```

To exit the application after running it via command line, press Ctrl+C.
