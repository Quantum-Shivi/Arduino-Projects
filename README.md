# Arduino-Projects

Arduino Learning is my hands-on journey into embedded systems and electronics.

This repository contains a collection of beginner-friendly Arduino sketches that demonstrate basic electronics and programming concepts such as LED control, button input, serial communication, analog sensing, seven-segment displays, and LCD interfacing.

Each project is stored in its own folder and can be uploaded as a standalone sketch to an Arduino board such as an Uno or Nano.

Projects Included
1digit7segment
A simple single-digit seven-segment display project.

4digit7segment
Demonstrates how to control a four-digit seven-segment display.

IncrementDecrement4digit7segment
A four-digit display project that allows the user to increment and decrement a number using buttons.

Incrementnumber1digit
A one-digit display counter that increases its value when a button is pressed.

Keyboard4buttonslcd
Uses four buttons and an I2C LCD to print numbers 1, 2, 3, and 4 on the screen.

LCDHelloShivi
A basic LCD example that displays a simple message on an I2C screen.

LDRvalueprinter
Reads the analog value from an LDR sensor and prints it to the Serial Monitor.

LDRvalueprinterLCD
Displays the LDR sensor value on an I2C LCD screen.

LEDdriver
A basic LED blinking example.

SimpleSerialport
A simple serial communication project that responds to commands like color and number.

Smartnightlight
An automatic night light that turns on an LED when the surrounding light is low.

t1
An improved version of the four-digit display counter with button debouncing and smoother increment/decrement behavior.

What You’ll Learn
Digital output with LEDs
Button input handling
Analog sensor reading with LDR
Serial communication
Seven-segment display control
LCD display usage with I2C
Required Tools
Arduino IDE
Arduino board such as Uno or Nano
Jumper wires
Basic electronic components depending on the project
I2C LCD libraries for the LCD-based sketches
How to Use
Open the desired .ino file in the Arduino IDE.
Select the correct board and COM port.
Upload the sketch to the Arduino.
Connect the required components based on the project.
Notes
LCD projects may require the correct I2C library and address configuration.
Some sketches depend on specific pins for buttons, sensors, or displays.
These examples are intended for learning and experimentation.
