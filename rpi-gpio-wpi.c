#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>


void main(int argc, char *argv[]) //int argc, char *argv[]
{
    int pin = atoi(argv[1]);

    wiringPiSetupGpio();
    pinMode(pin,OUTPUT);
    printf("%c  %c",argv[2][1],argv[1][0]);

    switch (argv[2][1])
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

