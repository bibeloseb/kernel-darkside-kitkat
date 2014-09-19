/*******************************************************************************
 *
 * Filename:
 * ---------
 * audio_gain_table_default.h
 *
 * Project:
 * --------
 *   ALPS
 *
 * Description:
 * ------------
 * This file is the header of audio cgain table parameters
 *
 * Author:
 * -------
 * ChiPeng Chang
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:$
 * $Modtime:$
 * $Log:$
 * 
 * 08 28 2012 weiguo.li
 * [ALPS00347285] [Need Patch] [Volunteer Patch]LGE AudioGainTable modification
 * .
 * 
 * 08 26 2012 weiguo.li
 * [ALPS00347285] [Need Patch] [Volunteer Patch]LGE AudioGainTable modification
 * .
 * 
 * 07 29 2012 weiguo.li
 * [ALPS00319405] ALPS.JB.BSP.PRA check in CR for Jades
 * .
 *
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef AUDIO_GAIN_TABLE_DEFAULT_H
#define AUDIO_GAIN_TABLE_DEFAULT_H

// Receiver  Gain
// Headset   Gain
// Speaker   Gain
#define DEFAULT_VOICE_GAIN_TABLE_PARA \
    0xFF,0x0A000000,      0x64,0x0A000000,      0x50,0x0A000000,      0x3C,0x0A000000,      0x28,0x0A000000,\
    0x14,0x0A000000,      0x00,0x0A000000,      0x00,0x0B000000,      0x48,0x08000000,      0x50,0x08000000,\
    0x58,0x09000000,      0x60,0x0A000000,      0x68,0x0B000000,      0x70,0x08000000,      0x78,0x08000000,\
    0x80,0x09000000,      0x88,0x0A000000,      0x90,0x0B000000,      0x98,0x08000000,      0xA0,0x08000000,\
    \
    0xFF,0x0A006400,      0x64,0x0A006400,      0x50,0x0A006400,      0x3C,0x0A006400,      0x28,0x0A006400,\
    0x14,0x0A006400,      0x00,0x0A006400,      0x00,0x07000000,      0x48,0x08000000,      0x50,0x09000000,\
    0x58,0x0A000000,      0x60,0x0B000000,      0x68,0x07000000,      0x70,0x08000000,      0x78,0x09000000,\
    0x80,0x0A000000,      0x88,0x0B000000,      0x90,0x07000000,      0x98,0x08000000,      0xA0,0x09000000,\
    \
    0xFF,0x0C4F8000,      0x64,0x0C4F8000,      0x50,0x0C4F8000,      0x3C,0x0C4F8000,      0x28,0x0C4F8000,\
    0x14,0x0C4F8000,      0x00,0x0C4F8000,      0x00,0x08000000,      0x48,0x09000000,      0x50,0x0A000000,\
    0x58,0x0B000000,      0x60,0x07000000,      0x68,0x08000000,      0x70,0x09000000,      0x78,0x0A000000,\
    0x80,0x0B000000,      0x88,0x07000000,      0x90,0x08000000,      0x98,0x09000000,      0xA0,0x0A000000 
// Receiver  Gain
// Headset   Gain
// Speaker   Gain
#define DEFAULT_SYSTEM_GAIN_TABLE_PARA \
    0xF2,0x08000000,      0xC2,0x09000000,      0xA2,0x0A000000,      0x92,0x0B000000,      0x62,0x07000000,\
    0x32,0x08000000,      0x00,0x09000000,      0x00,0x0A000000,      0x48,0x0B000000,      0x50,0x07000000,\
    0x58,0x08000000,      0x60,0x09000000,      0x68,0x0A000000,      0x70,0x0B000000,      0x78,0x07000000,\
    0x80,0x08000000,      0x88,0x09000000,      0x90,0x0A000000,      0x98,0x0B000000,      0xA0,0x07000000,\
    \
    0xFF,0x0C406400,      0x78,0x0C406400,      0x64,0x0C406400,      0x50,0x0C406400,      0x3C,0x0C406400,\
    0x28,0x0C406400,      0x14,0x0C406400,      0x00,0x0C406400,      0x48,0x08000000,      0x50,0x09000000,\
    0x58,0x0A000000,      0x60,0x0B000000,      0x68,0x07000000,      0x70,0x08000000,      0x78,0x09000000,\
    0x80,0x0A000000,      0x88,0x0B000000,      0x90,0x07000000,      0x98,0x08000000,      0xA0,0x09000000,\
    \
    0xFF,0x0C4F0000,      0x78,0x0C4F0000,      0x64,0x0C4F0000,      0x50,0x0C4F0000,      0x3C,0x0C4F0000,\
    0x28,0x0C4F0000,      0x14,0x0C4F0000,      0x00,0x0C4F0000,      0x48,0x09000000,      0x50,0x0A000000,\
    0x58,0x0B000000,      0x60,0x0B000000,      0x68,0x0C000000,      0x70,0x09000000,      0x78,0x0A000000,\
    0x80,0x0B000000,      0x88,0x0B000000,      0x90,0x0C000000,      0x98,0x09000000,      0xA0,0x0A000000    
// Receiver  Gain
// Headset   Gain
// Speaker   Gain
#define DEFAULT_RINGTONE_GAIN_TABLE_PARA \
    0xF2,0x08000000,      0xC2,0x09000000,      0xA2,0x0A000000,      0x92,0x0B000000,      0x62,0x07000000,\
    0x32,0x08000000,      0x00,0x09000000,      0x00,0x0A000000,      0x48,0x0B000000,      0x50,0x07000000,\
    0x58,0x08000000,      0x60,0x09000000,      0x68,0x0A000000,      0x70,0x0B000000,      0x78,0x07000000,\
    0x80,0x08000000,      0x88,0x09000000,      0x90,0x0A000000,      0x98,0x0B000000,      0xA0,0x07000000,\
    \
    0xFF,0x0C406400,      0x78,0x0C406400,      0x64,0x0C406400,      0x50,0x0C406400,      0x3C,0x0C406400,\
    0x28,0x0C406400,      0x14,0x0C406400,      0x00,0x0C406400,      0x48,0x08000000,      0x50,0x09000000,\
    0x58,0x0A000000,      0x60,0x0B000000,      0x68,0x07000000,      0x70,0x08000000,      0x78,0x09000000,\
    0x80,0x0A000000,      0x88,0x0B000000,      0x90,0x07000000,      0x98,0x08000000,      0xA0,0x09000000,\
    \
    0xFF,0x0C4F0000,      0x78,0x0C4F0000,      0x64,0x0C4F0000,      0x50,0x0C4F0000,      0x3C,0x0C4F0000,\
    0x28,0x0C4F0000,      0x14,0x0C4F0000,      0x00,0x0C4F0000,      0x48,0x09000000,      0x50,0x0A000000,\
    0x58,0x0B000000,      0x60,0x0B000000,      0x68,0x0C000000,      0x70,0x09000000,      0x78,0x0A000000,\
    0x80,0x0B000000,      0x88,0x0B000000,      0x90,0x0C000000,      0x98,0x09000000,      0xA0,0x0A000000
// Receiver  Gain
// Headset   Gain
// Speaker   Gain
#define DEFAULT_MUSIC_GAIN_TABLE_PARA \
    0xFF,0x07000000,      0xF4,0x08000000,      0xE8,0x09000000,      0xD8,0x0A000000,      0xC8,0x0B000000,\
    0xB8,0x07000000,      0x98,0x08000000,      0x78,0x09000000,      0x58,0x0A000000,      0x48,0x0B000000,\
    0x38,0x07000000,      0x28,0x08000000,      0x18,0x09000000,      0x00,0x0A000000,      0x78,0x0B000000,\
    0x80,0x07000000,      0x88,0x08000000,      0x90,0x09000000,      0x98,0x0A000000,      0xA0,0x0B000000,\
    \
    0xFF,0x0C406400,      0xA8,0x0C406400,      0x9C,0x0C406400,      0x90,0x0C406400,      0x84,0x0C406400,\
    0x78,0x0C406400,      0x6C,0x0C406400,      0x60,0x0C406400,      0x54,0x0C406400,      0x48,0x0C406400,\
    0x3C,0x0C406400,      0x30,0x0C406400,      0x24,0x0C406400,      0x18,0x0C406400,      0x0C,0x0C406400,\
    0x00,0x0C406400,      0x88,0x08000000,      0x90,0x09000000,      0x98,0x0A000000,      0xA0,0x0B000000,\
    \
    0xFF,0x0C4F0000,      0xA8,0x0C4F0000,      0x9C,0x0C4F0000,      0x90,0x0C4F0000,      0x84,0x0C4F0000,\
    0x78,0x0C4F0000,      0x6C,0x0C4F0000,      0x60,0x0C4F0000,      0x54,0x0C4F0000,      0x48,0x0C4F0000,\
    0x3C,0x0C4F0000,      0x30,0x0C4F0000,      0x24,0x0C4F0000,      0x18,0x0C4F0000,      0x0C,0x0C4F0000,\
    0x00,0x0C4F0000,      0x88,0x09000000,      0x90,0x0A000000,      0x98,0x0B000000,      0xA0,0x07000000    
// Receiver  Gain
// Headset   Gain
// Speaker   Gain
#define DEFAULT_ALARM_GAIN_TABLE_PARA \
    0xF2,0x08000000,      0xC2,0x09000000,      0xA2,0x0A000000,      0x92,0x0B000000,      0x62,0x07000000,\
    0x32,0x08000000,      0x00,0x09000000,      0x00,0x0A000000,      0x48,0x0B000000,      0x50,0x07000000,\
    0x58,0x08000000,      0x60,0x09000000,      0x68,0x0A000000,      0x70,0x0B000000,      0x78,0x07000000,\
    0x80,0x08000000,      0x88,0x09000000,      0x90,0x0A000000,      0x98,0x0B000000,      0xA0,0x07000000,\
    \
    0xFF,0x0C406400,      0x78,0x0C406400,      0x64,0x0C406400,      0x50,0x0C406400,      0x3C,0x0C406400,\
    0x28,0x0C406400,      0x14,0x0C406400,      0x00,0x0C406400,      0x48,0x08000000,      0x50,0x09000000,\
    0x58,0x0A000000,      0x60,0x0B000000,      0x68,0x07000000,      0x70,0x08000000,      0x78,0x09000000,\
    0x80,0x0A000000,      0x88,0x0B000000,      0x90,0x07000000,      0x98,0x08000000,      0xA0,0x09000000,\
    \
    0xFF,0x0C4F0000,      0x78,0x0C4F0000,      0x64,0x0C4F0000,      0x50,0x0C4F0000,      0x3C,0x0C4F0000,\
    0x28,0x0C4F0000,      0x14,0x0C4F0000,      0x00,0x0C4F0000,      0x48,0x09000000,      0x50,0x0A000000,\
    0x58,0x0B000000,      0x60,0x0B000000,      0x68,0x0C000000,      0x70,0x09000000,      0x78,0x0A000000,\
    0x80,0x0B000000,      0x88,0x0B000000,      0x90,0x0C000000,      0x98,0x09000000,      0xA0,0x0A000000
// Receiver  Gain
// Headset   Gain
// Speaker   Gain
#define DEFAULT_NOTIFICATION_GAIN_TABLE_PARA \
    0xF2,0x08000000,      0xC2,0x09000000,      0xA2,0x0A000000,      0x92,0x0B000000,      0x62,0x07000000,\
    0x32,0x08000000,      0x00,0x09000000,      0x00,0x0A000000,      0x48,0x0B000000,      0x50,0x07000000,\
    0x58,0x08000000,      0x60,0x09000000,      0x68,0x0A000000,      0x70,0x0B000000,      0x78,0x07000000,\
    0x80,0x08000000,      0x88,0x09000000,      0x90,0x0A000000,      0x98,0x0B000000,      0xA0,0x07000000,\
    \
    0xFF,0x0C406400,      0x78,0x0C406400,      0x64,0x0C406400,      0x50,0x0C406400,      0x3C,0x0C406400,\
    0x28,0x0C406400,      0x14,0x0C406400,      0x00,0x0C406400,      0x48,0x08000000,      0x50,0x09000000,\
    0x58,0x0A000000,      0x60,0x0B000000,      0x68,0x07000000,      0x70,0x08000000,      0x78,0x09000000,\
    0x80,0x0A000000,      0x88,0x0B000000,      0x90,0x07000000,      0x98,0x08000000,      0xA0,0x09000000,\
    \
    0xFF,0x0C4F0000,      0x78,0x0C4F0000,      0x64,0x0C4F0000,      0x50,0x0C4F0000,      0x3C,0x0C4F0000,\
    0x28,0x0C4F0000,      0x14,0x0C4F0000,      0x00,0x0C4F0000,      0x48,0x09000000,      0x50,0x0A000000,\
    0x58,0x0B000000,      0x60,0x0B000000,      0x68,0x0C000000,      0x70,0x09000000,      0x78,0x0A000000,\
    0x80,0x0B000000,      0x88,0x0B000000,      0x90,0x0C000000,      0x98,0x09000000,      0xA0,0x0A000000
// Receiver  Gain
// Headset   Gain
// Speaker   Gain
#define DEFAULT_BLUETOOTH_SCO_GAIN_TABLE_PARA \
    0xFF,0x0A000000,      0xEF,0x0B000000,      0xDF,0x07000000,      0xCC,0x08000000,      0xBC,0x09000000,\
    0xAC,0x0A000000,      0x9C,0x0B000000,      0x8C,0x07000000,      0x7C,0x08000000,      0x6C,0x09000000,\
    0x5C,0x0A000000,      0x4C,0x0B000000,      0x3C,0x07000000,      0x2C,0x08000000,      0x1C,0x09000000,\
    0x00,0x0A000000,      0x88,0x0B000000,      0x90,0x07000000,      0x98,0x08000000,      0xA0,0x09000000,\
    \
    0xFF,0x0C406400,      0xA8,0x0C406400,      0x9C,0x0C406400,      0x90,0x0C406400,      0x84,0x0C406400,\
    0x78,0x0C406400,      0x6C,0x0C406400,      0x60,0x0C406400,      0x54,0x0C406400,      0x48,0x0C406400,\
    0x3C,0x0C406400,      0x30,0x0C406400,      0x24,0x0C406400,      0x18,0x0C406400,      0x0C,0x0C406400,\
    0x00,0x0C406400,      0x88,0x0B000000,      0x90,0x07000000,      0x98,0x08000000,      0xA0,0x09000000,\
    \
    0xFF,0x0C4F0000,      0xA8,0x0C4F0000,      0x9C,0x0C4F0000,      0x90,0x0C4F0000,      0x84,0x0C4F0000,\
    0x78,0x0C4F0000,      0x6C,0x0C4F0000,      0x60,0x0C4F0000,      0x54,0x0C4F0000,      0x48,0x0C4F0000,\
    0x3C,0x0C4F0000,      0x30,0x0C4F0000,      0x24,0x0C4F0000,      0x18,0x0C4F0000,      0x0C,0x0C4F0000,\
    0x00,0x0C4F0000,      0x88,0x07000000,      0x90,0x08000000,      0x98,0x09000000,      0xA0,0x0A000000    
// Receiver  Gain
// Headset   Gain
// Speaker   Gain
#define DEFAULT_ENFORCEAUDIBLE_GAIN_TABLE_PARA \
    0xF2,0x08000000,      0xC2,0x09000000,      0xA2,0x0A000000,      0x92,0x0B000000,      0x62,0x07000000,\
    0x32,0x08000000,      0x00,0x09000000,      0x00,0x0A000000,      0x48,0x0B000000,      0x50,0x07000000,\
    0x58,0x08000000,      0x60,0x09000000,      0x68,0x0A000000,      0x70,0x0B000000,      0x78,0x07000000,\
    0x80,0x08000000,      0x88,0x09000000,      0x90,0x0A000000,      0x98,0x0B000000,      0xA0,0x07000000,\
    \
    0xFF,0x0C406400,      0x8C,0x0C406400,      0x78,0x0C406400,      0x64,0x0C406400,      0x50,0x0C406400,\
    0x3C,0x0C406400,      0x28,0x0C406400,      0x14,0x0C406400,      0x48,0x08000000,      0x50,0x09000000,\
    0x58,0x0A000000,      0x60,0x0B000000,      0x68,0x07000000,      0x70,0x08000000,      0x78,0x09000000,\
    0x80,0x0A000000,      0x88,0x0B000000,      0x90,0x07000000,      0x98,0x08000000,      0xA0,0x09000000,\
    \
    0xFF,0x0C4F0000,      0x78,0x0C4F0000,      0x64,0x0C4F0000,      0x50,0x0C4F0000,      0x3C,0x0C4F6720,\
    0x28,0x0C4F0000,      0x14,0x0C4F0000,      0x00,0x0C4F0000,      0x48,0x09000000,      0x50,0x0A000000,\
    0x58,0x0B000000,      0x60,0x0B000000,      0x68,0x0C000000,      0x70,0x09000000,      0x78,0x0A000000,\
    0x80,0x0B000000,      0x88,0x0B000000,      0x90,0x0C000000,      0x98,0x09000000,      0xA0,0x0A000000    
// Receiver  Gain
// Headset Gain
// Speaker Gain
#define DEFAULT_DTMF_GAIN_TABLE_PARA \
    0xF8,0x0A000000,      0xE8,0x0B000000,      0xD8,0x07000000,      0xC8,0x08000000,      0xB8,0x09000000,\
    0xA8,0x0A000000,      0x98,0x0B000000,      0x88,0x07000000,      0x78,0x08000000,      0x68,0x09000000,\
    0x58,0x0A000000,      0x48,0x0B000000,      0x38,0x07000000,      0x28,0x08000000,      0x18,0x09000000,\
    0x00,0x0A000000,      0xFF,0x0B000000,      0x90,0x07000000,      0x98,0x08000000,      0xA0,0x09000000,\
    \
    0xFF,0x0C406400,      0xA8,0x0C406400,      0x9C,0x0C406400,      0x90,0x0C406400,      0x84,0x0C406400,\
    0x78,0x0C406400,      0x6C,0x0C406400,      0x60,0x0C406400,      0x54,0x0C406400,      0x48,0x0C406400,\
    0x3C,0x0C406400,      0x30,0x0C406400,      0x24,0x0C406400,      0x18,0x0C406400,      0x0C,0x0C406400,\
    0x00,0x0C406400,      0xFF,0x0B000000,      0x90,0x07000000,      0x98,0x08000000,      0xA0,0x09000000,\
    \
    0xFF,0x0C4F0000,      0xA8,0x0C4F0000,      0x9C,0x0C4F0000,      0x90,0x0C4F0000,      0x84,0x0C4F0000,\
    0x78,0x0C4F0000,      0x6C,0x0C4F0000,      0x60,0x0C4F0000,      0x54,0x0C4F0000,      0x48,0x0C4F0000,\
    0x3C,0x0C4F0000,      0x30,0x0C4F0000,      0x24,0x0C4F0000,      0x18,0x0C4F0000,      0x0C,0x0C4F0000,\
    0x00,0x0C4F0000,      0xFF,0x0B000000,      0x90,0x07000000,      0x98,0x08000000,      0xA0,0x09000000    
// Receiver  Gain
// Headset Gain
// Speaker Gain
#define DEFAULT_TTS_GAIN_TABLE_PARA \
    0xF8,0x0A000000,      0xE8,0x0B000000,      0xD8,0x07000000,      0xC8,0x08000000,      0xB8,0x09000000,\
    0xA8,0x0A000000,      0x98,0x0B000000,      0x88,0x07000000,      0x78,0x08000000,      0x68,0x09000000,\
    0x58,0x0A000000,      0x48,0x0B000000,      0x38,0x07000000,      0x28,0x08000000,      0x18,0x09000000,\
    0x00,0x0A000000,      0xFF,0x0B000000,      0x90,0x07000000,      0x98,0x08000000,      0xA0,0x09000000,\
    \
    0xFF,0x0C406400,      0xA8,0x0C406400,      0x9C,0x0C406400,      0x90,0x0C406400,      0x84,0x0C406400,\
    0x78,0x0C406400,      0x6C,0x0C406400,      0x60,0x0C406400,      0x54,0x0C406400,      0x48,0x0C406400,\
    0x3C,0x0C406400,      0x30,0x0C406400,      0x24,0x0C406400,      0x18,0x0C406400,      0x0C,0x0C406400,\
    0x00,0x0C406400,      0xFF,0x0B000000,      0x90,0x07000000,      0x98,0x08000000,      0xA0,0x09000000,\
    \
    0xFF,0x0C4F0000,      0xA8,0x0C4F0000,      0x9C,0x0C4F0000,      0x90,0x0C4F0000,      0x84,0x0C4F0000,\
    0x78,0x0C4F0000,      0x6C,0x0C4F0000,      0x60,0x0C4F0000,      0x54,0x0C4F0000,      0x48,0x0C4F0000,\
    0x3C,0x0C4F0000,      0x30,0x0C4F0000,      0x24,0x0C4F0000,      0x18,0x0C4F0000,      0x0C,0x0C4F0000,\
    0x00,0x0C4F0000,      0xFF,0x0B000000,      0x90,0x07000000,      0x98,0x08000000,      0xA0,0x09000000    
// Receiver  Gain
// Headset Gain
// Speaker Gain
#define DEFAULT_FM_GAIN_TABLE_PARA \
    0xFF,0x0A000000,      0x00,0x0B000000,      0x00,0x07000000,      0x00,0x08000000,      0x00,0x09000000,\
    0x00,0x0A000000,      0x00,0x0B000000,      0x00,0x07000000,      0x00,0x08000000,      0x00,0x09000000,\
    0x00,0x0A000000,      0x00,0x0B000000,      0x00,0x07000000,      0x00,0x08000000,      0x00,0x09000000,\
    0x00,0x0A000000,      0x00,0x0B000000,      0x00,0x07000000,      0x00,0x08000000,      0x00,0x09000000,\
    \
    0xFF,0x0C406400,      0x00,0x0C406400,      0x00,0x0C406400,      0x00,0x0C406400,      0x00,0x0C406400,\
    0x00,0x0C406400,      0x00,0x0C406400,      0x00,0x0C406400,      0x00,0x0C406400,      0x00,0x0C406400,\
    0x00,0x0C406400,      0x00,0x0C406400,      0x00,0x0C406400,      0x00,0x0C406400,      0x00,0x0C406400,\
    0x00,0x0C406400,      0x00,0x08000000,      0x00,0x09000000,      0x00,0x0A000000,      0x00,0x0B000000,\
    \
    0xFF,0x0C4F0000,      0x00,0x0C4F0000,      0x00,0x0C4F0000,      0x00,0x0C4F0000,      0x00,0x0C4F0000,\
    0x00,0x0C4F0000,      0x00,0x0C4F0000,      0x00,0x0C4F0000,      0x00,0x0C4F0000,      0x00,0x0C4F0000,\
    0x00,0x0C4F0000,      0x00,0x0C4F0000,      0x00,0x0C4F0000,      0x00,0x0C4F0000,      0x00,0x0C4F0000,\
    0x00,0x0C4F0000,      0x00,0x09000000,      0x00,0x0A000000,      0x00,0x0B000000,      0x00,0x07000000    
//IDLE_RECORD_MIC 
//IDLE_RECORD_HeadSet
//INCALL_RECEIVER
//INCALL_HEADSET    
//INCALL_SPEAKER
//VOIP_RECEIVER
//VOIP_HEADSET
//VOIP_SPEAKER
//FM_RECORDING
//TTY_DEVICE
//VOICE_RECOGNITION
#define DEFAULT_MICROPHONE_GAIN_TABLE_PARA \
    0x39,	0x39,	0x27,	0x20,\
    0x1D,	0x29,	0x20,	0x1D,\
    0x02,	0x24,	0x24,	0x27,\
    0x20,	0x1D,	0x04,	0x00,\
    0x00,	0x00,	0x00,	0x00
//SIDETONE_RECEIVER
//SIDETONE_HEADSET
//SIDETONE_SPEAKER
#define DEFAULT_SIDETONE_GAIN_TABLE_PARA \
	0x00,	0x00,	0x00,	0x00, \
	0x00,	0x00,	0x00,	0x00, \
	0x00,	0x00,	0x00,	0x00, \
	0x00,	0x00,	0x00,	0x00, \
	0x00,	0x00,	0x00,	0x00
// Receiver Gain
// Headset Gain
// Speaker Gain
#define DEFAULT_SPEECH_GAIN_TABLE_PARA \
    0x00,0x1F000000,      0x00,0x1B000000,      0x00,0x17000000,      0x00,0x13000000,      0x00,0x0F000000,\
    0x00,0x0B000000,      0x03,0x06000000,      0x03,0x0A000000,      0x02,0x0B000000,      0x01,0x07000000,\
    0x0A,0x0C000000,      0x09,0x09000000,      0x08,0x0A000000,      0x07,0x0B000000,      0x06,0x07000000,\
    0x05,0x0C000000,      0x04,0x09000000,      0x03,0x0A000000,      0x02,0x0B000000,      0x01,0x07000000,\
    \
    0x00,0x1A106800,      0x00,0x17106800,      0x00,0x14106800,      0x00,0x11106800,      0x00,0x0E106800,\
    0x00,0x0B106800,      0x00,0x08106800,      0x03,0x0A000000,      0x02,0x0B000000,      0x01,0x07000000,\
    0x0A,0x0C000000,      0x09,0x0D000000,      0x08,0x0A000000,      0x07,0x0B000000,      0x06,0x07000000,\
    0x05,0x0C000000,      0x04,0x0D000000,      0x03,0x0A000000,      0x02,0x0B000000,      0x01,0x07000000,\
    \
    0x00,0x1C2F8000,      0x00,0x192F8000,      0x00,0x162F8000,      0x00,0x132F8000,      0x00,0x102F8000,\
    0x00,0x0D2F8000,      0x00,0x0A2F8000,      0x07,0x0A000000,      0x02,0x0B000000,      0x01,0x07000000,\
    0x0A,0x08000000,      0x09,0x09000000,      0x08,0x0A000000,      0x07,0x0B000000,      0x06,0x07000000,\
    0x05,0x08000000,      0x04,0x09000000,      0x07,0x0A000000,      0x02,0x0B000000,      0x01,0x07000000
// Receiver Gain
// Headset Gain
// Speaker Gain
#define DEFAULT_SPEECH_WB_GAIN_TABLE_PARA \
    0x00,0x1F000000,      0x00,0x1B000000,      0x00,0x17000000,      0x00,0x13000000,      0x00,0x0F000000,\
    0x00,0x0B000000,      0x03,0x06000000,      0x03,0x0A000000,      0x02,0x0B000000,      0x01,0x07000000,\
    0x0A,0x0C000000,      0x09,0x09000000,      0x08,0x0A000000,      0x07,0x0B000000,      0x06,0x07000000,\
    0x05,0x0C000000,      0x04,0x09000000,      0x03,0x0A000000,      0x02,0x0B000000,      0x01,0x07000000,\
    \
    0x00,0x1A106800,      0x00,0x17106800,      0x00,0x14106800,      0x00,0x11106800,      0x00,0x0E106800,\
    0x00,0x0B106800,      0x00,0x08106800,      0x03,0x0A000000,      0x02,0x0B000000,      0x01,0x07000000,\
    0x0A,0x0C000000,      0x09,0x0D000000,      0x08,0x0A000000,      0x07,0x0B000000,      0x06,0x07000000,\
    0x05,0x0C000000,      0x04,0x0D000000,      0x03,0x0A000000,      0x02,0x0B000000,      0x01,0x07000000,\
    \
    0x00,0x1C2F8000,      0x00,0x192F8000,      0x00,0x162F8000,      0x00,0x132F8000,      0x00,0x102F8000,\
    0x00,0x0D2F8000,      0x00,0x0A2F8000,      0x07,0x0A000000,      0x02,0x0B000000,      0x01,0x07000000,\
    0x0A,0x08000000,      0x09,0x09000000,      0x08,0x0A000000,      0x07,0x0B000000,      0x06,0x07000000,\
    0x05,0x08000000,      0x04,0x09000000,      0x07,0x0A000000,      0x02,0x0B000000,      0x01,0x07000000
#endif
