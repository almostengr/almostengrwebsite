---
title: .NET Core CheatSheet
description: Useful commands and code snippets when working with .NET Core and C# (c-sharp)
---

Cheatsheets have useful commands to do tasks that you may forget. This cheatsheet
consisits of commands that I use when buidling .NET Core applications using Visual
Studio Code and .NET Core via the command line.

```sh
dotnet watch run
```

Runs the application. It will also watch the files to see if they have been modified.
If they have been modified, the application will be rebuilt automatically.

```sh
dotnet run
```

Runs the application.

```sh
dotnet tool install --global dotnet-ef
```

Installs the Entity Framework for the selected project

```sh
dotnet tool install -g dotnet-aspnet-codegenerator
```

Installs the Code Generator tool. This allows for you to create controller, model, or
view files that have the initial text already entered into the file. This is close to
the method that Visual Studio uses when you create new files and it does scaffolding.
