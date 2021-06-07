/* trackuino copyright (C) 2021  IU2FRL Luca
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

 /*
 *  Copyright (C) 2018 - Handiko Gesang - www.github.com/handiko
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "config.h"
#include "dra818.h"
#if (ARDUINO + 1) >= 100
#  include <Arduino.h>
#else
#  include <WProgram.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <SoftwareSerial.h>
#include "pin.h"

SoftwareSerial dorji(RRXD, RTXD);

void dorji_sequence();
void dorji_init(SoftwareSerial &ser);
void dorji_reset(SoftwareSerial &ser);
void dorji_setfreq(float txf, float rxf, SoftwareSerial &ser);
void dorji_readback(SoftwareSerial &ser);

/*
 * 
 */
void dorji_init(SoftwareSerial &ser)
{
  ser.println("AT+DMOCONNECT");
}

void dorji_reset(SoftwareSerial &ser)
{
  for(char i=0;i<3;i++)
    ser.println("AT+DMOCONNECT");
}

void dorji_setfreq(float txf, float rxf, SoftwareSerial &ser)
{
  ser.print("AT+DMOSETGROUP=0,");
  ser.print(txf, 4);
  ser.print(',');
  ser.print(rxf, 4);
  ser.println(",0000,0,0000");
}

void dorji_readback(SoftwareSerial &ser)
{
  String d;
  
  while(ser.available() < 1);
  if(ser.available() > 0)
  {
    d = ser.readString();
    Serial.print(d);
  }
}

void dorji_sequence() {
  // RTX Pins
  pinMode(PTT_PIN, OUTPUT);
  pinMode(RPD, OUTPUT);
  pinMode(POW_PIN, OUTPUT);

  // Powersave and OUT power
  pin_write(RPD, HIGH);
  pin_write(POW_PIN, POUT);
  
  #ifdef DEBUG_RTX
    Serial.println("");
    Serial.println("RTX Setup...");
  #endif
  dorji.begin(RBAUD);
  delay(1000);
  dorji_reset(dorji);
  dorji_readback(dorji);
  delay(1000);
  dorji_setfreq(TXFREQ, RXFREQ, dorji);
  dorji_readback(dorji);
  #ifdef DEBUG_RTX
    Serial.print("RTX Setup Done! RX: ");
    Serial.print(RXFREQ, 3);
    Serial.print("MHz TX: ");
    Serial.print(TXFREQ, 3);
    Serial.println("MHz");
  #endif
}
