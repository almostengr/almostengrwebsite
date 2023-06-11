function getHeaders() {
    return { "Content-Type": "application/json" };
}
const jukeboxRoute = "/jukeboxapi.php";

async function submitJukeboxRequest() {
    const alertMsg = document.getElementById("alert");
    const successClass = "alert-success";
    const dangerClass = "alert-danger";
    const dNone = "d-none";
    const form = document.getElementById("jukeboxForm");
    const formData = new FormData(form);
    const data = Object.fromEntries(formData);

    try {
        alertMsg.classList.add(dNone);

        const response = await fetch(jukeboxRoute, {
            method: 'POST',
            headers: getHeaders(),
            body: JSON.stringify(data),
        });

        const result = await response.json();

        if (response.status > 299) {
            throw new Error(result.message);
        }

        alertMsg.innerText = result.message;
        alertMsg.classList.remove(dangerClass);
        alertMsg.classList.add(successClass);
    } catch (error) {
        alertMsg.innerText = error;
        alertMsg.classList.remove(successClass);
        alertMsg.classList.add(dangerClass);
    }
    alertMsg.classList.remove(dNone);
}

async function updateCurrentSong() {
    const songDiv = document.getElementById("currentSong");
    
    if (songDiv == null) { return; }
    
    try {
        const response = await fetch(jukeboxRoute, {
            method: 'GET',
            headers: getHeaders(),
        });
        
        const result = await response.json();

        if (response.status > 299) {
            throw new Error(result.message);
        }

        if (result.message !== "") {
            songDiv.innerText = "Now playing... " + result.message;
        }
        else {
            songDiv.innerText = "The light show is offline.";
        }
    }
    catch (error) {
        songDiv.innerText = error;
    }

    const delayTime = 1000 * 5;
    setTimeout(updateCurrentSong, delayTime);
}
