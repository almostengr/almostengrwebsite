---
title: Light Show Jukebox
---

Pick the song that you would like to hear next.

<form action="/jukeboxrequest.php" method="post">
  <p>
    <label for="sequenceName">Select a song:</label>
    <select name="sequenceName" id="sequenceName" required>
      <option value="">Select a song</option>
      <option value="song1">Song 1</option>
      <option value="song2">Song 2</option>
      <option value="song3">Song 3</option>
    </select>
  </p>
  <p>
    <label for="code">Enter the code:</label>
    <input type="text" name="code" id="code" required>
    <span class="note">The code is announced during the show</span>
  </p>
  <p>
    <button type="submit">Play My Song</button>
  </p>
</form>

