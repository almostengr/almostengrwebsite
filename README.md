# thealmostengineer.com

## Description

Code for one of my websites, [thealmostengineer.com](https://thealmostengineer.com).

In the past, this website was ran on Drupal 7 and Wordpress. To get rid of the overhead of
having to keep up with the maintenance of a Content Management System (CMS), 
I have since converted it to a static website that is generated with MKDocs. Static websites have less 
maintenance overhead and are easier to update when using a static site generator (SSG).

You may read up on why I swtiched my blog from Drupal to MkDocs in my
[blog post](https://thealmostengineer.com/blog/2019.12.21-switched-blog-from-drupal-to-mkdocs/).

To find out the full information about the technology used on my website, you can visit the
[uses page](https://thealmostengineer.com/uses).

## Branches

### main (default)

Source of the Markdown website. This includes the custom theme, based on Bootstrap 4, to convert the 
Markdown files to static HTML content.

### website

The generated HTML code from the Markdown files in main branch. This branch is built by GitHub Actions.

## Resources

Below are some of the content that I referenced when building the technical aspects of this website

* [.htaccess files](https://perishablepress.com/stupid-htaccess-tricks/#gen3)
* [Jinja Template Language](https://jinja.palletsprojects.com/en/2.11.x/)
* [MkDocs](https://www.mkdocs.org/)
