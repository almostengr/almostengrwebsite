const jukeboxRoute = "/jukeboxapi.php";
const alertDangerClass = "alert-danger";
const alertSuccessClass = "alert-success";
const dNone = "d-none";
const textDangerClass = "text-danger";

const artistElement = document.getElementById("songArtist");
const cpuTempElement = document.getElementById("cpuTemp");
const jukeboxForm = document.getElementById("jukeboxForm");
const nwsTempElement = document.getElementById("nwsTemp");
const showMetaDataElement = document.getElementById("showMetaData");
const songTitleElement = document.getElementById("songTitle");
const windChillElement = document.getElementById("windChill");
const lastUpdatedElement = document.getElementById("lastUpdated");

function requestHeaders() {
    return { "Content-Type": "application/json" };
}

async function submitJukeboxRequest() {
    alertBody.classList.add(dNone);

    try {
        const formData = new FormData(jukeboxForm);
        const data = Object.fromEntries(formData);

        const response = await fetch(jukeboxRoute, {
            method: 'POST',
            headers: requestHeaders(),
            body: JSON.stringify(data),
        });

        const result = await response.json();
        alertText.innerText = result.message;
        if (response.status > 299) {
            throw new Error(result.message);
        }

        alertBody.classList.remove(alertDangerClass);
        alertBody.classList.add(alertSuccessClass);
    } catch (error) {
        alertBody.classList.remove(alertSuccessClass);
        alertBody.classList.add(alertDangerClass);
    }

    alertBody.classList.remove(dNone);

    const alertDisplaySeconds = 5 * 1000;
    setTimeout(() => {
        alertBody.classList.add(dNone)
    }, alertDisplaySeconds);
}

async function getDisplayData() {
    if (songTitleElement == null) {
        return;
    }

    try {
        const response = await fetch(jukeboxRoute, {
            method: 'GET',
            headers: requestHeaders(),
        });

        if (response.status > 299) {
            throw new Error(result.message);
        }

        let result = await response.json();

        if (result.title === "") {
            songTitleElement.innerText = "Show is offline";
            artistElement.innerText = "Show dates and times are available below.";
            jukeboxForm.classList.add(dNone);
        }
        else {
            songTitleElement.innerText = result.title;
            artistElement.innerText = result.artist;
            nwsTempElement.innerText = result.nwstemp;
            windChillElement.innerText = result.windchill;
            cpuTempElement.innerText = result.cputemp;
            lastUpdatedElement.innerText = result.createdTime;
            jukeboxForm.classList.remove(dNone);
        }

        songTitleElement.classList.remove(textDangerClass);
    }
    catch (errorMessage) {
        songTitleElement.innerText = errorMessage;
        songTitleElement.classList.add(textDangerClass);
    }
}

getDisplayData();
const delaySeconds = 1000 * 10;
setInterval(getDisplayData, delaySeconds);
