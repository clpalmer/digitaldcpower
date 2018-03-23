<!--
  Title: Digital DC Power
  Description: ATMega8 Microcontroller-Based Digital DC Power Supply
  Author: clpalmer
-->
Digital DC Power 
================

This is an ATMega8 microcontroller-based digital DC power supply created by [tuxgraphics](http://tuxgraphics.org/electronics/201005/bench-power-supply-v3.shtml "tuxgraphics")

The software is entirely unchanged from the original and all credit goes to Guido Socher from tuxgraphics.

The only software changes made were to calibrate the hardware. The hardware was modified to suit my needs, removing the unneeded USB PC control.

The schematic and layout can be viewed/edited using the freeware version of DipTrace here:  
[DipTrace Downloads](https://diptrace.com/download/download-diptrace/ "DipTrace Downloads")

Software
--------
Compile the software and program the microcontroller:

1) edit and adapt the file hardware_settings.h 
   (calibration and selection of the right hardware type).

2) load and compile:
make 
make load

3) set the fuse bytes to 4MHz internal:
make wrfuse4mhz

This should result in the following settings:

avrdude: Device signature = 0x1e9307
avrdude: safemode: lfuse reads as E3
avrdude: safemode: hfuse reads as D9


The make wrfuse4mhz needs to be done only once
unless you change the Atmega8 chip. make/make load
need to be repeated everytime you change something
in the software (e.g update of hardware_settings.h). 

The poweresupply must be powered up during programming
but nothing should be connected to the output. Make
also sure that you do not accidently press any button
during the programming (loading the software into the uC).


Calibration
-----------
To calibrate the display edit the file hardware_settings.h
Here you can change also the settings between the 30V and the 22V version.


Overview
========
This is the software for the tuxgraphics.org electronic digital DC power supply. 
A microncontroller controlled bench DC power supply unit. 

All of the control logic is implemented in software. This
saves a lot of parts compared to conventional lab-power 
supplies. This means it is cheaper, easier to build and
offers more functionallity.

Note however that this means also that the short circuit
protection is implemented in software. So be careful when
you change something in the software. If the microcontroller 
is not running properly due to a software fault then there
might not be any short circuit protection.


The software is prepared for 2 versions:
- 0-22V 0-2.5A
- 0-30V 0-2A

It is possible to build a different version without major
re-design. 


How the software works
======================

I have added a lot more comments to the software than usual. 
It should be possible even for somebody with little experience in
C programming to understand how this software works.

The circuit uses as internal units ADC steps. All external values
(Volt, Ampere) are converted to steps of the analog to digital 
converter (ADC). When you change the voltage then this is first
converted to ADC steps and then it will be further processed.


main.c -- this is the main program. All initialization starts here.
 It contains a infinite while loop which will execute the slow tasks
 one by one: 
   + Convert ADC results to display values
   + Update the LCD
   + Check push buttons
 
analog.c -- the analog to digital converter and the main control loop
         for the power supply. Everything is interrupt based here as
         it needs to be fast.
         Voltage control, current limitation and short circuit protection
         are all implemented here.

dac.c -- the digital to analog converter. Initalized from main.c but
         used exclusivly from analog.c

kbd.c -- the keyboard driver

i2c_avr.c -- I2C over RS232 communication

lcd.c -- the LCD driver. This is a special version which will not need
         the rw pin of the display. It uses instead an internal timer
         which should be long enough for the display to finish its task.
         The RW pin which is normally used to poll the display to see
         if it is ready is not needed.

-------------------------------------------------------------------
Copyright: GPL V2
Author: Guido Socher
Homepage: http://www.tuxgraphics.org/electronics/
-------------------------------------------------------------------
Change history:
digitaldcpower-0.5.0 -- 2007-07-12 first version of the new power supply

digitaldcpower-0.5.1 -- 2007-09-25 Corrected typo in readme.htm file.

digitaldcpower-0.5.2 -- 2009-03-22 Minor updates to the Makefile, no code change.

digitaldcpower-0.5.3 -- 2009-06-27 Reset the display once in a while. This helps
                        if there is a garbage character on the screen due to 
			high power electrical interference
-------------------------------------------------------------------
</pre>
