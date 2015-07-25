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

#include "Z21Test.h"

boolean been_called = false;

boolean bool_v1 = false;
boolean bool_v2 = false;
boolean bool_v3 = false;
boolean bool_v4 = false;


// to avoid any complication to compere with int literals
uint8_t uint8_v0 = 0;
uint8_t uint8_v1 = 0;
uint8_t uint8_v2 = 0;
uint8_t uint8_v3 = 0;
uint8_t uint8_v4 = 0;
uint8_t uint8_v5 = 0;
uint8_t uint8_v6 = 0;
uint8_t uint8_v7 = 0;

uint8_t* uint8p_v0 = NULL;
uint8_t* uint8p_v1 = NULL;
uint8_t* uint8p_v2 = NULL;

uint16_t uint16_v0 = 0;
uint16_t uint16_v1 = 0;
uint16_t uint16_v2 = 0;
uint16_t uint16_v3 = 0;
uint16_t uint16_v4 = 0;
uint16_t uint16_v5 = 0;

uint32_t uint32_v0 = 0;
uint32_t uint32_v1 = 0;
uint32_t uint32_v6 = 0;

void on_Void() {
    been_called = true;
}

void on_Uint8(uint8_t v0) {
    been_called = true;
    uint8_v0 = v0;
}

void on_Uint8_Uint8(uint8_t v0, uint8_t v1) {
    been_called = true;
    uint8_v0 = v0;
    uint8_v1 = v1;
}

void on_Uint8p_Uint16(uint8_t* v0, uint16_t v1) {
    been_called = true;
    uint8p_v0 = v0;
    uint16_v1 = v1;
}

void on_Uint8_Uint8p_Uint16(uint8_t v0, uint8_t* v1, uint16_t v2) {
    been_called = true;
    uint8_v0  = v0;
    uint8p_v1 = v1;
    uint16_v2 = v2;
}

void on_Uint8_Uint16_Uint8p_Uint16(uint8_t v0, uint16_t v1, uint8_t* v2, uint16_t v3) {
    been_called = true;
    uint8_v0  = v0;
    uint16_v1 = v1;
    uint8p_v2 = v2;
    uint16_v3 = v3;
}

void on_Uint16_Uint8(uint16_t v0, uint8_t v1) {
    been_called = true;
    uint16_v0 = v0;
    uint8_v1 = v1;
}

void on_Uint16x6_Uint8x2(uint16_t v0, 
                         uint16_t v1, 
                         uint16_t v2, 
                         uint16_t v3,
                         uint16_t v4,
                         uint16_t v5,
                         uint8_t  v6,
                         uint8_t  v7) {
    been_called = true;
    uint16_v0 = v0;
    uint16_v1 = v1;
    uint16_v2 = v2;
    uint16_v3 = v3;
    uint16_v4 = v4;
    uint16_v5 = v5;  
    uint8_v6 = v6;
    uint8_v7 = v7;
}

void on_Uint16_Boolx4_Uint8_Uint32(uint16_t v0,
                                   boolean  v1,
                                   boolean  v2,
                                   boolean  v3,
                                   boolean  v4,
                                   uint8_t  v5,
                                   uint32_t v6) {
    been_called = true;
    uint16_v0 = v0;
    bool_v1 = v1;
    bool_v2 = v2;
    bool_v3 = v3;
    bool_v4 = v4;
    uint8_v5 = v5;
    uint32_v6 = v6;
}

void on_Uint32(uint32_t v0) {
    been_called = true;
    uint32_v0 = v0;
}

void on_Uint32_Uint32(uint32_t v0, uint32_t v1) {
    been_called = true;
    uint32_v0 = v0;
    uint32_v1 = v1;
}

void Z21RXTest::test_onSerialNumber() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onSerialNumber = on_Uint32;
    been_called = false;
    uint32_v0 = 0;

    uint8_t packet[] = {0x08, 0x00, 0x10, 0x00, 0x01, 0x23, 0x45, 0x67};
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(0x67452301L == uint32_v0);
}

void Z21RXTest::test_onHardwareInfo() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onHardwareInfo = on_Uint32_Uint32;
    been_called = false;
    uint32_v0 = 0;
    uint32_v1 = 0;

    uint8_t packet[] = {0x0C, 0x00, 0x1A, 0x00, 0xFE, 0xDC, 0xBA, 0x98, 0x01, 0x23, 0x45, 0x67};
    z21.processPacket(packet);
    
    ASSERT(been_called);
    ASSERT(0x98BADCFEL == uint32_v0);
    ASSERT(0x67452301L == uint32_v1);
}

