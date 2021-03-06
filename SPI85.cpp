/*
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 
Added to github repository by Stanley Seow
for Nordic nRF24L01 wireless modules

Date : 10 Apr 2013
e-mail : stanleyseow@gmail.com
github : https://github.com/stanleyseow/attiny-nRF24L01
Desc   : This SPI 85 is for attiny85/x5 and attiny84/x4

Date : 24 July 2013
Desc : Updates pin mapping based on arduino-tiny-cores
https://code.google.com/p/arduino-tiny/

Date : 11 Aug 2013
Desc : Renamed SPI MOSI/MISO to USI_DO/ USI_DI to prevent confusion with SPI
Pls refer to page 61 of attiny84 datasheet

Date   : 16 Jun 2017
github : https://github.com/neimar2009/SPI85
Desc   : Copiado para um novo repositório visando o desenvolvimento individual.

 */

#include "pins_arduino.h"
#include "SPI85.h"

#if defined( __AVR_ATtiny85__ )
const static uint8_t SS     = PB4;
const static uint8_t USI_DO = PB1;
const static uint8_t USI_DI = PB0;
const static uint8_t SCK    = PB2;
#endif

// attiny84 tested working using Arduino Digital Pins below
#if defined( __AVR_ATtiny84__ )
const static uint8_t SS     = 3;
const static uint8_t USI_DO = 5;
const static uint8_t USI_DI = 4; 
const static uint8_t SCK    = 6;
#endif

SPI85Class SPI85;

void SPI85Class::begin() {
  // Set direction register for SCK and USI_DO pin.
  // USI_DI pin automatically overrides to INPUT.
  // When the SS pin is set as OUTPUT, it can be used as
  // a general purpose output port (it doesn't influence
  // SPI operations).

  pinMode(SCK, OUTPUT);
  pinMode(USI_DO, OUTPUT);
  pinMode(USI_DI,INPUT);

  digitalWrite(USI_DI,HIGH);
  digitalWrite(SCK, LOW);
  digitalWrite(USI_DO, LOW);

}

void SPI85Class::end() {
  pinMode(SCK, INPUT);
  pinMode(USI_DO, INPUT);
  pinMode(USI_DI,INPUT);
}

void SPI85Class::setDataMode(uint8_t mode)
{
  //SPCR = (SPCR & ~SPI_MODE_MASK) | mode; //FOR 328 NOT TINY
}

void SPI85Class::setClockDivider(uint8_t rate)
{
//  SPCR = (SPCR & ~SPI_CLOCK_MASK) | (rate & SPI_CLOCK_MASK);
//	SPSR = (SPSR & ~SPI_2XCLOCK_MASK) | ((rate >> 2) & SPI_2XCLOCK_MASK);
}

