function externalLinks() {
    var anchors = document.getElementsByTagName('a');
    for (var i = 0; i < anchors.length; i++) {
        if (anchors[i].getAttribute("href").startsWith("http") && 
            anchors[i].getAttribute("target").startsWith("_self") == false) {
            anchors[i].target = "_blank";
        }
    }
}

externalLinks();