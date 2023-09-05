/* Copyright 2023 Dual Tachyon
 * https://github.com/DualTachyon
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */

#ifndef MISC_H
#define MISC_H

#include <stdbool.h>
#include <stdint.h>

#define IS_MR_CHANNEL(x) ((x) >= MR_CHANNEL_FIRST && (x) <= MR_CHANNEL_LAST)
#define IS_FREQ_CHANNEL(x) ((x) >= FREQ_CHANNEL_FIRST && (x) <= FREQ_CHANNEL_LAST)
#define IS_NOAA_CHANNEL(x) ((x) >= NOAA_CHANNEL_FIRST && (x) <= NOAA_CHANNEL_LAST)
#define IS_NOT_NOAA_CHANNEL(x) ((x) >= MR_CHANNEL_FIRST && (x) <= FREQ_CHANNEL_LAST)
#define IS_VALID_CHANNEL(x) ((x) <= NOAA_CHANNEL_LAST)

enum {
	MR_CHANNEL_FIRST = 0U,
	MR_CHANNEL_LAST = 199U,
	FREQ_CHANNEL_FIRST = 200U,
	FREQ_CHANNEL_LAST = 206U,
	NOAA_CHANNEL_FIRST = 207U,
	NOAA_CHANNEL_LAST = 216U,
};

enum {
	FLASHLIGHT_OFF = 0U,
	FLASHLIGHT_ON = 1U,
	FLASHLIGHT_BLINK = 2U,
};

enum {
	VFO_CONFIGURE_0 = 0U,
	VFO_CONFIGURE_1 = 1U,
	VFO_CONFIGURE_RELOAD = 2U,
};

enum AlarmState_t {
	ALARM_STATE_OFF     = 0U,
	ALARM_STATE_TXALARM = 1U,
	ALARM_STATE_ALARM   = 2U,
	ALARM_STATE_TX1750  = 3U,
};

typedef enum AlarmState_t AlarmState_t;

enum ReceptionMode_t {
	RX_MODE_NONE      = 0U,
	RX_MODE_DETECTED  = 1U,
	RX_MODE_LISTENING = 2U,
};

typedef enum ReceptionMode_t ReceptionMode_t;

enum CssScanMode_t {
	CSS_SCAN_MODE_OFF      = 0U,
	CSS_SCAN_MODE_SCANNING = 1U,
	CSS_SCAN_MODE_FOUND    = 2U,
};

typedef enum CssScanMode_t CssScanMode_t;

extern const uint32_t *gUpperLimitFrequencyBandTable;
extern const uint32_t *gLowerLimitFrequencyBandTable;

extern bool gSetting_350TX;
extern bool gSetting_KILLED;
extern bool gSetting_200TX;
extern bool gSetting_500TX;
extern bool gSetting_350EN;
extern uint8_t gSetting_F_LOCK;
extern bool gSetting_ScrambleEnable;
extern uint8_t gSetting_F_LOCK;

extern const uint32_t gDefaultAesKey[4];
extern uint32_t gCustomAesKey[4];
extern bool bHasCustomAesKey;
extern uint32_t gChallenge[4];
extern uint8_t gTryCount;

extern uint8_t gEEPROM_1EC0_0[8];
extern uint8_t gEEPROM_1EC0_1[8];
extern uint8_t gEEPROM_1EC0_2[8];
extern uint8_t gEEPROM_1EC0_3[8];

extern uint16_t gEEPROM_RSSI_CALIB[3][4];

extern uint16_t gEEPROM_1F8A;
extern uint16_t gEEPROM_1F8C;

extern uint8_t gMR_ChannelAttributes[207];

