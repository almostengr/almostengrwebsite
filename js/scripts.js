const jukeboxRoute = "/jukeboxapi.php";
const successClass = "alert-success";
const dangerClass = "alert-danger";
const dNone = "d-none";
const songNameElement = document.getElementById("currentSong");

const jukeboxForm = document.getElementById("jukeboxForm");
const artistElement = document.getElementById("currentArtist");
const controllerTempElement = document.getElementById("controllerTemp");
const nwsTempElement = document.getElementById("nwsTemp");
const queueCount = document.getElementById("songQueue");
const windChillElement = document.getElementById("windchill");
const showOffline = document.getElementById("showOffline");
const currentSongMetaData = document.getElementById("currentSongMetaData");
const textDanger = "text-danger";

function getHeaders() {
    return { "Content-Type": "application/json" };
}

async function submitJukeboxRequest() {

    try {
        const formData = new FormData(jukeboxForm);
        const data = Object.fromEntries(formData);
        alertBody.classList.add(dNone);

        const response = await fetch(jukeboxRoute, {
            method: 'POST',
            headers: getHeaders(),
            body: JSON.stringify(data),
        });

        const result = await response.json();
        if (response.status > 299) {
            throw new Error(result.message);
        }

        alertText.innerText = result.message;
        alertBody.classList.remove(dangerClass);
        alertBody.classList.add(successClass);
    } catch (error) {
        alertText.innerText = error;
        alertBody.classList.remove(successClass);
        alertBody.classList.add(dangerClass);
    }
    alertBody.classList.remove(dNone);
}

async function getAllSettings() {
    try {
        const response = await fetch(jukeboxRoute, {
            method: 'GET',
            headers: getHeaders(),
        });

        if (response.status > 299) {
            throw new Error(result.message);
        }

        const result = await response.json();

        result.forEach(element => {
            let tempF = 32, tempC = 0;
            switch (element.identifier) {
                case "currentsong":
                    if (trim(element.value) == "") {
                        showOffline.classList.remove(dNone);
                        currentSongMetaData.classList.add(dNone);
                        jukeboxForm.classList.add(dNone);
                        break;
                    }

                    const songParts = element.value.split("|");
                    songNameElement.innerText = songParts[0]; // == "" ? showOfflineMessage : songParts[0];
                    artistElement.innerText = songParts[1] == undefined ? "" : songParts[1];
                    showOffline.classList.add(dNone);
                    currentSongMetaData.classList.remove(dNone);
                    jukeboxForm.classList.remove(dNone);
                    break;

                case "cputempc":
                    tempF = getFahrenheitFromCelsius(element.value);
                    tempC = roundCelsius(element.value);
                    controllerTempElement.innerText = `${tempF} F (${tempC} C)`;
                    break;

                case "nwstempc":
                    tempF = getFahrenheitFromCelsius(element.value);
                    tempC = roundCelsius(element.value);
                    nwsTempElement.innerText = `${tempF} F (${tempC} C)`;
                    break;

                case "queuecount":
                    queueCount.innerText = artistElement.innerText == "" ? 0 : element.value;
                    break;

                case "windchill":
                    tempF = getFahrenheitFromCelsius(element.value);
                    tempC = roundCelsius(element.value);
                    windChillElement.innerText = element.value == "" ? "None" : `${tempF} F (${tempC} C)`;
                    break;
            }
        });

        songNameElement.classList.remove(textDanger);
    }
    catch (errorMessage) {
        songNameElement.innerText = errorMessage;
        songNameElement.classList.add(textDanger);
    }
}

function getFahrenheitFromCelsius(celsius) {
    const value = parseFloat(celsius);
    const calcF = (value * (9 / 5)) + 32;
    return Math.round(calcF);
}

function roundCelsius(celsius) {
    const value = parseFloat(celsius);
    return Math.round(value);
}

if (songNameElement !== null) {
    const intervalDelay = 1000 * 7;
    setInterval(getAllSettings, intervalDelay);
}
