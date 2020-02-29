# Linux CheatSheet

Cheatsheet of commands to use when working on Linux-based systems. Here the commands that I use
most frequently.


I'm currently working on a YouTube tutorial series that will describe the commands listed and the 
multiple ways that they can be used.

Submissions or issues identified can be submitted via issue on this 
[project's repository](https://github.com/almostengr/almostengrwebsite/issues).

These commands have been tested and confirmed to work on Ubuntu-based systems. They also should, 
but are not guaranteed to work on Debian-based systems. For other Linux-bsed systems, these commands 
may work, but are not guaranteed to do so.

## Table of Contents

### File System Navigation

* [List All Files in Current Directory](#list-all-files-in-current-directory)
* [List All Files in Current Directory in Reverse Order](#list-all-files-in-current-directory-in-reverse-order)
* [List All Files In Current Directory and Filter with Grep](#list-all-files-in-current-directory-and-filter-with-grep)

### Sending Emails

* [Email A File To User](#email-a-file-to-user)

### System Maintenance

* [Remove Old Linux Kernels (Ubuntu and Debian Based Systems)](#remove-old-linux-kernels-ubuntu-and-debian-based-systems)

----

## File System Navigation

### List All Files in Current Directory

```bash
ls -al
```

### List All Files in Current Directory in Reverse Order

```bash
ls -altr
```

### List Files in Current Directory and Filter with Grep

```bash
ls -al | grep -i <searchString>
```

List the directory contents. Then search for the ```searchString``` in the output of the
directory listing. NOTE: Depending on the system, the ```searchString``` may be 
highlighted in a different color when it is found.

----

## Sending Emails

### Email A File To User

```bash
uuencode <filename> <filename> | mailx -s <subject> <to>
```

The ```<filename>``` does have to be typed twice. First time is the name of the file on the
file system. The second time is what you want the name of the attachment to be. 
```<subject>``` is the subject of the email. 
```<to>``` is who the email should be sent to.

----

## System Maintenance

### Remove Old Linux Kernels (Ubuntu and Debian Based Systems)

```bash
apt-get autoremove --purge $(dpkg --list | egrep -i --color 'linux-image|linux-headers' | grep -v $(uname -r)^C awk '/ii/{ print $2}') 
```
