const bgDark = "bg-dark";
const bodyElement = document.getElementById("body");
const previousLink = document.getElementById("previousLink");
const nextLink = document.getElementById("nextLink");

function addSlideShowNavigation() {
    document.addEventListener("keyup", (event) => {
        switch (event.key) {
            case 'ArrowRight':
            case ' ':
            case 'PageDown':
            case 'Enter':
                goToNextSlide();
                break;

            case 'ArrowLeft':
            case 'PageUp':
                goToPreviousSlide();
                break;

            case 'b':
            case 'B':
                bodyElement.classList.toggle(bgDark);
                break;
        }
    });
}

function goToPreviousSlide() {
    if (previousLink !== null) {
        previousLink.click();
    }
}

function goToNextSlide() {
    if (nextLink !== null) {
        nextLink.click();
    }
}

function addTargetToExternalLinks() {
    document.querySelectorAll('a').forEach(link => {
        if (link.hostname !== window.location.hostname) {
            link.setAttribute('target', '_blank');
        }
    });
}

addSlideShowNavigation();
addTargetToExternalLinks();
