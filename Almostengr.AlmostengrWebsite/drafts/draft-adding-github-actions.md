
# Adding GitHub Actions to Blog

## Background

As you may know, I use MkDocs to generate the static pages for my website. 
This means that the posts that I write are written in Markdown and then 
I have to run a couple of Python commands to convert those Markdown 
files to static HTML files. 

I decided to use GitHub pages to automation this portion of the publishing 
process. This will allow me to make updates to the website or publish 
new posts from anywhere that has an internet connection.

## CD (Continuous Deployment) Completed

Prior to setting up GitHub Actions, I had my Production environment 
already pulling the latest version of the gh-pages branch of my website 
repository. This automated pull is done via cronjob that runs every 
3 hours. 

## Setting Up GitHub Actions 

To get started with GitHub Actions, you can go to the repository that 
you have some tasks that you want to automate and click on the 
Actions tab on the page. 

If you do not have any actions set up for the repository, you will be 
presented with a list of defined workflows that you can immediately
use in your repository. Since there was not a workflow for MkDocs, 
I had to create my workflow from scratch.

In order to get my workflow going, I used a combination of looking 
at the workflows that others had created and the Github Actions 
documentation.

My workflow file to automatically generate the static files is broken
down as follows: 

### Name of the workflow 

```yaml
name: Generate static pages
```

### Trigger for the Workflow 

```yaml
on:
    push: 
        branches:
            - master

    pull_request:
        branches:
            - master
```

This defines the trigger for when the workflow should be started. 
In my case, I set it to trigger when a push is done or a pull request
is done on the master branch.

### Jobs and Build 

```yaml
jobs:
    build:
```

### Operating System

```yaml
name: buildout
    runs-on: ubuntu-latest
```

### Steps to Do

```yaml
steps:
- name: Checkout latest master
    uses: actions/checkout@v2
    with: 
        repository: almostengr/almostengrwebsite
```

### Commands

```yaml
- name: Installing Python
  run:  python -m pip install --upgrade pip
```

## Handling Errors

### mkdocs command not found

```bash
Run mkdocs gh-deploy
/home/runner/work/_temp/19138cfe-7455-4470-a2a3-bd90113d693e.sh: line 1: mkdocs: command not found
##[error]Process completed with exit code 127.
```

When attempting to run the command to deploy the MkDocs website, I would 
receive the above message. Looking on the MkDocs documentation, I 
found that it mentioned on Windows systems that "python -m" may need to
be used in order to execute a command. 

So if you receive the above error message, then change the command from 

```bash
mkdocs gh-deploy
```

to 

```bash
python -m mkdocs gh-deploy
```

in your workflow file.

### Not A Commit or A Branch

```bash
Run git checkout -b gh-pages origin/gh-pages
fatal: 'origin/gh-pages' is not a commit and a branch 'gh-pages' cannot be created from it
##[error]Process completed with exit code 128.
```

If you receive the above error, that means that the branch does not exist. 
When the repo is cloned, it only copies the master branch. If you want 
to have access to the other branches in the repository, then you will need ot 
perform a fetch and then checkout the branch of your choosing.

You can add a fetch to your workflow by adding the below command:

```yaml
- name: Fetching branches
  run:  git fetch -p
```

### gh-pages (or deployment) Branch Does Not Exist

```bash
WARNING -  Version check skipped: No version specificed in previous deployment. 
INFO    -  Copying '/home/runner/work/almostengrwebsite/almostengrwebsite/site' to 'gh-pages' branch and pushing to GitHub. 
ERROR   -  Failed to deploy to GitHub with error: 
To https://github.com/almostengr/almostengrwebsite
 ! [rejected]        gh-pages -> gh-pages (fetch first)
error: failed to push some refs to 'https://github.com/almostengr/almostengrwebsite'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally. This is usually caused by another repository pushing
hint: to the same ref. You may want to first integrate the remote changes
hint: (e.g., 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
 
##[error]Process completed with exit code 1.
```

If you receive the above error, it is because the mkdocs gh-deploy command 
is trying to build and push the code into the same branch, which it should not.

I added the following to my file, which resolved my issue.

```yaml
- name: Checking out gh-pages branch
  run:  git checkout -b gh-pages origin/gh-pages

- name: Checking out master branch
  run:  git checkout master
    
- name: Building static site
  run:  python -m mkdocs gh-deploy
```

## Conclusion 

Before setting up GitHub actions, I was only able to make updates when I 
was at home as I only have my Development server configured for MkDocs.

Even better is that this allows me to commit and publish from my phone.

You can view my 
[Actions file](https://github.com/almostengr/almostengrwebsite/blob/master/.github/workflows/generate-static-pages.yml)
in the website repository.
