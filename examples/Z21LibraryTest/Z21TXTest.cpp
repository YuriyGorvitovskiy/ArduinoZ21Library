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

void Z21TXTest::test_getSerialNumber() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.getSerialNumber();

    uint8_t expect[] = {0x04, 0x00, 0x10, 0x00}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}

void Z21TXTest::test_getHardwareInfo() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.getHardwareInfo();

    uint8_t expect[] = {0x04, 0x00, 0x1A, 0x00}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}

void Z21TXTest::test_getVersion() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.getVersion();

    uint8_t expect[] = {0x07, 0x00, 0x40, 0x00, 0x21, 0x21, 0x00}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_getFirmwareVersion() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.getFirmwareVersion();

    uint8_t expect[] = {0x07, 0x00, 0x40, 0x00, 0xF1, 0x0A, 0xFB}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_getStatus() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.getStatus();

    uint8_t expect[] = {0x07, 0x00, 0x40, 0x00, 0x21, 0x24, 0x05}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_getSystemState() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.getSystemState();

    uint8_t expect[] = {0x04, 0x00, 0x85, 0x00}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_setTrackPowerOff() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.setTrackPowerOff();

    uint8_t expect[] = {0x07, 0x00, 0x40, 0x00, 0x21, 0x80, 0xa1}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_setTrackPowerOn() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.setTrackPowerOn();

    uint8_t expect[] = {0x07, 0x00, 0x40, 0x00, 0x21, 0x81, 0xa0}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_getBroadcastFlags() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.getBroadcastFlags();

    uint8_t expect[] = {0x04, 0x00, 0x51, 0x00}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_setBroadcastFlags() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.setBroadcastFlags(0x12345678L);

    uint8_t expect[] = {0x08, 0x00, 0x50, 0x00, 0x78, 0x56, 0x34, 0x12}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_logoff() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.logoff();

    uint8_t expect[] = {0x04, 0x00, 0x30, 0x00}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_setStop() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.setStop();

    uint8_t expect[] = {0x06, 0x00, 0x40, 0x00, 0x80, 0x80}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_getLocoInfo() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.getLocoInfo(0x5639);

    uint8_t expect[] = {0x09, 0x00, 0x40, 0x00, 0xE3, 0xF0, 0xD6, 0x39, 0xE3 ^ 0xF0 ^ 0xD6 ^ 0x39}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_setLocoDrive() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.setLocoDrive(0x1838, false, 0x03, 0x72);

    uint8_t expect[] = {0x0A, 0x00, 0x40, 0x00, 0xE4, 0x13, 0xD8, 0x38, 0x72, 0xE4 ^ 0x13 ^ 0xD8 ^ 0x38 ^ 0x72}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_setLocoFunction() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.setLocoFunction(0x6749, 0x15, 0x2);

    uint8_t expect[] = {0x0A, 0x00, 0x40, 0x00, 0xE4, 0xF8, 0xE7, 0x49, 0x95, 0xE4 ^ 0xF8 ^ 0xE7 ^ 0x49 ^ 0x95}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_getAccessoryInfo() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.getAccessoryInfo(0x4821);

    uint8_t expect[] = {0x08, 0x00, 0x40, 0x00, 0x43, 0x48, 0x21, 0x43 ^ 0x48 ^ 0x21}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_setAccessory() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.setAccessory(0x6391, 0x00, true, false);

    uint8_t expect[] = {0x09, 0x00, 0x40, 0x00, 0x53, 0x63, 0x91, B10001000, 0x53 ^ 0x63 ^ 0x91 ^ B10001000}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_getLocoMode() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.getLocoMode(0x8593);

    uint8_t expect[] = {0x06, 0x00, 0x60, 0x00, 0x85, 0x93}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_setLocoMode() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.setLocoMode(0x7392, 0x87);

    uint8_t expect[] = {0x07, 0x00, 0x61, 0x00, 0x73, 0x92, 0x87}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_getAccessoryMode() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.getAccessoryMode(0x3856);

    uint8_t expect[] = {0x06, 0x00, 0x70, 0x00, 0x38, 0x56}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_setAccessoryMode() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.setAccessoryMode(0x1872, 0x36);

    uint8_t expect[] = {0x07, 0x00, 0x71, 0x00, 0x18, 0x72, 0x36}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_dccReadRegister() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.dccReadRegister(0x62);

    uint8_t expect[] = {0x08, 0x00, 0x40, 0x00, 0x22, 0x11, 0x62, 0x22 ^ 0x11 ^ 0x62}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_dccWriteRegister() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.dccWriteRegister(0x47, 0x64);

    uint8_t expect[] = {0x09, 0x00, 0x40, 0x00, 0x23, 0x12, 0x47, 0x64, 0x23 ^ 0x12 ^ 0x47 ^ 0x64}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_dccReadCV() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.dccReadCV(0x5476);

    uint8_t expect[] = {0x09, 0x00, 0x40, 0x00, 0x23, 0x11, 0x00, 0x76, 0x23 ^ 0x11 ^ 0x00 ^ 0x76}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_dccWriteCV() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.dccWriteCV(0x9353, 0x64);

    uint8_t expect[] = {0x0A, 0x00, 0x40, 0x00, 0x24, 0x12, 0x03, 0x53, 0x64, 0x24 ^ 0x12 ^ 0x03 ^ 0x53 ^ 0x64}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_mmWriteByte() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.mmWriteByte(0x23, 0x74);

    uint8_t expect[] = {0x0A, 0x00, 0x40, 0x00, 0x24, 0xFF, 0x00, 0x23, 0x74, 0x24 ^ 0xFF ^ 0x00 ^ 0x23 ^ 0x74}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_dccReadOnMainLocoCVByte() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.dccReadOnMainLocoCVByte(0x7399, 0x4729);

    uint8_t expect[] = {0x0C, 0x00, 0x40, 0x00, 0xE6, 0x30, 0xF3, 0x99, B11100111, 0x29, 0x00, 0xE6 ^ 0x30 ^ 0xF3 ^ 0x99 ^ B11100111 ^ 0x29 ^ 0x00}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_dccWriteOnMainLocoCVByte() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.dccWriteOnMainLocoCVByte(0x9384, 0x0284, 0x75);

    uint8_t expect[] = {0x0C, 0x00, 0x40, 0x00, 0xE6, 0x30, 0xD3, 0x84, B11101110, 0x84, 0x75, 0xE6 ^ 0x30 ^ 0xD3 ^ 0x84 ^ B11101110 ^ 0x84 ^ 0x75}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_dccWriteOnMainLocoCVBit() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.dccWriteOnMainLocoCVBit(0x4109, 0x4321, 3, false);

    uint8_t expect[] = {0x0C, 0x00, 0x40, 0x00, 0xE6, 0x30, 0xC1, 0x09, B11101011, 0x21, 0x03, 0xE6 ^ 0x30 ^ 0xC1 ^ 0x09 ^ B11101011 ^ 0x21 ^ 0x03}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_dccReadOnMainAccessoryCVByte() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.dccReadOnMainAccessoryCVByte(0x0987, 0x01, 0x6543); // B00001 00110 0001 11, B0000 0001, B0110 0101 0100 0011
    
    uint8_t expect[] = {0x0C, 0x00, 0x40, 0x00, 0xE6, 0x31, B00000110, B00011111, 0xE5, 0x43, 0x00, 0xE6 ^ 0x31 ^ B00000110 ^ B00011111 ^ 0xE5 ^ 0x43 ^ 0x00}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));

    packet = z21.dccReadOnMainAccessoryCVByte(0x0987, Z21_Accessory_Pos::ALL, 0x6543); // B00001 00110 0001 11, B0000 0010, B0110 0101 0100 0011
    
    uint8_t expect2[] = {0x0C, 0x00, 0x40, 0x00, 0xE6, 0x31, B00000110, B00010000, 0xE5, 0x43, 0x00, 0xE6 ^ 0x31 ^ B00000110 ^ B00010000 ^ 0xE5 ^ 0x43 ^ 0x00}; 
    
    ASSERT(sizeof(expect2) == packet.length);
    ASSERT(UnitTest::same_values(expect2, packet.data, packet.length));
}
void Z21TXTest::test_dccWriteOnMainAccessoryCVByte() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.dccWriteOnMainAccessoryCVByte(0x0987, 0x01, 0x6543, 0x56); // B00001 00110 0001 11, B0000 0001, B0110 0101 0100 0011

    uint8_t expect[] = {0x0C, 0x00, 0x40, 0x00, 0xE6, 0x31, B00000110, B00011111, 0xED, 0x43, 0x56, 0xE6 ^ 0x31 ^ B00000110 ^ B00011111 ^ 0xED ^ 0x43 ^ 0x56}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));

    packet = z21.dccWriteOnMainAccessoryCVByte(0x0987, Z21_Accessory_Pos::ALL, 0x6543, 0x56); // B00001 00110 0001 11, B0000 0010, B0110 0101 0100 0011
    
    uint8_t expect2[] = {0x0C, 0x00, 0x40, 0x00, 0xE6, 0x31, B00000110, B00010000, 0xED, 0x43, 0x56, 0xE6 ^ 0x31 ^ B00000110 ^ B00010000 ^ 0xED ^ 0x43 ^ 0x56}; 
    
    ASSERT(sizeof(expect2) == packet.length);
    ASSERT(UnitTest::same_values(expect2, packet.data, packet.length));
}
void Z21TXTest::test_dccWriteOnMainAccessoryCVBit() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.dccWriteOnMainAccessoryCVBit(0x0987, 0x01, 0x6543, 0x07, true); // B00001 00110 0001 11, B0000 0001, B0110 0101 0100 0011

    uint8_t expect[] = {0x0C, 0x00, 0x40, 0x00, 0xE6, 0x31, B00000110, B00011111, 0xE9, 0x43, 0x0F, 0xE6 ^ 0x31 ^ B00000110 ^ B00011111 ^ 0xE9 ^ 0x43 ^ 0x0F}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));

    packet = z21.dccWriteOnMainAccessoryCVBit(0x0987, Z21_Accessory_Pos::ALL, 0x6543, 0x00, false); // B00001 00110 0001 11, B0000 0010, B0110 0101 0100 0011
    
    uint8_t expect2[] = {0x0C, 0x00, 0x40, 0x00, 0xE6, 0x31, B00000110, B00010000, 0xE9, 0x43, 0x00, 0xE6 ^ 0x31 ^ B00000110 ^ B00010000 ^ 0xE9 ^ 0x43 ^ 0x00}; 
    
    ASSERT(sizeof(expect2) == packet.length);
    ASSERT(UnitTest::same_values(expect2, packet.data, packet.length));
}
void Z21TXTest::test_railcomGetData() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.railcomGetData();

    uint8_t expect[] = {0x04, 0x00, 0x89, 0x00}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_rbusGetData() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.rbusGetData(0x67);

    uint8_t expect[] = {0x05, 0x00, 0x81, 0x00, 0x67}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_rbusProgramModule() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.rbusProgramModule(0x45);

    uint8_t expect[] = {0x05, 0x00, 0x82, 0x00, 0x45}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_loconetDispatchAddress() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.loconetDispatchAddress(0x789A);

    uint8_t expect[] = {0x06, 0x00, 0xA3, 0x00, 0x9A, 0x78}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_loconetDetector() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.loconetDetector(0x34, 0x5678);

    uint8_t expect[] = {0x07, 0x00, 0xA4, 0x00, 0x34, 0x78, 0x56}; 
    
    ASSERT(sizeof(expect) == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, packet.length));
}
void Z21TXTest::test_loconetSendMessage() {
    UnitTest::start();

    Z21Translator z21;
    Z21Packet& packet = z21.loconetSendMessage(0x1234);

    uint8_t expect[] = {0x38, 0x12, 0xA2, 0x00}; 
    ASSERT(0x1238 == packet.length);
    ASSERT(UnitTest::same_values(expect, packet.data, 4));
}

