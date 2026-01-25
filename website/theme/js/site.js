const dNone = "d-none";
const dataUrl = "data-url";
const headingElement = document.querySelector("h1").closest("div");
const subHeadingElements = document.querySelectorAll("h2, h3, h4, pre");
const slideElement = document.getElementById("slideshow");

function addSlideShowNavigation() {
    if (slideElement === null) {
        return;
    }

    headingElement.classList.add(dNone);
    subHeadingElements.forEach(heading => {
        heading.classList.add(dNone);
    });

    const nextLink = document.getElementById("nextLink");
    const previousLink = document.getElementById("previousLink");

    const headingRevealed = "heading-revealed";
    const slideRevealed = "slide-revealed";

    nextLink.addEventListener("click", (event) => { 
        goToNextSlide();
    });

    previousLink.addEventListener("click", (event)=> { 
        goToPreviousSlide();
    });

    document.addEventListener("keyup", (event) => {
        if (event.key === 'ArrowRight') {
            goToNextSlide();
        }
        else if (event.key === 'ArrowLeft') {
            goToPreviousSlide();
        }
    });
}

function goToPreviousSlide(){ 
    if (slideElement === null) { 
        return ; 
    }
    else if (slideElement.classList.contains(slideRevealed)) {
        slideElement.classList.remove(slideRevealed);
        subHeadingElements.forEach(heading => {
            heading.classList.add(dNone);
        });
    }
    else if (slideElement.classList.contains(headingRevealed)) {
        headingElement.classList.add(dNone);
        slideElement.classList.remove(headingRevealed);
    }
    else if (previousLink) {
        window.location.href = previousLink.getAttribute(dataUrl);
    }
}

function goToNextSlide() { 
    if (slideElement === null) { 
        return; 
    } 
    else if (!slideElement.classList.contains(headingRevealed)) {
        headingElement.classList.remove(dNone);
        slideElement.classList.add(headingRevealed);
    }
    else if (!slideElement.classList.contains(slideRevealed)) {
        slideElement.classList.add(slideRevealed);
        subHeadingElements.forEach(heading => {
            heading.classList.remove(dNone);
        });
    } else if (nextLink) {
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
