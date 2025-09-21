#!/bin/bash

# set -x

RSS_FILE="rss.xml"

rm -r $RSS_FILE

touch $RSS_FILE

echo "<rss version='2.0'>" >> $RSS_FILE
echo "<channel>" >> $RSS_FILE
echo "<title>The Blog of Kenny Robinson, The Almost Engineer</title>" >> $RSS_FILE
echo "<link>http://www.thealmostengineer.com/</link>" >> $RSS_FILE
echo "<description>Information about this blog and Kenny Robinson.</description>" >> $RSS_FILE
echo "<language>en-us</language>" >> $RSS_FILE
echo "<pubDate>$(date)</pubDate>" >> $RSS_FILE
echo "<lastBuildDate>$(date)</lastBuildDate>" >> $RSS_FILE
echo "<docs>https://www.rssboard.org/rss-specification</docs>" >> $RSS_FILE
echo "<!-- <generator>Blosxom 2.1.2</generator>" >> $RSS_FILE
echo "<managingEditor>neil.armstrong@example.com (Neil Armstrong)</managingEditor>" >> $RSS_FILE
echo "<webMaster>sally.ride@example.com (Sally Ride)</webMaster> -->" >> $RSS_FILE
echo "<atom:link href='https://www.rssboard.org/files/sample-rss-2.xml' rel='self' type='application/rss+xml'/>" >> $RSS_FILE

for blogPost in $(ls -r docs/blog/*.md)
do
    echo "<item>" >> $RSS_FILE

    TITLE=$(grep -h "title:" "$blogPost" | sed "s/title: //g")
    echo "<title>${TITLE}</title>" >> $RSS_FILE

    PAGE_PATH=$(echo $blogPost | sed "s/docs\/blog//g" | sed "s/.md//g" )
    echo "<link>https://thealmostengineer.com/blog${PAGE_PATH}</link>" >> $RSS_FILE

    PUBLISH_DATE=$(grep -h "posted:" "$blogPost" | sed "s/posted: //g")
    if [ "$PUBLISH_DATE" != "" ]; then
        echo "<pubDate>${PUBLISH_DATE}</pubDate>" >> $RSS_FILE
    fi

    DESCRIPTION=$(grep -h "description:" "$blogPost" | sed "s/description: //g")
    if [ "$DESCRIPTION" != "" ]; then
        echo "<description>${DESCRIPTION}</description>" >> $RSS_FILE
    fi

    echo "</item>" >> $RSS_FILE
done

echo "</channel>" >> $RSS_FILE
echo "</rss>" >> $RSS_FILE
