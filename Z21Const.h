/**
 ** This is Public Domain Software.
 **
 ** The author disclaims copyright to this source code.
 ** In place of a legal notice, here is a blessing:
 **
 **    May you do good and not evil.
 **    May you find forgiveness for yourself and forgive others.
 **    May you share freely, never taking more than you give.
 **/

#ifndef __Z21_CONST_H__
#define __Z21_CONST_H__

class Z21_Broadcast {
public:
    static const uint32_t STATUS_LOCO_TURNOUT           = 0x00000001L;
    static const uint32_t RMBUS_DATACHANGED             = 0x00000002L;
    static const uint32_t SYSTEMSTATE_DATACHANGED       = 0x00000100L;
    static const uint32_t ALL_LOCO_INFO                 = 0x00010000L;
    static const uint32_t LOCONET                       = 0x01000000L;
    static const uint32_t LOCONET_LOCO                  = 0x02000000L;
    static const uint32_t LOCONET_TURNOUT               = 0x04000000L;
    static const uint32_t LOCONET_OCCUPY                = 0x08000000L;
};

class Z21_Status {
public:
    static const uint8_t EMERGENCY_STOP                 = 0x01;
    static const uint8_t TRACK_VOLTAGE_OFF              = 0x02;
    static const uint8_t SHORT_CIRCUIT                  = 0x04;
    static const uint8_t PROGRAMMING_MODE_ACTIVE        = 0x20;
};

class Z21_Status_EX {
public:
    static const uint8_t HIGH_TEMPERATURE               = 0x01;
    static const uint8_t POWER_LOST                     = 0x02;
    static const uint8_t SHORT_CIRCUIT_EXTERNAL         = 0x04;
    static const uint8_t SHORT_CIRCUIT_INTERNAL         = 0x08;
};

class Z21_Decoder_Mode {
public:
    static const uint8_t DCC                      = 0;
    static const uint8_t MM                       = 1;
};

class Z21_Speed_Range {
public:
    static const uint8_t STEPS_14                  = 0x00;
    static const uint8_t STEPS_28                  = 0x02;
    static const uint8_t STEPS_128                 = 0x03;
};

#define        Z21_FUNCTION_BIT(f)                (1L<<(f))
class Z21_Function {
public:
    static const uint8_t F0                       = 0;
    static const uint8_t F1                       = 1;
    static const uint8_t F2                       = 2;
    static const uint8_t F3                       = 3;
    static const uint8_t F4                       = 4;
    static const uint8_t F5                       = 5;
    static const uint8_t F6                       = 6;
    static const uint8_t F7                       = 7;
    static const uint8_t F8                       = 8;
    static const uint8_t F9                       = 9;
    static const uint8_t F10                      = 10;
    static const uint8_t F11                      = 11;
    static const uint8_t F12                      = 12;
    static const uint8_t F13                      = 13;
    static const uint8_t F14                      = 14;
    static const uint8_t F15                      = 15;
    static const uint8_t F16                      = 16;
    static const uint8_t F17                      = 17;
    static const uint8_t F18                      = 18;
    static const uint8_t F19                      = 19;
    static const uint8_t F20                      = 20;
    static const uint8_t F21                      = 21;
    static const uint8_t F22                      = 22;
    static const uint8_t F23                      = 23;
    static const uint8_t F24                      = 24;
    static const uint8_t F25                      = 25;
    static const uint8_t F26                      = 26;
    static const uint8_t F27                      = 27;
    static const uint8_t F28                      = 28;