extern volatile bool gNextTimeslice500ms;
extern volatile uint16_t gBatterySaveCountdown;
extern volatile uint16_t gDualWatchCountdown;
extern volatile uint16_t gTxTimerCountdown;
extern volatile uint16_t g_20000342;
extern volatile uint16_t gFmPlayCountdown;
extern volatile uint16_t gNOAA_Countdown;
extern bool gEnableSpeaker;
extern uint8_t gKeyLockCountdown;
extern uint8_t gRTTECountdown;
extern bool bIsInLockScreen;
extern uint8_t gUpdateStatus;
extern uint8_t gFoundCTCSS;
extern uint8_t gFoundCDCSS;
extern bool gEndOfRxDetectedMaybe;
extern uint8_t gVFO_RSSI_Level[2];
extern uint8_t gReducedService;
extern uint8_t gBatteryVoltageIndex;
extern CssScanMode_t gCssScanMode;
extern bool gUpdateRSSI;
extern AlarmState_t gAlarmState;
extern uint16_t g_2000038E;
extern uint8_t g_20000393;
extern bool gPttWasReleased;
extern bool gPttWasPressed;
extern bool gFlagReconfigureVfos;
extern uint8_t gVfoConfigureMode;
extern bool gFlagResetVfos;
extern bool gRequestSaveVFO;
extern uint8_t gRequestSaveChannel;
extern bool gRequestSaveSettings;
extern bool gRequestSaveFM;
extern uint8_t gKeypadLocked;
extern uint8_t g_200003A0;
extern bool gFlagAcceptSetting;
extern bool gFlagRefreshSetting;
extern bool gFlagSaveVfo;
extern bool gFlagSaveSettings;
extern bool gFlagSaveChannel;
extern bool gFlagSaveFM;
extern uint8_t gDTMF_RequestPending;
extern bool g_CDCSS_Lost;
extern uint8_t gCDCSSCodeType;
extern bool g_CTCSS_Lost;
extern bool g_CxCSS_TAIL_Found;
extern bool g_VOX_Lost;
extern bool g_SquelchLost;
extern uint8_t gFlashLightState;
extern bool gVOX_NoiseDetected;
extern uint16_t g_200003B6;
extern uint16_t gVoxPauseCountdown;
extern volatile uint16_t gFlashLightBlinkCounter;
extern bool gFlagEndTransmission;
extern uint16_t gLowBatteryCountdown;
extern uint8_t gNextMrChannel;
extern ReceptionMode_t gRxReceptionMode;
extern uint8_t gRestoreMrChannel;
extern uint8_t gCurrentScanList;
extern uint8_t gPreviousMrChannel;
extern uint32_t gRestoreFrequency;
extern uint8_t gRxVfoIsActive;
extern uint8_t gAlarmToneCounter;
extern uint16_t gAlarmRunningCounter;
extern bool gKeyBeingHeld;
extern bool gPttIsPressed;
extern uint8_t gPttDebounceCounter;
extern uint8_t gMenuListCount;
extern uint8_t gBackupCROSS_BAND_RX_TX;
extern uint8_t gScanDelay;
extern uint8_t gAircopySendCountdown;
extern uint8_t gFSKWriteIndex;
extern uint8_t gNeverUsed;

extern bool gIsNoaaMode;
extern volatile bool gNextTimeslice;
extern uint8_t gNoaaChannel;
extern bool gUpdateDisplay;
extern uint8_t gFM_ChannelPosition;
extern bool gF_LOCK;
extern uint8_t gShowChPrefix;
extern volatile uint16_t gSystickCountdown2;
extern volatile uint8_t gFoundCDCSSCountdown;
extern volatile uint8_t gFoundCTCSSCountdown;
extern volatile uint16_t gVoxStopCountdown;
extern volatile bool gTxTimeoutReached;
extern volatile bool gNextTimeslice40ms;
extern volatile bool gSchedulePowerSave;
extern volatile bool gBatterySaveCountdownExpired;
extern volatile bool gScheduleDualWatch;
extern volatile bool gScheduleNOAA;
extern volatile bool gSystickFlag10;
extern volatile bool gScheduleFM;

extern uint16_t gCurrentRSSI;

extern uint8_t gIsLocked;

// --------

void NUMBER_Get(char *pDigits, uint32_t *pInteger);
void NUMBER_ToDigits(uint32_t Value, char *pDigits);
uint8_t NUMBER_AddWithWraparound(uint8_t Base, int8_t Add, uint8_t LowerLimit, uint8_t UpperLimit);

#endif

