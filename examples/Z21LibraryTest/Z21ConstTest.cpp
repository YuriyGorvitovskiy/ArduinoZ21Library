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
 
#include <Arduino.h>
#include <UnitTest.h>
#include <Z21.h>
#include <Z21Const.h>

#include "Z21ConstTest.h"

void Z21ConstTest::testZ21_Broadcast() {
    UnitTest::start();

    uint32_t value[] = { 
        Z21_Broadcast::STATUS_LOCO_TURNOUT,
        Z21_Broadcast::RMBUS_DATACHANGED,
        Z21_Broadcast::SYSTEMSTATE_DATACHANGED,
        Z21_Broadcast::ALL_LOCO_INFO,
        Z21_Broadcast::LOCONET,
        Z21_Broadcast::LOCONET_LOCO,
        Z21_Broadcast::LOCONET_TURNOUT,
        Z21_Broadcast::LOCONET_OCCUPY
    };
    ASSERT(UnitTest::unique_bits(value, sizeof(value)/sizeof(uint32_t)));
    ASSERT(UnitTest::ordered_values(value, sizeof(value)/sizeof(uint32_t)));
}

void Z21ConstTest::testZ21_Status() {
    UnitTest::start();

    uint8_t value[] = { 
        Z21_Status::EMERGENCY_STOP,
        Z21_Status::TRACK_VOLTAGE_OFF,
        Z21_Status::SHORT_CIRCUIT,
        Z21_Status::PROGRAMMING_MODE_ACTIVE,
    };
    
    ASSERT(UnitTest::unique_bits(value, sizeof(value)/sizeof(uint8_t)));
    ASSERT(UnitTest::ordered_values(value, sizeof(value)/sizeof(uint8_t)));
}

void Z21ConstTest::testZ21_Status_EX() {
    UnitTest::start();

    uint8_t value[] = { 
        Z21_Status_EX::HIGH_TEMPERATURE,
        Z21_Status_EX::POWER_LOST,
        Z21_Status_EX::SHORT_CIRCUIT_EXTERNAL,
        Z21_Status_EX::SHORT_CIRCUIT_INTERNAL,
    };
    
    ASSERT(UnitTest::unique_bits(value, sizeof(value)/sizeof(uint8_t)));
    ASSERT(UnitTest::ordered_values(value, sizeof(value)/sizeof(uint8_t)));
}

void Z21ConstTest::testZ21_Decoder_Mode() {
    UnitTest::start();

    uint8_t value[] = { 
        Z21_Decoder_Mode::DCC,
        Z21_Decoder_Mode::MM,
    };
    ASSERT(UnitTest::unique_values(value, sizeof(value)/sizeof(uint8_t)));
    ASSERT(UnitTest::ordered_values(value, sizeof(value)/sizeof(uint8_t)));
}

void Z21ConstTest::testZ21_Speed_Range() {
    UnitTest::start();

    uint8_t value[] = { 
        Z21_Speed_Range::STEPS_14,
        Z21_Speed_Range::STEPS_28,
        Z21_Speed_Range::STEPS_128,
    };
    ASSERT(UnitTest::unique_values(value, sizeof(value)/sizeof(uint8_t)));
    ASSERT(UnitTest::ordered_values(value, sizeof(value)/sizeof(uint8_t)));
}

