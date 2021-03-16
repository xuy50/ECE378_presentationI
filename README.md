# ECE378_presentationI

My project files:<br>
lib folder (library files in the lib folder)<br>
lcd.c (the c file for interfacing the I2C LCD with pcf8574 chip to the ATmega328P is lcd.)c<br>
compile_script.py (the compile_script.py is the script to compile my project)<br>

For the project, I need to interface I2C with an LCD to the ATmega328P with a usable library for the I2C LCD, which can be used for different size LCD screen. I found the mostly completely library from Davide Gironi. He write a very nice library which is based on lcd library by Peter Fleury. However, the library can't be used directly for my UNO board. I changed some code for my UNO board to let it work, after I searched and did many times debug. After it can work on my UNO board, I add some function to use the lib for interfacing the project easily.<br><br>

The library for the project also can be compatible with other size screens, we only need to change the line account, the length for each line, the addresses for each line, and pins for different screens in the library file "lcdpcf8574.h". Nevertheless, I only have 1602A screen can be used, I really cannot test other size screens addresses and currect pins, so I do not know the currect pins and addressed for other screens.<br><br>



<br>
References:<br>
https://www.digikey.com/en/products/detail/nxp-usa-inc/PCF8574T-3-518/735791<br>
https://www.nxp.com/docs/en/data-sheet/PCF8574_PCF8574A.pdf<br>
http://davidegironi.blogspot.com/2013/06/an-avr-atmega-library-for-hd44780-based.html#.YE_9RGhKguV<br>
https://www.byteparadigm.com/applications/introduction-to-i2c-and-spi-protocols/?/article/AA-00255/22/Introduction-to-SPI-and-IC-protocols.html<br>
