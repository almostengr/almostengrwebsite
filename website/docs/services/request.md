---
title: Request Services
description: Request Services offered by Almost Engineer Services
date: 2020-06-29
author: Kenny Robinson
---

<form method="get">

<h3>Some Info About You</h3>

<div class="m-2">
<label for="firstname">First Name</label><br>
<input class="form-control" type="text" id="firstname" placeholder="First Name" name="firstname" required>
</div>

<div class="m-2">
<label for="lastname">Last Name</label><br />
<input class="form-control" type="text" id="lastname" placeholder="Last Name" name="lastname" required>
</div>

<div class="m-2">
<label for="emailer">Email Address</label><br />
<input class="form-control" type="text" id="emailer" placeholder="user@thealmostengineer.com" name="emailer" required>
</div>

<h3>Info About The Project</h3>

<div class="m-2">
<label for="jobdetails">Project Details</label><br />
<small>Enter details about the work to be done. The more details, the better.</small><br>
<textarea class="form-control" rows="5" name="jobdetails" id="jobdetails"></textarea>
</div>

<div class="m-2">
<button type="submit" class="btn btn-danger">Submit Request</button>
</div>

</form>
