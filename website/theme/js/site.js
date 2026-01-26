const dNone = "d-none";
const dataUrl = "data-url";
const titleElement = document.getElementById("slideTitle");
const bodyElement = document.getElementById("slideBody");
const previousLink = document.getElementById("previousLink");
const nextLink = document.getElementById("nextLink");

function addSlideShowNavigation() {
    if (bodyElement === null) {
        return;
    }

    titleElement.classList.add(dNone);
    bodyElement.classList.add(dNone);

    if (nextLink !== null) {
        nextLink.addEventListener("click", (event) => {
            event.preventDefault();
            goToNextSlide();
        });
    }

    if (previousLink !== null) {
        previousLink.addEventListener("click", (event) => {
            event.preventDefault();
            goToPreviousSlide();
        });
    }

    document.addEventListener("keyup", (event) => {
        if (event.key === 'ArrowRight') {
            goToNextSlide();
        }
        else if (event.key === 'ArrowLeft') {
            goToPreviousSlide();
        }
    });
}

function goToPreviousSlide() {
    if (bodyElement === null) {
        return;
    }
    else if (!bodyElement.classList.contains(dNone)) {
        bodyElement.classList.add(dNone);
    }
    else if (!titleElement.classList.contains(dNone)) {
        bodyElement.classList.add(dNone);
        titleElement.classList.add(dNone);
    }
    else if (previousLink !== null) {
        window.location.href = previousLink.getAttribute(dataUrl);
    }
}

function goToNextSlide() {
    if (bodyElement === null) {
        return;
    }
    else if (titleElement.classList.contains(dNone)) {
        titleElement.classList.remove(dNone);
    }
    else if (bodyElement.classList.contains(dNone)) {
        bodyElement.classList.remove(dNone);
        titleElement.classList.remove(dNone);
    } else if (nextLink !== null) {
        window.location.href = nextLink.getAttribute(dataUrl);
    }
}

function addTargetToExternalLinks() {
    document.querySelectorAll('a').forEach(link => {
        if (link.hostname !== window.location.hostname) {
            link.setAttribute('target', '_blank');
        }
    });
}

addTargetToExternalLinks();
addSlideShowNavigation();
