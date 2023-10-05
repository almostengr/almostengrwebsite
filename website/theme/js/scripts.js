const JUKEBOX_ROUTE = "/jukeboxapi.php";
const ALERT_DANGER_CLASS = "alert-danger";
const ALERT_SUCCESS_CLASS = "alert-success";
const D_NONE = "d-none";

const artistElement = document.getElementById("songArtist");
const cpuTempElement = document.getElementById("cpuTemp");
const jukeboxForm = document.getElementById("jukeboxForm");
const nwsTempElement = document.getElementById("nwsTemp");
const showMetaDataElement = document.getElementById("showMetaData");
const songTitleElement = document.getElementById("songTitle");
const windChillElement = document.getElementById("windChill");
const lastUpdatedElement = document.getElementById("lastUpdated");
const errorsElement = document.getElementById("errors");

function requestHeaders() {
    return { "Content-Type": "application/json" };
}

async function submitJukeboxRequest() {
    alertBody.classList.add(D_NONE);

    try {
        const formData = new FormData(jukeboxForm);
        const data = Object.fromEntries(formData);

        const response = await fetch(JUKEBOX_ROUTE, {
            method: 'POST',
            headers: requestHeaders(),
            body: JSON.stringify(data),
        });

        const result = await response.json();
        alertText.innerText = result.message;
        if (response.status > 299) {
            throw new Error(result.message);
        }

        alertBody.classList.remove(ALERT_DANGER_CLASS);
        alertBody.classList.add(ALERT_SUCCESS_CLASS);
    } catch (error) {
        alertBody.classList.remove(ALERT_SUCCESS_CLASS);
        alertBody.classList.add(ALERT_DANGER_CLASS);
    }

    alertBody.classList.remove(D_NONE);

    const alertDisplaySeconds = 5 * 1000;
    setTimeout(() => {
        alertBody.classList.add(D_NONE)
    }, alertDisplaySeconds);
}

async function getDisplayData() {
    if (songTitleElement == null) {
        return;
    }

    try {
        const response = await fetch(JUKEBOX_ROUTE, {
            method: 'GET',
            headers: requestHeaders(),
        });

        if (response.status > 299) {
            throw new Error(result.message);
        }

        let result = await response.json();

        if (result.title === "") {
            songTitleElement.innerText = "RADIO OFF";
            artistElement.innerText = "Show times are listed below";
            jukeboxForm.classList.add(D_NONE);
            showMetaDataElement.classList.add(D_NONE);
        }
        else {
            songTitleElement.innerText = result.title;
            artistElement.innerText = result.artist;
            nwsTempElement.innerText = result.nwstemp;
            windChillElement.innerText = result.windchill;
            cpuTempElement.innerText = result.cputemp;
            lastUpdatedElement.innerText = result.createdTime;
            jukeboxForm.classList.remove(D_NONE);
            showMetaDataElement.classList.remove(D_NONE);
        }

        errorsElement.innerText = "";
    }
    catch (errorMessage) {
        errorsElement.innerText = errorMessage;
    }
}

getDisplayData();
const delaySeconds = 1000 * 10;
setInterval(getDisplayData, delaySeconds);
