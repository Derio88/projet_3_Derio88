

libc : rpi-gpio-libc.c main.c
	gcc gpio-libc.c main.c -o rpi_gpio
	
wpi : rpi-gpio-wpi.c main.c
	gcc gpio-wpi.c main.c -l wiringPi -o rpi-gpio