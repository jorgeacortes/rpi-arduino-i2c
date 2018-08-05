/*
 * main.c
 *
 *	RPI Project main file
 *
 *  Created on: Jul 14, 2018
 *      Author: Jorge
 */

#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#include "../includes/main.h"

#define PIN_USED 11

int main(void)
{
	int fd=0;
	int value=0;
	wiringPiSetup();
	fd=wiringPiI2CSetup(0x0A);
	pinMode(PIN_USED,OUTPUT);
	while(1)
	{
		digitalWrite(PIN_USED,HIGH);
		wiringPiI2CWrite(fd,0x01);
		delay (500);
		printf("Low\n");
		digitalWrite(PIN_USED,LOW);
		wiringPiI2CWrite(fd,0x00);
		delay(500);
		printf("High\n");
		value=wiringPiI2CRead(fd);
		printf("%d\n",value);
	}
	return 0;
}
