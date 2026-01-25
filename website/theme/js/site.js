const dNone = "d-none";

function addSlideshowNavigation() {
    const slideElement = document.getElementById("slideshow");
    if (slideElement === null) {
        return;
    }

    const headingElement = document.querySelector("h1").closest("div");
    const subHeadingElements = document.querySelectorAll("h2");

    headingElement.classList.add(dNone);
    subHeadingElements.forEach(heading => {
        heading.classList.add(dNone);
    });

    const nextLink = document.getElementById("nextLink");
    const previousLink = document.getElementById("previousLink");

    const headingRevealed = "heading-revealed";
    const slideRevealed = "slide-revealed";

    document.addEventListener("keyup", (event) => {
        if (event.key === 'ArrowRight') {
            if (!slideElement.classList.contains(headingRevealed)) {
                headingElement.classList.remove(dNone)
                slideElement.classList.add(headingRevealed);
            }
            else if (!slideElement.classList.contains(slideRevealed)) {
                slideElement.classList.add(slideRevealed);
                subHeadingElements.forEach(heading => {
                    heading.classList.remove(dNone);
                });
            } else if (nextLink) {
                window.location.href = nextLink.href;
            }
        }
        else if (event.key === 'ArrowLeft') {
            if (slideElement.classList.contains(slideRevealed)) {
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
                window.location.href = previousLink.href;
            }
        }
    });
}

function addTargetToExternalLinks() {
    document.querySelectorAll('a').forEach(link => {
        if (link.hostname !== window.location.hostname) {
            link.setAttribute('target', '_blank');
        }
    });
}

addTargetToExternalLinks();
addSlideshowNavigation();
