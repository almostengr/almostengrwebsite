#!/bin/bash

# set -x

RSS_FILE="all.xml"
RSS_LATEST_FILE="latest.xml"
DADLIFE_FILE="dadlife.rss.xml"
EMBEDDED_FILE="embedded.rss.xml"
JUNKDRAWER_FILE="junkdrawer.rss.xml"
TECH_FILE="tech.rss.xml"
WEBDEV_FILE="webdevelopment.rss.xml"

rm -f $RSS_FILE $RSS_LATEST_FILE
rm -f $DADLIFE_FILE $EMBEDDED_FILE $JUNKDRAWER_FILE $TECH_FILE $WEBDEV_FILE

touch $DADLIFE_FILE $EMBEDDED_FILE $JUNKDRAWER_FILE $TECH_FILE $WEBDEV_FILE

function writeFeedHeader() {
    TITLE=""
    DESCRIPTION=""
    case $2 in
        "dadlife")
            TITLE="Dad Life Feed | The Almost Engineer"        
            ;;

        "embedded-systems")
            TITLE="Embedded Systems Feed | The Almost Engineer"
            ;;

        "junkdrawer")
            TITLE="Junk Drawer and Randomness Feed | The Almost Engineer"
            ;;

        "tech-workbench")
            TITLE="Tech Workbench Feed | The Almost Engineer"
            ;;

        "web-development")
            TITLE="Web Development Feed | The Almost Engineer"
            ;;

        *)
            echo "Invalid header parameter"
            exit 45
            ;;
    esac

    echo "<rss version='2.0'>" >> $1
    echo "<channel>" >> $1
    echo "<title>${TITLE}</title>" >> $1
    echo "<link>http://www.thealmostengineer.com/</link>" >> $1

    if [ "${DESCRIPTION}" == "" ]; then
        echo "<description>Latest posts from The Almost Engineer, Kenny Robinson.</description>" >> $1
    else
        echo "<description>${DESCRIPTION}</description>" >> $1
    fi

    echo "<language>en-us</language>" >> $1
    echo "<copyright>The Almost Engineer</copyright>" >> $1
    echo "<generator>The Almost Engineer Bash Script</generator>" >> $1
    echo "<pubDate>$(date)</pubDate>" >> $1
    echo "<lastBuildDate>$(date)</lastBuildDate>" >> $1
    echo "<docs>https://www.rssboard.org/rss-specification</docs>" >> $1
}

function writeFeedFooter() {
    echo "</channel>" >> $1
    echo "</rss>" >> $1
}

function writeFeedItems() {
    echo "<item>" >> $1

    fileName=$2

    TITLE=$(grep "^title:" "$fileName" | sed 's/^title: //' | xargs)
    echo "<title>${TITLE}</title>" >> $1

    PAGE_PATH=$(echo $2 | sed "s/website\/docs\/${3}//g" | sed "s/.md//g" | xargs)
    echo "<link>https://thealmostengineer.com/${3}${PAGE_PATH}</link>" >> $1

    PUBLISH_DATE=$(grep "^posted:" "$fileName" | sed 's/^posted: //' | xargs)
    if [ "$PUBLISH_DATE" != "" ]; then
        echo "<pubDate>${PUBLISH_DATE}</pubDate>" >> $1
    fi

    DESCRIPTION=$(grep "^description:" "$fileName" | sed 's/^description: //' | xargs)
    if [ "$DESCRIPTION" != "" ]; then
        echo "<description>${DESCRIPTION}</description>" >> $1
    fi

    echo "</item>" >> $1
}


writeFeedHeader $DADLIFE_FILE "dadlife"
for blogPost in $(ls -r website/docs/dadlife/*.md | head -11)
do
    writeFeedItems "$DADLIFE_FILE" $blogPost "dadlife"
done
writeFeedFooter $DADLIFE_FILE


writeFeedHeader $EMBEDDED_FILE "embedded-systems"
for blogPost in $(ls -r website/docs/embedded-systems/*.md | head -11)
do
    writeFeedItems "$EMBEDDED_FILE" $blogPost "embedded-systems"
done
writeFeedFooter $EMBEDDED_FILE


writeFeedHeader $JUNKDRAWER_FILE "junkdrawer"
for blogPost in $(ls -r website/docs/junkdrawer/*.md | head -11)
do
    writeFeedItems "$JUNKDRAWER_FILE" $blogPost "junkdrawer"
done
writeFeedFooter $JUNKDRAWER_FILE


writeFeedHeader $TECH_FILE "tech-workbench"
for blogPost in $(ls -r website/docs/tech-workbench/*.md | head -11)
do
    writeFeedItems "$TECH_FILE" $blogPost "tech-workbench"
done
writeFeedFooter $TECH_FILE


writeFeedHeader $WEBDEV_FILE "web-development"
for blogPost in $(ls -r website/docs/web-development/*.md | head -11)
do
    writeFeedItems "$WEBDEV_FILE" $blogPost "web-development"
done
writeFeedFooter $WEBDEV_FILE