void Z21ConstTest::testZ21_Function() {
    UnitTest::start();
    
    uint8_t value1[] = { 
        Z21_Function::F0,
        Z21_Function::F1,
        Z21_Function::F2,
        Z21_Function::F3,
        Z21_Function::F4,
        Z21_Function::F5,
        Z21_Function::F6,
        Z21_Function::F7,
        Z21_Function::F8,
        Z21_Function::F9,
        Z21_Function::F10,
        Z21_Function::F11,
        Z21_Function::F12,
        Z21_Function::F13,
        Z21_Function::F14,
        Z21_Function::F15,
        Z21_Function::F16,
        Z21_Function::F17,
        Z21_Function::F18,
        Z21_Function::F19,
        Z21_Function::F20,
        Z21_Function::F21,
        Z21_Function::F22,
        Z21_Function::F23,
        Z21_Function::F24,
        Z21_Function::F25,
        Z21_Function::F26,
        Z21_Function::F27,
        Z21_Function::F28
    };
    
    ASSERT(UnitTest::unique_values(value1, sizeof(value1)/sizeof(uint8_t)));
    ASSERT(UnitTest::ordered_values(value1, sizeof(value1)/sizeof(uint8_t)));

    uint32_t value2[] = { 
        Z21_Function::F0_BIT,
        Z21_Function::F1_BIT,
        Z21_Function::F2_BIT,
        Z21_Function::F3_BIT,
        Z21_Function::F4_BIT,
        Z21_Function::F5_BIT,
        Z21_Function::F6_BIT,
        Z21_Function::F7_BIT,
        Z21_Function::F8_BIT,
        Z21_Function::F9_BIT,
        Z21_Function::F10_BIT,
        Z21_Function::F11_BIT,
        Z21_Function::F12_BIT,
        Z21_Function::F13_BIT,
        Z21_Function::F14_BIT,
        Z21_Function::F15_BIT,
        Z21_Function::F16_BIT,
        Z21_Function::F17_BIT,
        Z21_Function::F18_BIT,
        Z21_Function::F19_BIT,
        Z21_Function::F20_BIT,
        Z21_Function::F21_BIT,
        Z21_Function::F22_BIT,
        Z21_Function::F23_BIT,
        Z21_Function::F24_BIT,
        Z21_Function::F25_BIT,
        Z21_Function::F26_BIT,
        Z21_Function::F27_BIT,
        Z21_Function::F28_BIT,
    };

    ASSERT(UnitTest::unique_bits(value2, sizeof(value2)/sizeof(uint32_t)));
    ASSERT(UnitTest::ordered_values(value2, sizeof(value2)/sizeof(uint32_t)));
}

void Z21ConstTest::testZ21_Function_Action() {
    UnitTest::start();

    uint8_t value[] = { 
        Z21_Function_Action::OFF,
        Z21_Function_Action::ON,
        Z21_Function_Action::SWITCH,
    };
    ASSERT(UnitTest::unique_values(value, sizeof(value)/sizeof(uint8_t)));
    ASSERT(UnitTest::ordered_values(value, sizeof(value)/sizeof(uint8_t)));
}

void Z21ConstTest::testZ21_Accessory_Pos() {
    UnitTest::start();

    uint8_t value[] = { 
        Z21_Accessory_Pos::P0,
        Z21_Accessory_Pos::P1,
        Z21_Accessory_Pos::ALL,
    };
    ASSERT(UnitTest::unique_values(value, sizeof(value)/sizeof(uint8_t)));
    ASSERT(UnitTest::ordered_values(value, sizeof(value)/sizeof(uint8_t)));
}

void Z21ConstTest::testZ21_Accessory_State() {
    UnitTest::start();

    uint8_t value[] = { 
        Z21_Accessory_State::UNKNOWN,
        Z21_Accessory_State::P0,
        Z21_Accessory_State::P1,
        Z21_Accessory_State::INVALID,
    };
    ASSERT(UnitTest::unique_values(value, sizeof(value)/sizeof(uint8_t)));
    ASSERT(UnitTest::ordered_values(value, sizeof(value)/sizeof(uint8_t)));
}

void Z21ConstTest::testZ21_LAN() {
    UnitTest::start();

    uint16_t value[] = { 
        Z21_LAN::GET_SERIAL_NUMBER,
        Z21_LAN::GET_HWINFO,
        Z21_LAN::LOGOFF,
        Z21_LAN::X,
        Z21_LAN::SET_BROADCASTFLAGS,
        Z21_LAN::GET_BROADCASTFLAGS,
        Z21_LAN::GET_LOCOMODE,
        Z21_LAN::SET_LOCOMODE,
        Z21_LAN::GET_TURNOUTMODE,
        Z21_LAN::SET_TURNOUTMODE,
        Z21_LAN::RMBUS_DATACHANGED,
        Z21_LAN::RMBUS_GETDATA,
        Z21_LAN::RMBUS_PROGRAMMODULE,
        Z21_LAN::SYSTEMSTATE_DATACHANGED,
        Z21_LAN::SYSTEMSTATE_GETDATA,
        Z21_LAN::RAILCOM_DATACHANGED,
        Z21_LAN::RAILCOM_GETDATA,
        Z21_LAN::LOCONET_Z21_RX,
        Z21_LAN::LOCONET_Z21_TX,
        Z21_LAN::LOCONET_FROM_LAN,
        Z21_LAN::LOCONET_DISPATCH_ADDR,
        Z21_LAN::LOCONET_DETECTOR
    };
    
    ASSERT(UnitTest::unique_values(value, sizeof(value)/sizeof(uint16_t)));
    ASSERT(UnitTest::ordered_values(value, sizeof(value)/sizeof(uint16_t)));
}

