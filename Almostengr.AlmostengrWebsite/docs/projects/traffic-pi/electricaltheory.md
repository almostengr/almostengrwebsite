---
title: Electrical Theory
description: Explain various electrical components with the traffic light.
---

## Relays

Relays are used when devices of different voltages or amperages are being used together. One common example
of this is relays that are used to control headlights on a car. The switch inside the vehicle has a lower
amperage and is considered to be a "signal wire". When the switch is turned on, a relay is closed
which then connects a different circuit to turn on and off the headlights.

In the Traffic Pi project, relays are used in a similar manner. The Raspberry Pi outputs 3.3VDC from the
GPIO pins. Those pins are connected to a relay board. The relay board is also connected to a 120VAC which is
needed by each of the signals. When the Pi sends an "on" signal to the relay board, the relay activates, thus
sending 120VAC from the source (in this case a wall outlet) to the signal and then corresponding signal then
turns on.

## Wires

### Wire Color Standards

The color of each wire always denotes its purpose. When using different color wires, you don't need to
have a tag on each wire. Instead, you create a service manual or other documentation that lists the purpose
of each wire based on its color.

For example, if you look a wiring harness on a car, you will notice that it has a number of wires that are
bundled together. Each of those wires has a purpose. The vehicle manufacturers create a document, often
referred to as a service manual, that lists each of the colors of the wire in the harness and their purpose.

### AC Circuits Wire Color

With an AC circuit, there are commonly 3 wires. Black, white, and bare copper or green.
Black wire in AC circuit represents the "hot" or supply voltage.
White wire in AC Circuit represents the neutral.
Green or bare copper wire in AC Circuit represents the ground.

### DC Circuits Wire Color

With a DC Circuit, there are two wires. Red and black.
Red wire in DC circuit represents the positive. This is the voltage that comes from the power source.
Black wire in DC circuits represents the negative. This is the voltage that goes back to the power source.

## AC vs DC

### Alternating Current (AC)

The current in an AC
system alternates between the hot and neutral wires. The frequency at which this occurs varies. In
North America (including the United States), the alternation takes place at 60 Hertz (Hz) or 60 times per second.
In other parts of the world, this alternation takes place at 50 Hz per second.

AC circuits are commonly used for items that require a lot of power to operate. These include large motors,
like the ones used in AC refrigeration and industrial machines.

### Direct Current (DC)

DC circuits are commonly used for battery powered systems, electronics, and other devices
that do not require a lot of power to operate. If a device, such as a cell phone or streaming player, 
has a "power brick", then that device runs on DC power. The power brick converts the AC power to DC power 
and at the same time reduces the voltage to what the device needs.
