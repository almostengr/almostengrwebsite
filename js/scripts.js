const jukeboxRoute = "/jukeboxapi.php";
const successClass = "alert-success";
const dangerClass = "alert-danger";
const dNone = "d-none";
const songNameElement = document.getElementById("currentSong");
const showOfflineMessage = "Show is offline";

function getHeaders() {
    return { "Content-Type": "application/json" };
}

async function submitJukeboxRequest() {
    const alertBody = document.getElementById("alertBody");
    const alertText = document.getElementById("alertText");
    const form = document.getElementById("jukeboxForm");
    const formData = new FormData(form);
    const data = Object.fromEntries(formData);

    try {
        alertBody.classList.add(dNone);

        if (songNameElement.innerText.indexOf(showOfflineMessage) !== -1) {
            throw new Error("The show is offline and not accepting requests.");
        }

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
    if (songNameElement == null) {
        return;
    }

    try {
        const response = await fetch(jukeboxRoute, {
            method: 'GET',
            headers: getHeaders(),
        });

        if (response.status > 299) {
            throw new Error(result.message);
        }

        const result = await response.json();
        const artistElement = document.getElementById("currentArtist");
        const controllerTempElement = document.getElementById("controllerTemp");
        const nwsTempElement = document.getElementById("nwsTemp");
        const queueCount = document.getElementById("songQueue");

        result.forEach(element => {
            let tempF = 32, tempC = 0;
            switch (element.identifier) {
                case "currentsong":
                    var songParts = element.value.split("|");
                    songNameElement.innerText = songParts[0] == "" ? showOfflineMessage : songParts[0];
                    artistElement.innerText = songParts[1] == undefined ? "" : songParts[1];
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
            }
        });
    }
    catch (errorMessage) {
        songNameElement.innerText = errorMessage;
    }

    const delaySeconds = 1000 * 7;
    setTimeout(getAllSettings, delaySeconds);
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

getAllSettings();
