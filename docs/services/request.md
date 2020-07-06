---
title: Request Services
description: Request Services offered by Almost Engineer Services
date: 2020-06-29
author: Kenny Robinson
keywords: request handymany, request services, request help, submit request
---

<form method="get">

<div class="m-2">
<label for="firstname">First Name <span class="text-danger">*</span></label><br>
<input class="form-control" type="text" id="firstname" name="firstname" minlength="2"
 placeholder="First Name" required>
</div>

<div class="m-2">
<label for="lastname">Last Name <span class="text-danger">*</span></label><br>
<input class="form-control" type="text" id="lastname" name="lastname" minlength="2" 
 placeholder="Last Name" required>
</div>

<div class="m-2">
<label for="emailer">Email Address <span class="text-danger">*</span></label><br>
<input class="form-control" type="email" id="emailer" name="emailer" minlength="5"
 placeholder="user@thealmostengineer.com" required>
<div class="text-muted">Enter the email address that you can be contacted at.</div>
</div>

<div class="m-2">
<label for="phonenum">Phone Number <span class="text-danger">*</span></label><br>
<input class="form-control" type="tel" id="phonenum" pattern="[0-9]{3}-[0-9]{3}-[0-9]{4}" 
 placeholder="555-555-5555" required>
<div class="text-muted">Enter the phone number that you can be contacted at. Enter number in 
555-555-5555 format.</div>
</div>

<div class="m-2">
<label for="servicetype">What Service Are You Needing? <span class="text-danger">*</span></label><br>
<select class="form-control" id="servicetype" required>
    <option selected="selected"></option>
    <optgroup label="Handyman Services">
        <option value="Bed Assembly">Bed Assembly</option>
        <option value="Bookcase Assembly">Bookcase Assembly</option>
        <option value="Ceiling Fan Replacement/Installation">Ceiling Fan Replacement/Installation</option>
        <option value="Doorbell Replacement/Installation">Doorbell Replacement/Installation</option>
        <option value="Furniture Assembly">Furniture Assembly</option>
        <option value="Holiday Lighting and Decorations">Holiday Lighting and Decorations</option>
        <option value="Kitchen Island Assembly">Kitchen Island Assembly</option>
        <option value="Lawn Services (Cutting and Edging)">Lawn Services (Cutting and Edging)</option>
        <option value="Lighting Fixture Replacement/Installation">Lighting Fixture Replacement/Installation</option>
        <option value="Outdoor Furniture Assembly">Outdoor Furniture Assembly</option>
        <option value="Patio Furniture Assembly">Patio Furniture Assembly</option>
        <option value="Picture Hanging">Picture Hanging</option>
        <option value="Shower Head Replacement/Installation">Shower Head Replacement/Installation</option>
        <option value="Smart Thermostat Replacement/Installation">Smart Thermostat Replacement/Installation</option>
        <option value="Table Assembly">Table Assembly</option>
        <option value="Television (TV) Stand Assembly">Television (TV) Stand Assembly</option>
        <option value="Television (TV) Wall Mounting">Television (TV) Wall Mounting</option>
        <option value="Trim Repair">Trim Repair</option>
        <option value="Window Treatment (Curtains, Blinds, Drapes) Installation">Window Treatment (Curtains, Blinds, Drapes) Installation</option>
    </optgroup>
    <optgroup label="Tech Services">
        <option value="Computer Repair">Computer Repair</option>
        <option value="Computer Programming Sessions">Computer Programming Sessions</option>
        <option value="Drupal Maintenance and Updates">Drupal Maintenance and Updates</option>
        <option value="Robotic Process Automation (RPA)">Robotic Process Automation (RPA)</option>
        <option value="Virus and Malware Removal">Virus and Malware Removal</option>
        <option value="Website Design">Website Design</option>
        <option value="WordPress Maintenance and Updates">WordPress Maintenance and Updates</option>
    </optgroup>
</select>
</div>

<div class="m-2">
<label for="jobdetails">Project Details</label><br />
<textarea class="form-control" rows="5" name="jobdetails" id="jobdetails" 
 placeholder="Need exterior trim replaced and painted with rot resistent materials."></textarea>
<div class="text-muted">Enter details about the work to be done. The more details, the better.</div>
</div>

<div class="m-2">
<button type="submit" class="btn btn-danger">Submit</button>
</div>

</form>
