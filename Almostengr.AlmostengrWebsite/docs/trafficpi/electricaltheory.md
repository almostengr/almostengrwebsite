---
title: Electrical Theory
description: Explain various electrical components with the traffic light.
---

## Table of Contents

* [Relays](#relays)
* [Wire Gauge](#wire-gauge)
* [Wire Color Standards](#wire-color-standards)
* [AC vs DC](#ac-vs-dc)

## Relays

Relays are used when devices of different voltages or amperages are being used together. One common example
of this is relays that are used to control headlights on a car. The switch inside the vehicle has a lower 
amperage signal that is ran through it to be used as a signal. When the switch is turned on, a relay is closed 
which then connects a different circuit to turn on and off the headlights.

In the Traffic Pi project, relays are used in a similar manner. The Raspberry Pi outputs 3.3DCV from the 
GPIO pins. Those pins are connected to a relay board. The relay board is also connected to a 120V which is 
needed by each of the signals. When the Pi sends an "on" signal to the relay board, the relay activates, thus
sending 120V from the source (in this case an outlet) to the signal and then corresponding signal then
turns on.

## Wire Gauge

## Wire Color Standards

The color of each wire always denotes its purpose. When using different color wires, you don't need to 
have a tag on each wire. Instead, you create a service manual or other documentation that lists which 
color wire each is responsible for.

For example, if you look a wiring harness on a car, you will notice that it has a number of wires that are 
bundled together. Each of those wires has a purpose. The vehicle manufacturers create a document, often 
referred to as a service manual, that lists each of the colors of the wire in the harness and their purpose.

### AC Circuits

With an AC circuit, there are commonly 3 wires. Black, white, and bare or green. 
Black wire in AC circuit represents the "hot" or supply voltage.
White wire in AC Circuit represents the neutral. The netural 

### DC Circuits

With a DC Circuit, there are two wires. Red and black. The current in a DC system only flows in one 
direction. 
Red wire in DC circuit represents the positive. This is the voltage that comes from the power source.
Black wire in DC circuits represents the negative. This is the voltage that goes back to the power source.

## AC vs DC

### Alternating Current (AC)

The current in an AC
system alternates between the hot and neutral wires. The frequency at which this occurs varies. In the
North American (including the United States), the alternation takes place at 60 Hertz or 60 times per second.

AC circuits are commonly used for items that require a lot of power to operate. These include large motors, 
like the ones used in AC refrigeration and industrial machines.

### Direct Current (DC)

DC circuits are commonly used for battery powered systems and devices that do not require a lot of power 
to operate.
