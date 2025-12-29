function addTargetToExternalLinks() {
    document.querySelectorAll('a').forEach(link => {
        if (link.hostname !== window.location.hostname) {
            link.setAttribute('target', '_blank');
        }
    });
}
addTargetToExternalLinks();