void Z21ConstTest::testZ21RX_LAN_X() {
    UnitTest::start();

    uint8_t value[] = { 
        Z21RX_LAN_X::TURNOUT_INFO,
        Z21RX_LAN_X::BC,
        Z21RX_LAN_X::STATUS_CHANGED,
        Z21RX_LAN_X::GET_VERSION,
        Z21RX_LAN_X::CV_RESULT,
        Z21RX_LAN_X::BC_STOPPED,
        Z21RX_LAN_X::LOCO_INFO,
        Z21RX_LAN_X::GET_FIRMWARE_VERSION
    };
    
    ASSERT(UnitTest::unique_values(value, sizeof(value)/sizeof(uint8_t)));
    ASSERT(UnitTest::ordered_values(value, sizeof(value)/sizeof(uint8_t)));
}

void Z21ConstTest::testZ21RX_DB0() {
    UnitTest::start();

    uint8_t value[] = { 
        Z21RX_DB0::BC_TRACK_POWER_OFF,
        Z21RX_DB0::BC_TRACK_POWER_ON,
        Z21RX_DB0::BC_PROGRAMMING_MODE,
        Z21RX_DB0::BC_TRACK_SHORT_CIRCUIT,
        Z21RX_DB0::CV_NACK_SC,
        Z21RX_DB0::CV_NACK,
        Z21RX_DB0::UNKNOWN_COMMAND,
        Z21RX_DB0::STATUS_CHANGED,
        Z21RX_DB0::GET_VERSION,
        Z21RX_DB0::CV_RESULT,
        Z21RX_DB0::GET_FIRMWARE_VERSION,
    };
    
    ASSERT(UnitTest::unique_values(value, sizeof(value)/sizeof(uint8_t)));

    uint8_t value1[] = { 
        Z21RX_DB0::BC_TRACK_POWER_OFF,
        Z21RX_DB0::BC_TRACK_POWER_ON,
        Z21RX_DB0::BC_PROGRAMMING_MODE,
        Z21RX_DB0::BC_TRACK_SHORT_CIRCUIT,
        Z21RX_DB0::CV_NACK_SC,
        Z21RX_DB0::CV_NACK,
        Z21RX_DB0::UNKNOWN_COMMAND,
    };

    ASSERT(UnitTest::ordered_values(value1, sizeof(value1)/sizeof(uint8_t)));
}

