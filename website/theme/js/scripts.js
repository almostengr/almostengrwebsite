async function submitJukeboxRequest() {
    const form = document.getElementById("jukeboxForm");
    const alertMsg = document.getElementById("alert");
    const dNone = "d-none";
    const successClass = "alert-success";
    const dangerClass = "alert-danger";
    const formData = new FormData(form);
    const data = Object.fromEntries(formData);

    try {
        alertMsg.classList.add(dNone);

        const response = await fetch('/jukeboxapi.php', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(data),
        });

        const result = await response.json();

        if (response.status > 299) {
            throw new Error(result.message);
        }

        alertMsg.innerText = result.message;
        alertMsg.classList
        alertMsg.classList.add(successClass);
        alertMsg.classList.remove(dangerClass);
        alertMsg.classList.remove(dNone);
    } catch (error) {
        alertMsg.innerText = error;
        alertMsg.classList.add(dangerClass);
        alertMsg.classList.remove(successClass);
        alertMsg.classList.remove(dNone);
    }
}