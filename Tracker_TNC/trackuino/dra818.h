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

#ifndef __DRA818_H__
#define __DRA818_H__

#include <SoftwareSerial.h>
#include "pin.h"

void dorji_sequence();
void dorji_init(SoftwareSerial &ser);
void dorji_reset(SoftwareSerial &ser);
void dorji_setfreq(float txf, float rxf, SoftwareSerial &ser);
void dorji_readback(SoftwareSerial &ser);

#endif
