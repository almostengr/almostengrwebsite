# Python Cheatsheet

This cheatsheet has some of the tips and tricks for using the Python programming 
language. As I learn more about Python, I will post more useful code snippets here
in order to help you.

Submissions or issues identified can be submitted via issue on this 
[project's repository](https://github.com/almostengr/almostengrwebsite/issues).

## Table of Contents

### Basics

* [Declaring Variables](#declare-variables)
* [Functions](#functions)
* [Running Python Scripts](#running-python-scripts)

### Math and Numbers

* [Addition](#addition)
* [Division](#division)
* [Multiplication](#multiplication)
* [Random Number](#random-number)
* [Subtraction](#subtraction)

### Examples

* [Hello World](#hello-world)
* [Raspberry Pi Traffic Light Controller](#more-resources)

----

## Running Python Scripts 

```bash
python <script name>
``` 

Replace ```<script name>``` with the file name of the Python script that you want to run.

----

## Declare Variables 

Variables hold the values that are used in your application or script. In Python, 
variables are not strong-typed. This means that the variables you declare,
are not limited to a particular data type. However, the variable does have a 
value, any future changes to that value must be of the same type. So you cannot set 
the value of a variable to a string and then change it to a integer. 

```python
myVariable = "red" 
myOtherVariable = false
myOtherOtherVariable = 5
``` 

----

## Functions

To write a function in Python, you start the function out with the "def" keyword. 

### Example

```python
def myFunction (param1, param2, param3): 
   sum = param1 + param2 + param3
   return sum
```

If you notice, there are no braces or brackets around the contents of the function. 
Python relies on indentation for the grouping of lines together within a given 
section.

----

## Random Number

Random nubmers can be used to do countdowns or other things that are needed. 
To get a random number, you have to import the randomint class from the random library 
by adding 

```python
from random import randint
```

to the top of your Python script. 

Then you can set the random integer to a variable by doing 

```python
myNumber = randint(5,60)
```

In the example above, 5 is the lower limit of the range and 60 is the upper limit
of the range. If your range needs to be different, then changes either or both of 
these values.

----

## Basic Mathematics

### Addition 

To do addition in Python, just have to code out two numbers and add them together 
like you would normally do for a math problem that you were writing on paper. Just 
keep in mind that the calculations always have to be done on the right side of the
equals sign and will be set to the variable on the left of the equals sign. 

```python
sum = 5 + 3
print sum
```

From the example above, the output will print 8. 

### Subtraction

Similar in fashion, subtraction is written just like addition, except it uses the 
minus sign instead of the plus sign. 

```python 
difference = 10 - 3
print difference 
```

From the example above, the output will print 7.

### Multiplication

Multiplication is done using the asterisk. 

```python
product = 4 * 3
print product
```

From the example above, the output will print 12.

### Division 

```python 
quotient = 20 / 5
print quotient
```

From the example above, the output will print 4. 

----

## Hello World

Below is a sample of how to print out "Hello world" in Python.

```python
print ("Hello world")
```

----

## More Resources

The Raspberry Pi traffic light project is written in Python code. You can review the 
code at 
[https://github.com/almostengr/raspitraffic-stem](https://github.com/almostengr/raspitraffic-stem).
