---
title: Linux CheatSheet
updated: 2022-03-04
author: Kenny Robinson
---

Cheatsheet of commands to use when working on Linux-based systems. Here the commands that I use
most frequently.

Submissions or issues identified can be submitted via issue on this 
[project's repository](https://github.com/almostengr/almostengrwebsite/issues).

These commands have been tested and confirmed to work on Ubuntu-based systems. They also should, 
but are not guaranteed to work on Debian-based and Linux-based systems.

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

## Bash

### View Command Execution History

```bash
history
```

Output: 

```aeoutput
almostengineer@aeoffice$ history
2016  cd ../..
2017  mkdocs build 
2018  history | grep serve 
2019  mkdocs serve > /dev/null 2>&1 &  
2020  git status 
2021  history
```

The first column shows the command number and the second column will show the command that was run.

### Run Command From History

```bash
!<number>
```

Will run the command from your history as it was originally typed. You will need to replace 
```<number>``` with the number that shows in the output. For example, entering in ```!2020```
after running the ```history``` command above will give the below output.

Output: 

```aeoutput
almostengineer@aeoffice$ !2020
git status 
On branch master
Your branch is ahead of 'origin/master' by 2 commits.
  (use "git push" to publish your local commits)

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   docs/resources/linux-cheatsheet.md

no changes added to commit (use "git add" and/or "git commit -a")
```

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