void Z21ConstTest::testZ21TX_LAN_X() {
    UnitTest::start();
    
    uint16_t value1[] = { 
        UnitTest::combine(Z21TX_LAN_X::GET_VERSION, Z21TX_DB0::GET_VERSION),
        UnitTest::combine(Z21TX_LAN_X::GET_STATUS, Z21TX_DB0::GET_STATUS),
        UnitTest::combine(Z21TX_LAN_X::SET_TRACK_POWER_OFF, Z21TX_DB0::SET_TRACK_POWER_OFF),
        UnitTest::combine(Z21TX_LAN_X::SET_TRACK_POWER_ON, Z21TX_DB0::SET_TRACK_POWER_ON),
        UnitTest::combine(Z21TX_LAN_X::DCC_READ_REGISTER, Z21TX_DB0::DCC_READ_REGISTER),
        UnitTest::combine(Z21TX_LAN_X::DCC_WRITE_REGISTER, Z21TX_DB0::DCC_WRITE_REGISTER),
        UnitTest::combine(Z21TX_LAN_X::CV_READ, Z21TX_DB0::CV_READ),
        UnitTest::combine(Z21TX_LAN_X::CV_WRITE, Z21TX_DB0::CV_WRITE),
        UnitTest::combine(Z21TX_LAN_X::MM_WRITE_BYTE, Z21TX_DB0::MM_WRITE_BYTE),
        UnitTest::combine(Z21TX_LAN_X::GET_TURNOUT_INFO, 0),
        UnitTest::combine(Z21TX_LAN_X::SET_TURNOUT, 0),
        UnitTest::combine(Z21TX_LAN_X::SET_STOP, 0),
        UnitTest::combine(Z21TX_LAN_X::GET_LOCO_INFO, Z21TX_DB0::GET_LOCO_INFO),
        UnitTest::combine(Z21TX_LAN_X::SET_LOCO_DRIVE, Z21TX_DB0::SET_LOCO_DRIVE | Z21_Speed_Range::STEPS_14),
        UnitTest::combine(Z21TX_LAN_X::SET_LOCO_DRIVE, Z21TX_DB0::SET_LOCO_DRIVE | Z21_Speed_Range::STEPS_28),
        UnitTest::combine(Z21TX_LAN_X::SET_LOCO_DRIVE, Z21TX_DB0::SET_LOCO_DRIVE | Z21_Speed_Range::STEPS_128),
        UnitTest::combine(Z21TX_LAN_X::SET_LOCO_FUNCTION, Z21TX_DB0::SET_LOCO_FUNCTION),
        UnitTest::combine(Z21TX_LAN_X::GET_FIRMWARE_VERSION, Z21TX_DB0::GET_FIRMWARE_VERSION),
        
        UnitTest::combine(Z21TX_LAN_X::CV_POM_WRITE_BYTE, Z21TX_DB0::CV_POM_WRITE_BYTE),
        UnitTest::combine(Z21TX_LAN_X::CV_POM_ACCESSORY_WRITE_BYTE, Z21TX_DB0::CV_POM_ACCESSORY_WRITE_BYTE),
    };
    ASSERT(UnitTest::unique_values(value1, sizeof(value1)/sizeof(uint16_t)));

    uint32_t value2[] = { 
        UnitTest::combine(Z21TX_LAN_X::CV_POM_WRITE_BYTE, Z21TX_DB0::CV_POM_WRITE_BYTE, Z21TX_Option::CV_POM_WRITE_BYTE),
        UnitTest::combine(Z21TX_LAN_X::CV_POM_WRITE_BIT, Z21TX_DB0::CV_POM_WRITE_BIT, Z21TX_Option::CV_POM_WRITE_BIT),
        UnitTest::combine(Z21TX_LAN_X::CV_POM_READ_BYTE, Z21TX_DB0::CV_POM_READ_BYTE, Z21TX_Option::CV_POM_READ_BYTE),
        UnitTest::combine(Z21TX_LAN_X::CV_POM_ACCESSORY_WRITE_BYTE, Z21TX_DB0::CV_POM_ACCESSORY_WRITE_BYTE, Z21TX_Option::CV_POM_ACCESSORY_WRITE_BYTE),
        UnitTest::combine(Z21TX_LAN_X::CV_POM_ACCESSORY_WRITE_BIT, Z21TX_DB0::CV_POM_ACCESSORY_WRITE_BIT, Z21TX_Option::CV_POM_ACCESSORY_WRITE_BIT),
        UnitTest::combine(Z21TX_LAN_X::CV_POM_ACCESSORY_READ_BYTE, Z21TX_DB0::CV_POM_ACCESSORY_READ_BYTE, Z21TX_Option::CV_POM_ACCESSORY_READ_BYTE),
    };
    ASSERT(UnitTest::unique_values(value2, sizeof(value2)/sizeof(uint32_t)));
}
void Z21ConstTest::testZ21_Loconet_Detector() {
    UnitTest::start();

    uint8_t value1[] = { 
        Z21_Loconet_Detector::REQUEST_STATIONARY,
        Z21_Loconet_Detector::REQUEST_REPORT,
        Z21_Loconet_Detector::REQUEST_REPEATER,
    };
    ASSERT(UnitTest::unique_values(value1, sizeof(value1)/sizeof(uint8_t)));
    ASSERT(UnitTest::ordered_values(value1, sizeof(value1)/sizeof(uint8_t)));

    uint8_t value2[] = { 
        Z21_Loconet_Detector::REPORT_SENSOR,
        Z21_Loconet_Detector::REPORT_ENTER,
        Z21_Loconet_Detector::REPORT_LEAVE,
        Z21_Loconet_Detector::REPORT_LISSY_LOCO,
        Z21_Loconet_Detector::REPORT_LISSY_OCCUPY,
        Z21_Loconet_Detector::REPORT_LISSY_SPEED,
    };
    ASSERT(UnitTest::unique_values(value2, sizeof(value2)/sizeof(uint8_t)));
    ASSERT(UnitTest::ordered_values(value2, sizeof(value2)/sizeof(uint8_t)));
}

boolean Z21ConstTest::testAll() {
    UnitTest::suite("Z21 Const");
    
    testZ21_Broadcast();        // 1
    testZ21_Status();
    testZ21_Status_EX();
    
    testZ21_Decoder_Mode();     // 4
    testZ21_Speed_Range();
    testZ21_Function();         
    testZ21_Function_Action();
    
    testZ21_Accessory_Pos();    //8
    testZ21_Accessory_State();

    testZ21_LAN();              // 10
    testZ21RX_LAN_X();
    testZ21RX_DB0();
    testZ21TX_LAN_X();

    testZ21_Loconet_Detector(); // 14
    
    return UnitTest::report();
}