void Z21RXTest::test_onFirmwareVersion() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onFirmwareVersion = on_Uint8_Uint8;
    been_called = false;
    uint8_v0 = 0;
    uint8_v1 = 0;

    uint8_t packet[] = {0x09, 0x00, 0x40, 0x00, 0xf3, 0x0a, 0x01, 0x23, 0xdb};
    z21.processPacket(packet);
    
    ASSERT(been_called);
    ASSERT(0x01 == uint8_v0);
    ASSERT(0x23 == uint8_v1);
}

void Z21RXTest::test_onGetVersion() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onGetVersion = on_Uint8_Uint8;
    been_called = false;
    uint8_v0 = 0;
    uint8_v1 = 0;

    uint8_t packet[] = {0x09, 0x00, 0x40, 0x00, 0x63, 0x21, 0x30, 0x12, 0x60};
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(0x30 == uint8_v0);
    ASSERT(0x12 == uint8_v1);
}

void Z21RXTest::test_onBroadcastFlags() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onBroadcastFlags = on_Uint32;
    been_called = false;
    uint32_v0 = 0;

    uint8_t packet[] = {0x08, 0x00, 0x51, 0x00, 0xEF, 0xCD, 0xAB, 0x89};
    z21.processPacket(packet);
    
    ASSERT(been_called);
    ASSERT(0x89ABCDEFL == uint32_v0);
}

void Z21RXTest::test_onBCStopped() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onBCStopped = on_Void;
    been_called = false;

    uint8_t packet[] = {0x07, 0x00, 0x40, 0x00, 0x81, 0x00, 0x81};
    z21.processPacket(packet);
    
    ASSERT(been_called);
}

void Z21RXTest::test_onTrackPowerOff() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onTrackPowerOff = on_Void;
    been_called = false;

    uint8_t packet[] = {0x07, 0x00, 0x40, 0x00, 0x61, 0x00, 0x61};
    z21.processPacket(packet);
    
    ASSERT(been_called);
}

void Z21RXTest::test_onTrackPowerOn() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onTrackPowerOn = on_Void;
    been_called = false;

    uint8_t packet[] = {0x07, 0x00, 0x40, 0x00, 0x61, 0x01, 0x60};
    z21.processPacket(packet);
    
    ASSERT(been_called);
}

void Z21RXTest::test_onTrackProgrammingMode() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onTrackProgrammingMode = on_Void;
    been_called = false;

    uint8_t packet[] = {0x07, 0x00, 0x40, 0x00, 0x61, 0x02, 0x63};
    z21.processPacket(packet);
    
    ASSERT(been_called);
}

void Z21RXTest::test_onTrackShortCircuit() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onTrackShortCircuit = on_Void;
    been_called = false;

    uint8_t packet[] = {0x07, 0x00, 0x40, 0x00, 0x61, 0x08, 0x69};
    z21.processPacket(packet);
    
    ASSERT(been_called);
}

void Z21RXTest::test_onStatusChanged() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onStatusChanged = on_Uint8;
    been_called = false;
    uint8_v0 = 0;

    uint8_t packet[] = {0x08, 0x00, 0x40, 0x00, 0x62, 0x22, 0x64, 0x04};
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(0x64 == uint8_v0);
}

void Z21RXTest::test_onSystemStateDataChanged() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onSystemStateDataChanged = on_Uint16x6_Uint8x2;
    been_called = false;
    uint16_v0 = 0;
    uint16_v1 = 0;
    uint16_v2 = 0;
    uint16_v3 = 0;
    uint16_v4 = 0;
    uint16_v5 = 0;
    uint8_v6 = 0;
    uint8_v7 = 0;

    uint8_t packet[] = {0x14, 0x00, 0x84, 0x00, 
                        0x01, 0x23, 0x45, 0x67,
                        0x89, 0xAB, 0xCD, 0xEF,
                        0xFE, 0xDC, 0xBA, 0x98,
                        0x76, 0x54, 0x32, 0x10,
    };
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(0x2301 == uint16_v0);
    ASSERT(0x6745 == uint16_v1);
    ASSERT(0xAB89 == uint16_v2);
    ASSERT(0xEFCD == uint16_v3);
    ASSERT(0xDCFE == uint16_v4);
    ASSERT(0x98BA == uint16_v5);
    ASSERT(0x76 == uint8_v6);
    ASSERT(0x54 == uint8_v7);
}

