#!/bin/bash

set -x

RSS_FILE="all.xml"
RSS_LATEST_FILE="latest.xml"

rm -f $RSS_FILE $RSS_LATEST_FILE

touch $RSS_FILE $RSS_LATEST_FILE

function writeFeedHeader() {
    echo "<rss version='2.0'>" >> $1
    echo "<channel>" >> $1
    echo "<title>The Blog of Kenny Robinson, The Almost Engineer</title>" >> $1
    echo "<link>http://www.thealmostengineer.com/</link>" >> $1
    echo "<description>Information about this blog and Kenny Robinson.</description>" >> $1
    echo "<language>en-us</language>" >> $1
    echo "<pubDate>$(date)</pubDate>" >> $1
    echo "<lastBuildDate>$(date)</lastBuildDate>" >> $1
    echo "<docs>https://www.rssboard.org/rss-specification</docs>" >> $1
    echo "<atom:link href='https://www.rssboard.org/files/sample-rss-2.xml' rel='self' type='application/rss+xml'/>" >> $1
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

    PAGE_PATH=$(echo $2 | sed "s/docs\/blog//g" | sed "s/.md//g" | xargs)
    echo "<link>https://thealmostengineer.com/blog${PAGE_PATH}</link>" >> $1

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

# write full file
writeFeedHeader $RSS_FILE

for blogPost in $(ls -r docs/blog/*.md)
do
    writeFeedItems "$RSS_FILE" "$blogPost"
done

writeFeedFooter $RSS_FILE

# write latest file
writeFeedHeader $RSS_LATEST_FILE

for blogPost in $(ls -r docs/blog/*.md | head -11)
do
    writeFeedItems "$RSS_LATEST_FILE" $blogPost
done

writeFeedFooter $RSS_LATEST_FILE
