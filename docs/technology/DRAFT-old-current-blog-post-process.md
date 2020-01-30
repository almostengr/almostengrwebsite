
## Old Process with Drupal

### Login to Drupal 

Had to login to Drupal each time that I wanted to make an update to my blog. 
This mean that I was less likely to make that update over public wifi, because 
public wifi means that your site could be a greater risk for being hacked.

### Ignore that Message About Security Updates Available 

Now I did not always ignore this message, but majority of the time I did. 
Why? Because when the thought of a new content came to mind, I wanted to get 
as much of the thought out of my head and onto digital paper as possible. 
Fooling around and trying to get those updates installed before getting the 
thoughts out meant that I would risk loosing the thought, thus no new content.

### Write The Content... In A Word Processor

I know it does not make sense, but let me explain. While some browsers do have 
spell check, I have not ran across one that has grammar check. That said, 
I know that I make mistakes typing and have to go back and correct those mistakes. 
However, I would rather to get it right the first time than to have to correct 
it in a future update or somebody telling me about my mistake. 

### Move the Content to the Website

Once I have done all the grammar and spell checking in the word processor, 
I would then copy and paste that content into the website and preview it. 
With previewing, it would allow me to see that the content was formatted 
correctly before publishing. Once I would confirm that all was well, 
then I would publish the content. 

### Take a Backup

Since things could go wrong with Drupal when performing the database updates, 
per the Drupal documentation, it was recommended that you always backed up
the database before running the database updates function. 

I have had a few sites go wrong when performing the database updates and it was 
not easy getting them back online since I did not have recent backups. 

In some of the modules, the maintainers were not using database transactions
in their update functions. So if part of the update ran and failed, you would have 
a partial-ran database update but Drupal would see it as if the full update 
had completed successfully. Problem with Drupal seeing it as the full update 
running, is that it would not let you re-run that specific update again.
So that meant that you had to either tinker in the database and manually update 
the version number to the previous version so that the database update could be 
ran again or restore the database with the backup and run the update again. 
Either of those options were not ideal and defintely were time consuming.

### Those Security Updates 

If I was using the right computer, I would then download the available security
updates into my development computer. Confirmed that nothing blew up in the process
with Drupal's database updater. 
Then commit those updates to my website's version control.
Then pull the latest 
version into my production environment and run Drupal's database updater
and prayed the entire time that things would work as they should. 

## New Process with MkDocs 

### Fetch Latest Repo 

On any computer of my choosing that has git installed, 
I can get the latest the latest version of Markdown 
code of my website and make updates to it. 

### Edit in Text Editor or Word Processor 

Since the content that I am going to edit is already on the computer, I do 
not have to do anything special to get them into a word processor for editing. It 
is just as simple as File > Open > select the file > start typing.

### Save and Commit 

Once I have made all of the edits that need to be made, I can save my changes in the 
word processor and then commit them to my version control. Then push that branch 
up to the origin.

### Generate Static Files and Deploy 

I have my development environment set up with MkDocs. So I login to that server and 
run the ``` git pull ``` command followed by ``` mkdocs gh-deploy ``` command. 
The static HTML, CSS, and JS files are generated and committed to a local branch and
then I am prompted to enter by Github credentials. 

### Automated Pull in Production 

My production instance has a cronjob set up that does a pull of the branch that 
contains the static website. It does this pull several times per day. In a sense, it 
it like having a CD (continuous deployment) set up in that environment. 

## Future Considerations 

### Expanded CI-CD Setup 

One of the future goals that I have is to expand my current deployment set up 
so that it will periodically pull the master branch and automatically 
run the gh-deploy command on it. 

I looked into having all of this done in my 
production environment, but my website host provider will not allow me 
to install Python packages on their shared server. Thus will have to continue 
to generate the static website files locally. 