void Z21RXTest::test_onUnknownCommand() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onUnknownCommand = on_Void;
    been_called = false;

    uint8_t packet[] = {0x07, 0x00, 0x40, 0x00, 0x61, 0x82, 0xE3};
    z21.processPacket(packet);
    
    ASSERT(been_called);
}

void Z21RXTest::test_onLocoInfo() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onLocoInfo = on_Uint16_Boolx4_Uint8_Uint32;
    been_called = false;
    uint16_v0 = 0;
    bool_v1 = false;
    bool_v2 = false;
    bool_v3 = false;
    bool_v4 = false;
    uint8_v5 = false;
    uint32_v6 = false;

    uint8_t packet[] = {0x0E, 0x00, 0x40, 0x00, 
                        0xEF, 0xFE, 0xDC, 0xBA, 0x98, 
                        B01110110, 
                        B01010100, 
                        B00110010,
                        B00010000, 
                        0xEF ^ 0xFE ^ 0xDC ^ 0xBA ^ 0x98 ^ B00000000};
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(0x3EDC == uint16_v0);
    ASSERT(bool_v1); // busy
    ASSERT(bool_v2); // consist
    ASSERT(bool_v3); // transpond
    ASSERT(bool_v4); // forward
    ASSERT(0x60 == uint8_v5); // 0x18 in 28 step = 0x60
    ASSERT(B10001101 == (uint32_v6 & 0xFF));
    ASSERT(B01001010 == ((uint32_v6 >> 8) & 0xFF));
    ASSERT(B00000110 == ((uint32_v6 >> 16) & 0xFF));
    ASSERT(B00000010 == ((uint32_v6 >> 24) & 0xFF));
}

void Z21RXTest::test_onAccessoryInfo() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onAccessoryInfo = on_Uint16_Uint8;
    been_called = false;
    uint16_v0 = 0;
    uint8_v1 = 0;

    uint8_t packet[] = {0x09, 0x00, 0x40, 0x00, 0x43, 0x12, 0x34, 0x02, 0x66};
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(0x1234 == uint16_v0);
    ASSERT(0x02   == uint8_v1);
}

void Z21RXTest::test_onLocoMode() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onLocoMode = on_Uint16_Uint8;
    been_called = false;
    uint16_v0 = 0;
    uint8_v1 = 0;

    uint8_t packet[] = {0x07, 0x00, 0x60, 0x00, 0x23, 0x45, 0x01};
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(0x2345 == uint16_v0);
    ASSERT(0x01   == uint8_v1);
}

void Z21RXTest::test_onAccessoryMode() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onAccessoryMode = on_Uint16_Uint8;
    been_called = false;
    uint16_v0 = 0;
    uint8_v1 = 0;

    uint8_t packet[] = {0x07, 0x00, 0x70, 0x00, 0x34, 0x56, 0x02};
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(0x3456 == uint16_v0);
    ASSERT(0x02   == uint8_v1);
}

void Z21RXTest::test_onCVResult() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onCVResult = on_Uint16_Uint8;
    been_called = false;
    uint16_v0 = 0;
    uint8_v1 = 0;

    uint8_t packet[] = {0x0A, 0x00, 0x40, 0x00, 0x64, 0x14, 0x67, 0x89, 0xAB, 0x35};
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(0x6789 == uint16_v0);
    ASSERT(0xAB   == uint8_v1);
}

void Z21RXTest::test_onCVAccessFailed() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onCVAccessFailed = on_Void;
    been_called = false;

    uint8_t packet[] = {0x07, 0x00, 0x40, 0x00, 0x61, 0x13, 0x72};
    z21.processPacket(packet);
    
    ASSERT(been_called);
}

void Z21RXTest::test_onCVAccessFailedShortCircuit() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onCVAccessFailedShortCircuit = on_Void;
    been_called = false;

    uint8_t packet[] = {0x07, 0x00, 0x40, 0x00, 0x61, 0x12, 0x73};
    z21.processPacket(packet);
    
    ASSERT(been_called);
}