    static const uint32_t F0_BIT                  = Z21_FUNCTION_BIT(0);
    static const uint32_t F1_BIT                  = Z21_FUNCTION_BIT(1);
    static const uint32_t F2_BIT                  = Z21_FUNCTION_BIT(2);
    static const uint32_t F3_BIT                  = Z21_FUNCTION_BIT(3);
    static const uint32_t F4_BIT                  = Z21_FUNCTION_BIT(4);
    static const uint32_t F5_BIT                  = Z21_FUNCTION_BIT(5);
    static const uint32_t F6_BIT                  = Z21_FUNCTION_BIT(6);
    static const uint32_t F7_BIT                  = Z21_FUNCTION_BIT(7);
    static const uint32_t F8_BIT                  = Z21_FUNCTION_BIT(8);
    static const uint32_t F9_BIT                  = Z21_FUNCTION_BIT(9);
    static const uint32_t F10_BIT                 = Z21_FUNCTION_BIT(10);
    static const uint32_t F11_BIT                 = Z21_FUNCTION_BIT(11);
    static const uint32_t F12_BIT                 = Z21_FUNCTION_BIT(12);
    static const uint32_t F13_BIT                 = Z21_FUNCTION_BIT(13);
    static const uint32_t F14_BIT                 = Z21_FUNCTION_BIT(14);
    static const uint32_t F15_BIT                 = Z21_FUNCTION_BIT(15);
    static const uint32_t F16_BIT                 = Z21_FUNCTION_BIT(16);
    static const uint32_t F17_BIT                 = Z21_FUNCTION_BIT(17);
    static const uint32_t F18_BIT                 = Z21_FUNCTION_BIT(18);
    static const uint32_t F19_BIT                 = Z21_FUNCTION_BIT(19);
    static const uint32_t F20_BIT                 = Z21_FUNCTION_BIT(20);
    static const uint32_t F21_BIT                 = Z21_FUNCTION_BIT(21);
    static const uint32_t F22_BIT                 = Z21_FUNCTION_BIT(22);
    static const uint32_t F23_BIT                 = Z21_FUNCTION_BIT(23);
    static const uint32_t F24_BIT                 = Z21_FUNCTION_BIT(24);
    static const uint32_t F25_BIT                 = Z21_FUNCTION_BIT(25);
    static const uint32_t F26_BIT                 = Z21_FUNCTION_BIT(26);
    static const uint32_t F27_BIT                 = Z21_FUNCTION_BIT(27);
    static const uint32_t F28_BIT                 = Z21_FUNCTION_BIT(28);
};

class Z21_Function_Action {
public:
    static const uint8_t OFF                      = 0x00;
    static const uint8_t ON                       = 0x01;
    static const uint8_t SWITCH                   = 0x02;
};

class Z21_Accessory_Pos {
public:
    static const uint8_t P0                       = 0x00;
    static const uint8_t P1                       = 0x01;
    static const uint8_t ALL                      = 0x02;
};

class Z21_Accessory_State {
public:
    static const uint8_t UNKNOWN                  = 0;
    static const uint8_t P0                       = 1;
    static const uint8_t P1                       = 2;
    static const uint8_t INVALID                  = 3;
};

class Z21_Loconet_Detector {
public:
    // Stationary Interrogate Request
    static const uint8_t REQUEST_STATIONARY     = 0x80;
    static const uint8_t REQUEST_REPORT         = 0x81;
    static const uint8_t REQUEST_REPEATER       = 0x82;

    static const uint8_t REPORT_SENSOR          = 0x01;
    static const uint8_t REPORT_ENTER           = 0x02;
    static const uint8_t REPORT_LEAVE           = 0x03;
    static const uint8_t REPORT_LISSY_LOCO      = 0x10;
    static const uint8_t REPORT_LISSY_OCCUPY    = 0x11;
    static const uint8_t REPORT_LISSY_SPEED     = 0x12;
};

class Z21_LAN {
public:
    static const uint16_t GET_SERIAL_NUMBER       = 0x10;
    static const uint16_t GET_HWINFO              = 0x1A;

    static const uint16_t LOGOFF                  = 0x30;

    static const uint16_t X                       = 0x40;

    static const uint16_t SET_BROADCASTFLAGS      = 0x50;
    static const uint16_t GET_BROADCASTFLAGS      = 0x51;

    static const uint16_t GET_LOCOMODE            = 0x60;
    static const uint16_t SET_LOCOMODE            = 0x61;

    static const uint16_t GET_TURNOUTMODE         = 0x70;
    static const uint16_t SET_TURNOUTMODE         = 0x71;

    static const uint16_t RMBUS_DATACHANGED       = 0x80;
    static const uint16_t RMBUS_GETDATA           = 0x81;
    static const uint16_t RMBUS_PROGRAMMODULE     = 0x82;

    static const uint16_t SYSTEMSTATE_DATACHANGED = 0x84;
    static const uint16_t SYSTEMSTATE_GETDATA     = 0x85;

    static const uint16_t RAILCOM_DATACHANGED     = 0x88;
    static const uint16_t RAILCOM_GETDATA         = 0x89;

    static const uint16_t LOCONET_Z21_RX          = 0xA0;
    static const uint16_t LOCONET_Z21_TX          = 0xA1;
    static const uint16_t LOCONET_FROM_LAN        = 0xA2;
    static const uint16_t LOCONET_DISPATCH_ADDR   = 0xA3;
    static const uint16_t LOCONET_DETECTOR        = 0xA4;
};

class Z21RX_LAN_X {
public:
    static const uint8_t TURNOUT_INFO             = 0x43;
    static const uint8_t BC                       = 0x61;
    static const uint8_t STATUS_CHANGED           = 0x62;
    static const uint8_t GET_VERSION              = 0x63;
    static const uint8_t CV_RESULT                = 0x64;
    static const uint8_t BC_STOPPED               = 0x81;
    static const uint8_t LOCO_INFO                = 0xEF;
    static const uint8_t GET_FIRMWARE_VERSION     = 0xF3;
};

