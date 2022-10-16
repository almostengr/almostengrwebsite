---
title: Git Cheatsheet
updated: 2022-03-04
author: Kenny Robinson
description: A list of the most common commands to use with Git and explaination of each.
---

# Git Cheat Sheet

Cheatsheet of commands to use when working with git. This is a quick reference for the commands that 
are most commonly used when working with Git.

A description of what each command does if executed, is provided under each [command](#commands). 
Definitions of common terms are [located below](#definitions)

## Commands

```bash
git init
```
Creates a new repository in the current directory. 

---

```bash
git branch
```
Lists all of the branches that are in the current branch. 

---

```bash
git add .
```
Stages all of the files (both untracked and tracked) for commit in the current and subirectories.

---

```bash
git add -u
```
Stages all of the previously commited files in the current and subdirectories.

---

```bash
git commit -m "MESSAGE"
```
Commits (saves) the changes made to files, removal of files from the repo, and addition of files to the repo. 
```MESSAGE``` should be replaced with a details of the changes made since the last commit.

---

```bash
git clone REPOURL
```
Makes a copy of the repository from Github to your local computer. This allows for changes to be made 
from your local computer. ```REPOURL``` should be replaced with the URL from the remote repository.

---

```bash
git status
```
Shows the current branch, files that have added but not committed, files that have been removed but not 
committed, files that have not been staged for committing. 

---

```bash
git rm FILENAME
```
Removes files from the repository. If removing directories, "-r" option needs to be used. Replace 
```FILENAME``` with the name of the actual file(s). 

---

```bash
git diff --cached COMMITHASH
```
Shows the changes that have been made between a previous commit and the files pending commitment. 
If no files have been staged for commit, then this command will not return any output.  
```COMMITHASH``` should be replaced with the unique identifer of a previous commit.

---

```bash
git diff --cached $(git log | head -1 | awk '{print $2}')
```
Performs the same command above, but automatically gets the latest commit from the ```git log``` 
command.

---

```bash
git diff $(git log | head -1 | awk '{print $2}') $(git log | head -7 | tail -1 | awk '{print $2}')
```
Shows the changes between the latest commit and the previous commit by pulling the commit hash from 
```git log``` command.  This command will only work on Unix or Linux based systems.

---

```bash
git log
```
Shows the commit history. This include the commit message, date, time, author, and commit ID (or hash). 

---

```bash
git clean
```
Removes files that are not being tracked.

---

```bash
git push origin BRANCH
```
Pushes files from the origin branch to the git server that hosts the repository.  ```BRANCH``` should 
be replaced with the name of the branch, although it does not have to be specified. if ```BRANCH``` is 
not entered, then the current branch will be pushed.

---

```bash
git pull origin BRANCH
```
Pulls the latest version of the branch from your git server. ```BRANCH``` should be replaced with the 
name of the branch, although it does not have to be specified.

---

```bash
git ls-files --deleted -z | xargs -0 git rm
```
Deletes the local files that have already been removed from the git repo.

---

```bash
git branch | grep -v master | xargs git branch -D 
```

Deletes all of the local branches except master. Useful for when multiple remote branches have been removed 
and you need to remove the local corresponding branches.

---

## Definitions

### branch

A version of code in the repository. Changes to the code are normally done in another branch and then 
merged into the master branch of the repository.

### clone 

To make a copy of the repository from the central repository (server) to the local machine.

### commit

A commit is a revision (create, update, or delete), made to one or more files. This is the equivalent
of taking a snapshot of the files that have changed since the previous snapshot that was taken.

### fetch

To get the latest versions of all the branches and update local references of those branches.

### fork

Makes a copy of repo that is owned by somebody else and allows you to make changes to the code without 
making changes to the original repo.

### issue

Issues are used to track bugs, features or enhancements for a project. In some systems, this is 
referred to as a "ticket" or "change request".

### merge

Combines changes from two branches into a single branch.

### pull 

To get the latest code from the central repository (server) to your local machine.

### push

To send the code from your local machine to the central repository (server).