void Z21RXTest::test_onRailComDataChanged() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onRailComDataChanged = on_Uint8p_Uint16;
    been_called = false;
    uint8p_v0 = NULL;
    uint16_v1 = 0;

    uint8_t packet[] = {0x12, 0x00, 0x88, 0x00, 0xBE};
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(packet + 4 == uint8p_v0);
    ASSERT(0x000E     == uint16_v1);
}

void Z21RXTest::test_onRBusDataChanged() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onRBusDataChanged = on_Uint8_Uint8p_Uint16;
    been_called = false;
    uint8_v0  = 0;
    uint8p_v1 = NULL;
    uint16_v2 = 0;

    uint8_t packet[] = {0x0F, 0x00, 0x80, 0x00, 0xEF, 0xAB};
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(0xEF       == uint8_v0);
    ASSERT(packet + 5 == uint8p_v1);
    ASSERT(0x000A     == uint16_v2);
}

void Z21RXTest::test_onLoconetRX() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onLoconetRX = on_Uint8p_Uint16;
    been_called = false;
    uint8p_v0 = NULL;
    uint16_v1 = 0;

    uint8_t packet[] = {0x1A, 0x00, 0xA0, 0x00, 0xBE};
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(packet + 4 == uint8p_v0);
    ASSERT(0x0016     == uint16_v1);
}

void Z21RXTest::test_onLoconetTX() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onLoconetTX = on_Uint8p_Uint16;
    been_called = false;
    uint8p_v0 = NULL;
    uint16_v1 = 0;

    uint8_t packet[] = {0x24, 0x00, 0xA1, 0x00, 0xEC};
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(packet + 4 == uint8p_v0);
    ASSERT(0x0020     == uint16_v1);
}

void Z21RXTest::test_onLoconetFromLAN() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onLoconetFromLAN = on_Uint8p_Uint16;
    been_called = false;
    uint8p_v0 = NULL;
    uint16_v1 = 0;

    uint8_t packet[] = {0x3C, 0x00, 0xA2, 0x00, 0xAB};
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(packet + 4 == uint8p_v0);
    ASSERT(0x0038     == uint16_v1);
}

void Z21RXTest::test_onLoconetDispatchAddress() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onLoconetDispatchAddress = on_Uint16_Uint8;
    been_called = false;
    uint16_v0 = 0;
    uint8_v1  = 0;

    uint8_t packet[] = {0x07, 0x00, 0xA3, 0x00, 0xBE, 0x23, 0x56};
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(0x23BE == uint16_v0);
    ASSERT(0x56   == uint8_v1);
}

void Z21RXTest::test_onLoconetDetector() {
    UnitTest::start();
    
    Z21Translator z21;
    z21.onLoconetDetector = on_Uint8_Uint16_Uint8p_Uint16;
    been_called = false;
    uint8_v0  = 0;
    uint16_v1 = 0;
    uint8p_v2 = NULL;
    uint16_v3 = 0;

    uint8_t packet[] = {0x0B, 0x00, 0xA4, 0x00, 0xDC, 0xFE, 0xBA, 0x34, 0x56, 0x78, 0x9A};
    z21.processPacket(packet);

    ASSERT(been_called);
    ASSERT(0xDC   == uint8_v0);
    ASSERT(0xBAFE == uint16_v1);
    ASSERT(packet + 7 == uint8p_v2);
    ASSERT(0x0004 == uint16_v3);
}


boolean Z21RXTest::testAll() {
    UnitTest::suite("Z21 RX");
    
    test_onSerialNumber();      // 1
    test_onHardwareInfo();
    test_onFirmwareVersion();
    test_onGetVersion();

    test_onBroadcastFlags();    // 5
    test_onBCStopped();
    test_onTrackPowerOff();
    test_onTrackPowerOn();
    test_onTrackProgrammingMode();
    test_onTrackShortCircuit(); // 10
    test_onStatusChanged();             
    test_onSystemStateDataChanged();
    test_onUnknownCommand();

    test_onLocoInfo();          // 14
    test_onAccessoryInfo();     
    test_onLocoMode();
    test_onAccessoryMode();

    test_onCVResult();          // 18
    test_onCVAccessFailed();
    test_onCVAccessFailedShortCircuit();

    test_onRailComDataChanged();// 21
    test_onRBusDataChanged();
    test_onLoconetRX();
    test_onLoconetTX();
    test_onLoconetFromLAN();    // 25
    test_onLoconetDispatchAddress();  
    test_onLoconetDetector();  
    
    return UnitTest::report();
}

