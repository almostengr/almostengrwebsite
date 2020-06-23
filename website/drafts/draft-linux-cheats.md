# Linux CheatSheet

Cheatsheet of commands to use when working on Linux-based systems. Here the 
commands that I use most frequently. 

I'm currently working on a YouTube tutorial series that will describe the 
commands listed and the multiple ways that they can be used. 

## Commands 

```bash 
ls -altr
```

### List directory contents in reverse order

```bash
ls -al | grep -i <searchString>
``` 

List the directory contents. Then search for the "searchString" in the 
output of the directory listing. 
NOTE: Depending on the system, the "searchString" may be highlighted 
in a different color when it is found.

### Email a file to a specified user

```bash
uuencode <filename> <filename> | mailx -s <subject> <to>
```

The "filename" does have to be typed twice. 
First time is the name of the file on the file system. The second time is what
you want the name of the attachment to be. "subject" is the subject of the 
email. "to" is who the email should be sent to.

### Remove old Linux kernels 

```bash
apt-get autoremove --purge $(dpkg --list | egrep -i --color 'linux-image|linux-headers' | grep -v $(uname -r)^C awk '/ii/{ print $2}') 
```