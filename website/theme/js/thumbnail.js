const sideBarColumn = document.getElementById("sidebar");
const titleColumn = document.getElementById("title");

const params = new URLSearchParams(document.location.search);
const video = params.get("video") ?? null;
const title = params.get("title") ?? null;

function lightSidebar() {
    sideBarColumn.classList.add("bg-light");
    titleColumn.classList.add("text-light");
}

function darkSidebar() {
    sideBarColumn.classList.add("bg-dark");
    titleColumn.classList.add("text-dark");
}

if (title !== null) {
    titleColumn.innerText = title.toUpperCase();
}

switch (video) {
    case "gardening":
        lightSidebar();
        titleColumn.classList.add("bg-success");
        break;

    case "handyman":
        darkSidebar();
        titleColumn.classList.add("bg-warning");
        break;

    case "personal":
        darkSidebar();
        titleColumn.classList.add("bg-info");
        break;

    case "tech":
        darkSidebar();
        titleColumn.classList.add("bg-success-subtle");
        break;

    default:
        darkSidebar();
        titleColumn.classList.add("bg-light");
        break;
}
