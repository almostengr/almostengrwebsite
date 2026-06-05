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
    title.classList.add("text-dark");
}

if (title !== null) {
    titleColumn.innerText = title.toUpperCase();
}

switch (video) {
    case "tech":
        lightSidebar();
        titleColumn.classList.add("bg-success");
        break;

    case "personal":
        darkSidebar();
        titleColumn.classList.add("bg-info");
        break;

    case "handyman":
        darkSidebar();
        titleColumn.classList.add("bg-warning");
        break;

    default:
        lightSidebar();
        titleColumn.classList.add("bg-dark");
        break;
}