boolean Z21TXTest::testAll() {
    UnitTest::suite("Z21 TX");

    test_getSerialNumber();     // 1
    test_getHardwareInfo();
    test_getVersion();
    test_getFirmwareVersion();
    
    test_getStatus();           // 5
    test_getSystemState();

    test_setTrackPowerOff();    // 7
    test_setTrackPowerOn();
    
    test_getBroadcastFlags();   // 9
    test_setBroadcastFlags();
    
    test_logoff();              // 11
    
    test_setStop();             // 12
    
    test_getLocoInfo();         // 13
    test_setLocoDrive();
    test_setLocoFunction();
    
    test_getAccessoryInfo();    // 16
    test_setAccessory();
    
    test_getLocoMode();         // 18
    test_setLocoMode();
    
    test_getAccessoryMode();    // 20
    test_setAccessoryMode();
    
    test_dccReadRegister();     // 22
    test_dccWriteRegister();
    
    test_dccReadCV();           // 24
    test_dccWriteCV();
    
    test_mmWriteByte();         // 26
    
    test_dccReadOnMainLocoCVByte();         // 27
    test_dccWriteOnMainLocoCVByte();
    test_dccWriteOnMainLocoCVBit();
    
    test_dccReadOnMainAccessoryCVByte();    // 30
    test_dccWriteOnMainAccessoryCVByte();
    test_dccWriteOnMainAccessoryCVBit();

    test_railcomGetData();          // 33
    
    test_rbusGetData();             // 34
    test_rbusProgramModule();

    test_loconetDispatchAddress();  // 36
    test_loconetDetector();
    test_loconetSendMessage();      // 38
    
    return UnitTest::report();      
}

