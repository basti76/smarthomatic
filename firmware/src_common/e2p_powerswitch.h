/*
* This file is part of smarthomatic, http://www.smarthomatic.org.
* Copyright (c) 2013..2014 Uwe Freese
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

#ifndef _E2P_POWERSWITCH_H
#define _E2P_POWERSWITCH_H

// E2P Block "PowerSwitch"
// =======================
// Start offset (bit): 512
// Overall block length: 7680 bits

// SupportedSwitches (UIntValue)
// Description: This is a bit field about the connected switches. (Currently, only one switch is supported and the value has to be 0b00000001, but the value is for future usage.)

// Set SupportedSwitches (UIntValue)
// Byte offset: 64, bit offset: 0, length bits 8, min val 1, max val 1
static inline void e2p_powerswitch_set_supportedswitches(uint8_t val)
{
  eeprom_write_UIntValue(64, 0, 8, val);
}

// Get SupportedSwitches (UIntValue)
// Byte offset: 64, bit offset: 0, length bits 8, min val 1, max val 1
static inline uint8_t e2p_powerswitch_get_supportedswitches(void)
{
  return eeprom_read_UIntValue8(64, 0, 8, 1, 1);
}

// BaseStationPacketCounter (UIntValue)
// Description: This is the last remembered packet counter of a command from the base station. Packets with the same or lower number are ignored.

// Set BaseStationPacketCounter (UIntValue)
// Byte offset: 65, bit offset: 0, length bits 24, min val 0, max val 16777215
static inline void e2p_powerswitch_set_basestationpacketcounter(uint32_t val)
{
  eeprom_write_UIntValue(65, 0, 24, val);
}

// Get BaseStationPacketCounter (UIntValue)
// Byte offset: 65, bit offset: 0, length bits 24, min val 0, max val 16777215
static inline uint32_t e2p_powerswitch_get_basestationpacketcounter(void)
{
  return eeprom_read_UIntValue32(65, 0, 24, 0, 16777215);
}

// SwitchState (BoolValue[8])
// Description: This field stores the last known switch state(s) for eight switches to allow restoring the same state after power loss. It contains also the remaining timeout value. Fill this with zeros when creating a e2p file!

// Set SwitchState (BoolValue)
// Byte offset: 68, bit offset: 0, length bits 8
static inline void e2p_powerswitch_set_switchstate(uint8_t index, bool val)
{
  eeprom_write_UIntValue(68 + (uint16_t)index * 1, 0, 8, val ? 1 : 0);
}

// Get SwitchState (BoolValue)
// Byte offset: 68, bit offset: 0, length bits 8
static inline bool e2p_powerswitch_get_switchstate(uint8_t index)
{
  return eeprom_read_UIntValue8(68 + (uint16_t)index * 1, 0, 8, 0, 1) == 1;
}

// SwitchTimeout (UIntValue[8])
// Description: This field stores the last known switch state(s) for eight switches to allow restoring the same state after power loss. It contains also the remaining timeout value. Fill this with zeros when creating a e2p file!

// Set SwitchTimeout (UIntValue)
// Byte offset: 76, bit offset: 0, length bits 16, min val 0, max val 65767
static inline void e2p_powerswitch_set_switchtimeout(uint8_t index, uint16_t val)
{
  eeprom_write_UIntValue(76 + (uint16_t)index * 2, 0, 16, val);
}

// Get SwitchTimeout (UIntValue)
// Byte offset: 76, bit offset: 0, length bits 16, min val 0, max val 65767
static inline uint16_t e2p_powerswitch_get_switchtimeout(uint8_t index)
{
  return eeprom_read_UIntValue16(76 + (uint16_t)index * 2, 0, 16, 0, 65767);
}

// Reserved area with 7456 bits


#endif /* _E2P_POWERSWITCH_H */
