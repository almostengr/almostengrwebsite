# Controller Technology

The controller currently uses .NET Core 3.1. Tt is a multi-project application.

## User Interface (UI) / Front End

The user interface is a .NET Core MVC application. When you select the program that you want to run
from the application home page, the application then runs a linux command that runs the back
end program.

When the program is changed on the front end, the back end program is then terminated and the newly
select program is started.

## Relay Control / Back End

The back end of the application is a .NET Core Worker Service. The program modes are defined within
this worker service. The worker service will continue running until it is terminated by the front end
application or by a user via the command line or SSH.

## Source Code

The source code for this project can be downloaded from GitHub at
<a href="https://github.com/almostengr/trafficpi" target="_blank">
https://github.com/almostengr/trafficpi</a>.