class Z21RX_DB0 {
public:
    static const uint8_t BC_TRACK_POWER_OFF       = 0x00;
    static const uint8_t BC_TRACK_POWER_ON        = 0x01;
    static const uint8_t BC_PROGRAMMING_MODE      = 0x02;
    static const uint8_t BC_TRACK_SHORT_CIRCUIT   = 0x08;
    static const uint8_t CV_NACK_SC               = 0x12;
    static const uint8_t CV_NACK                  = 0x13;
    static const uint8_t UNKNOWN_COMMAND          = 0x82;

    static const uint8_t STATUS_CHANGED           = 0x22;
    static const uint8_t GET_VERSION              = 0x21;
    static const uint8_t CV_RESULT                = 0x14;
    static const uint8_t GET_FIRMWARE_VERSION     = 0x0A;
};

class Z21TX_LAN_X {
public:
    static const uint8_t GET_VERSION                    = 0x21;
    static const uint8_t GET_STATUS                     = 0x21;
    static const uint8_t SET_TRACK_POWER_OFF            = 0x21;
    static const uint8_t SET_TRACK_POWER_ON             = 0x21;

    static const uint8_t DCC_READ_REGISTER              = 0x22;
    static const uint8_t DCC_WRITE_REGISTER             = 0x23;
    static const uint8_t CV_READ                        = 0x23;
    static const uint8_t CV_WRITE                       = 0x24;
    static const uint8_t MM_WRITE_BYTE                  = 0x24;

    static const uint8_t GET_TURNOUT_INFO               = 0x43;
    static const uint8_t SET_TURNOUT                    = 0x53;

    static const uint8_t SET_STOP                       = 0x80;

    static const uint8_t GET_LOCO_INFO                  = 0xE3;
    static const uint8_t SET_LOCO_DRIVE                 = 0xE4;
    static const uint8_t SET_LOCO_FUNCTION              = 0xE4;

    static const uint8_t CV_POM_WRITE_BYTE              = 0xE6;
    static const uint8_t CV_POM_WRITE_BIT               = 0xE6;
    static const uint8_t CV_POM_READ_BYTE               = 0xE6;
    static const uint8_t CV_POM_ACCESSORY_WRITE_BYTE    = 0xE6;
    static const uint8_t CV_POM_ACCESSORY_WRITE_BIT     = 0xE6;
    static const uint8_t CV_POM_ACCESSORY_READ_BYTE     = 0xE6;

    static const uint8_t GET_FIRMWARE_VERSION           = 0xF1;
};

class Z21TX_DB0 {
public:
    static const uint8_t GET_VERSION                    = 0x21;
    static const uint8_t GET_STATUS                     = 0x24;
    static const uint8_t SET_TRACK_POWER_OFF            = 0x80;
    static const uint8_t SET_TRACK_POWER_ON             = 0x81;

    static const uint8_t DCC_READ_REGISTER              = 0x11;
    static const uint8_t DCC_WRITE_REGISTER             = 0x12;
    static const uint8_t CV_READ                        = 0x11;
    static const uint8_t CV_WRITE                       = 0x12;
    static const uint8_t MM_WRITE_BYTE                  = 0xFF;

    static const uint8_t GET_LOCO_INFO                  = 0xF0;
    static const uint8_t SET_LOCO_DRIVE                 = 0x10;
    static const uint8_t SET_LOCO_FUNCTION              = 0xF8;

    static const uint8_t CV_POM_WRITE_BYTE              = 0x30;
    static const uint8_t CV_POM_WRITE_BIT               = 0x30;
    static const uint8_t CV_POM_READ_BYTE               = 0x30;
    static const uint8_t CV_POM_ACCESSORY_WRITE_BYTE    = 0x31;
    static const uint8_t CV_POM_ACCESSORY_WRITE_BIT     = 0x31;
    static const uint8_t CV_POM_ACCESSORY_READ_BYTE     = 0x31;

    static const uint8_t GET_FIRMWARE_VERSION           = 0x0A;
};

class Z21TX_Option {
public:
    static const uint8_t CV_POM_WRITE_BYTE              = 0xEC;
    static const uint8_t CV_POM_WRITE_BIT               = 0xE8;
    static const uint8_t CV_POM_READ_BYTE               = 0xE4;
    static const uint8_t CV_POM_ACCESSORY_WRITE_BYTE    = 0xEC;
    static const uint8_t CV_POM_ACCESSORY_WRITE_BIT     = 0xE8;
    static const uint8_t CV_POM_ACCESSORY_READ_BYTE     = 0xE4;
};

#endif // __Z21_CONST_H__
