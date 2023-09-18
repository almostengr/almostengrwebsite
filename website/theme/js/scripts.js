const jukeboxRoute = "/jukeboxapi.php";
const dangerClass = "alert-danger";
const dNone = "d-none";
const textDanger = "text-danger";
const successClass = "alert-success";

const artistElement = document.getElementById("currentArtist");
const controllerTempElement = document.getElementById("controllerTemp");
const currentSongMetaData = document.getElementById("currentSongMetaData");
const jukeboxForm = document.getElementById("jukeboxForm");
const nwsTempElement = document.getElementById("nwsTemp");
const showOffline = document.getElementById("showOffline");
const songNameElement = document.getElementById("currentSong");
const windChillElement = document.getElementById("windchill");

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

        alertBody.classList.remove(dangerClass);
        alertBody.classList.add(successClass);
    } catch (error) {
        alertBody.classList.remove(successClass);
        alertBody.classList.add(dangerClass);
    }
    
    alertBody.classList.remove(dNone);

    const alertDisplaySeconds = 5 * 1000;
    setTimeout(() => {
        alertBody.classList.add(dNone)
    }, alertDisplaySeconds);
}

async function getDisplayData() {
    if (songNameElement == null) {
        return;
    }

    try {
        await fetch(jukeboxRoute, {
            method: 'GET',
            headers: requestHeaders(),
        });

        if (response.status > 299) {
            throw new Error(result.message);
        }
        let result = await response.json();

        if (result.Title === "") {
            showOffline.classList.remove(dNone);
            currentSongMetaData.classList.add(dNone);
            jukeboxForm.classList.add(dNone);
        }
        else {
            songNameElement.innerText = result.Title;
            artistElement.innerText = result.Artist;

            controllerTempElement.innerText = "";
            result.CpuTempSensors.foreach(element => {
                controllerTempElement.innerText += `${element} `;
            });

            nwsTempElement.innerText = result.NwsTemperature;
            windChillElement.innerText = element.value == "" ? "None" : `${tempF}F (${tempC}C)`;

            showOffline.classList.add(dNone);
            currentSongMetaData.classList.remove(dNone);
            jukeboxForm.classList.remove(dNone);
        }

        songNameElement.classList.remove(textDanger);
    }
    catch (errorMessage) {
        songNameElement.innerText = errorMessage;
        songNameElement.classList.add(textDanger);
    }
}

getDisplayData();
const delaySeconds = 1000 * 10;
setInterval(getDisplayData, delaySeconds);
