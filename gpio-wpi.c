#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "gpio.h"


void set_gpio(char* noPin,char* etats) //int argc, char *argv[]
{
    int pin = atoi(noPin);

    wiringPiSetupGpio();
    pinMode(pin,OUTPUT);
    printf("%c  %c",etats[1],noPin[0]);

    switch (etats[1])
    {
    case 'n':
        digitalWrite(pin,HIGH);
        break;

    case 'f':
        digitalWrite(pin,LOW);
        break;

    default:
        break;
    }
}

