/*
* This file is part of smarthomatic, http://www.smarthomatic.org.
* Copyright (c) 2013 Uwe Freese
*
* smarthomatic is free software: you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation, either version 3 of the License, or (at your
* option) any later version.
*
* smarthomatic is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
* Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with smarthomatic. If not, see <http://www.gnu.org/licenses/>.
*
* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
* ! WARNING: This file is generated by the SHC EEPROM editor and should !
* ! never be modified manually.                                         !
* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

#ifndef _PACKET_HEADER_H
#define _PACKET_HEADER_H

#include "util.h"
#include "e2p_access.h"

// Header size in bits (incl. header extension), set depending on used
// MessageType and used for calculating message data offsets.
uint8_t __HEADEROFFSETBITS;

// Packet size in bytes including padding, set depending on MessageType,
// MessageGroupID and MessageID and used for CRC32 calculation.
uint8_t __PACKETSIZEBYTES;

// Set CRC32 (UIntValue)
// Offset: 0, 0, length bits 32, min val 0, max val 4294967295
static inline void pkg_header_set_crc32(uint32_t val)
{
  array_write_UIntValue(0, 0, 32, val, bufx);
}

// Set SenderID (UIntValue)
// Offset: 4, 0, length bits 12, min val 0, max val 4095
static inline void pkg_header_set_senderid(uint32_t val)
{
  array_write_UIntValue(4, 0, 12, val, bufx);
}

// Set PacketCounter (UIntValue)
// Offset: 5, 4, length bits 24, min val 0, max val 16777215
static inline void pkg_header_set_packetcounter(uint32_t val)
{
  array_write_UIntValue(5, 4, 24, val, bufx);
}

// ENUM MessageType
typedef enum {
  MESSAGETYPE_GET = 0,
  MESSAGETYPE_SET = 1,
  MESSAGETYPE_SETGET = 2,
  MESSAGETYPE_STATUS = 8,
  MESSAGETYPE_ACK = 9,
  MESSAGETYPE_ACKSTATUS = 10
} MessageTypeEnum;

// Set MessageType (EnumValue)
// Offset: 8, 4, length bits 4
static inline void pkg_header_set_messagetype(MessageTypeEnum val)
{
  array_write_UIntValue(8, 4, 4, val, bufx);
}


// overall length: 72 bits

// Function to set CRC value after all data fields are set.
static inline void pkg_header_calc_crc32(void)
{
  pkg_header_set_crc32(crc32(bufx + 4, __PACKETSIZEBYTES - 4));
}

#endif /* _PACKET_HEADER_H */
