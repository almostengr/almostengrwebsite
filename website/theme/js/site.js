const dNone = "d-none";
const dataUrl = "data-url";
const titleElement = document.getElementById("slideTitle");
const bodyElement = document.getElementById("slideBody");
const previousLink = document.getElementById("previousLink");
const nextLink = document.getElementById("nextLink");

class SlideShow {
    currentSlide = 0;

    constructor() {
        this.bodyElement = document.getElementById("slideBody");

        if (this.bodyElement === null) {
            return;
        }

        let selectedSlide = [];
        const nodes = Array.from(this.bodyElement.children);

        nodes.forEach(node => {
            if (node.tagName === "HR") {
                if (selectedSlide.length > 0) {
                    this.slides.push(selectedSlide);
                    selectedSlide = [];
                }
                else {
                    selectedSlide.push(node);
                }
            }
        });

        // last slide
        if (selectedSlide.length > 0) {
            this.slides.push(selectedSlide);
        }
    }


    currentSlide = 0;
    slides = [];

    constructor() {
        this.bodyElement = document.getElementById("slideBody");

        if (!this.bodyElement) return;

        let selectedSlide = [];
        const nodes = Array.from(this.bodyElement.children);

        nodes.forEach(node => {
            if (node.tagName === "HR") {
                if (selectedSlide.length > 0) {
                    this.slides.push(selectedSlide);
                    selectedSlide = [];
                }
            } else {
                selectedSlide.push(node);
            }
        });

        // push last slide
        if (selectedSlide.length > 0) {
            this.slides.push(selectedSlide);
        }

        this.bindEvents();
        this.showSlide(0);
    }

    // nextSlide() {
    //     if (this.bodyElement === null) {
    //         return;
    //     }

    //     if (this.currentSlide >= this.slides.length) {
    //         return;
    //     }

    // }

    // previousSlide() {
    //     if (this.bodyElement === null) {
    //         return;
    //     }

    //     if (this.currentSlide <= 0) {
    //         return;
    //     }
    // }

    nextSlide() {
        if (this.currentSlide < this.slides.length - 1) {
            this.showSlide(this.currentSlide + 1);
        }
    }

    previousSlide() {
        if (this.currentSlide > 0) {
            this.showSlide(this.currentSlide - 1);
        }
    }
} // end class SlideShow




function addSlideShowNavigation2() {
    if (bodyElement === null) {
        return;
    }

    const slides = document.getElementsByTagName("hr");



    bodyElement.classList.remove(dNone);
}

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
