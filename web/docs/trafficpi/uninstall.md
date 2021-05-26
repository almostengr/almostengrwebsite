# Uninstall Traffic Pi

## Remove System Service

To remove the application as a system service, run each of the commands below.

```sh
sudo systemctl disable almostengrtrafficpiweb.service
sudo systemctl stop almostengrtrafficpiweb.service
sudo systemctl status almostengrtrafficpiweb.service
sudo rm /lib/systemd/system/almostengrtrafficpiweb.service
```

After running all of the commands above, then reboot the system.

## Application Files

To remove the application files, you can remove the entire trafficpi directory.

```sh
rm -rf trafficpi
```