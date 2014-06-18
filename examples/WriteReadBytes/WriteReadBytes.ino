/**************************************************************************//**
 * \brief EEPROM 24C512 library for Arduino - Demonstration program
 * \author Copyright (C) 2012  Julien Le Sech - www.idreammicro.com
 * \version 1.0
 * \date 20120218
 *
 * This file is part of the EEPROM 24C512 library for Arduino.
 *
 * This library is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 * 
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see http://www.gnu.org/licenses/
 ******************************************************************************/

/**************************************************************************//**
 * \file WriteReadBytes.ino
 ******************************************************************************/
 
/******************************************************************************
 * Header file inclusions.
 ******************************************************************************/

#include <Wire.h>

#include <Eeprom24C512.h>

/******************************************************************************
 * Private macro definitions.
 ******************************************************************************/

/**************************************************************************//**
 * \def EEPROM_ADDRESS
 * \brief Address of EEPROM memory on TWI bus.
 ******************************************************************************/
#define EEPROM_ADDRESS 0x50

/******************************************************************************
 * Private variable definitions.
 ******************************************************************************/

static Eeprom24C512 eeprom(EEPROM_ADDRESS);

/******************************************************************************
 * Public function definitions.
 ******************************************************************************/

/**************************************************************************//**
 * \fn void setup()
 *
 * \brief
 ******************************************************************************/
void setup()
{
    // Initialize serial communication.
    Serial.begin(9600);
    
    // Initiliaze EEPROM library.
    eeprom.initialize();

    // Declare byte arrays.
    byte inputBytes[94] = { 0 };
    byte outputBytes[94] = { 0 };

    // Fill input array with printable characters. See ASCII table for more
    // details.
    for (byte i = 0; i < 94; i++)
    {    
        inputBytes[i] = i + 33;
    }

    // Write input array to EEPROM memory.
    Serial.println("Write bytes to EEPROM memory...");
    eeprom.writeBytes(0, 94, inputBytes);

    // Read array with bytes read from EEPROM memory.
    Serial.println("Read bytes from EEPROM memory...");
    eeprom.readBytes(0, 94, outputBytes);
    
    // Print read bytes.
    Serial.println("Read bytes:");
    for (byte i = 0; i < 94; i++)
    {
        Serial.write(outputBytes[i]);
        Serial.print(" ");
    }
    Serial.println("");
}

/**************************************************************************//**
 * \fn void loop()
 *
 * \brief
 ******************************************************************************/
void loop()
{

}
