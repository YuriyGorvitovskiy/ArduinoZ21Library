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
#include <Z21Packet.h>

#include "Z21PacketTest.h"

void Z21PacketTest::testBasicSet() {
    UnitTest::start();

    Z21Packet packet;

    packet.setByte(1, (uint8_t)0x34);
    ASSERT(0x34 == packet.data[1]); // 1

    packet.setByte(2, 0x12FE);
    ASSERT(0xFE == packet.data[2]); // 2

    packet.setByte(3,0x124567EFL);
    ASSERT(0xEF == packet.data[3]); // 3

    packet.setLEuint16(4, 0x37BE);
    ASSERT(0xBE == packet.data[4]); // 4
    ASSERT(0x37 == packet.data[5]);
    
    packet.setLEuint32(6, 0x1368ABDEL);
    ASSERT(0xDE == packet.data[6]); // 6
    ASSERT(0xAB == packet.data[7]);
    ASSERT(0x68 == packet.data[8]);
    ASSERT(0x13 == packet.data[9]);

    packet.setBEuint16(10, 0x37BE);
    ASSERT(0x37 == packet.data[10]); // 10
    ASSERT(0xBE == packet.data[11]);

    packet.setBEuint32(12, 0x1368ABDEL);
    ASSERT(0x13 == packet.data[12]); // 12
    ASSERT(0x68 == packet.data[13]);
    ASSERT(0xAB == packet.data[14]);
    ASSERT(0xDE == packet.data[15]);
}

void Z21PacketTest::testSetHeader() {
    UnitTest::start();

    Z21Packet packet;

    packet.setHeader(0x3456, 0xABCD);
    ASSERT(0x56 == packet.data[0]); // 1
    ASSERT(0x34 == packet.data[1]);
    ASSERT(0xCD == packet.data[2]);
    ASSERT(0xAB == packet.data[3]);

    packet.setXPacket(0x34);
    ASSERT(0x06 == packet.data[0]); // 5
    ASSERT(0x00 == packet.data[1]);
    ASSERT(0x40 == packet.data[2]);
    ASSERT(0x00 == packet.data[3]);
    ASSERT(0x34 == packet.data[4]);
    ASSERT(0x34 == packet.data[5]);
    
    packet.setXPacket(0x12, 0xAB);
    ASSERT(0x07 == packet.data[0]); // 11
    ASSERT(0x00 == packet.data[1]);
    ASSERT(0x40 == packet.data[2]);
    ASSERT(0x00 == packet.data[3]);
    ASSERT(0x12 == packet.data[4]); //B0001 0010
    ASSERT(0xAB == packet.data[5]); //B1010 1011
    ASSERT(B10111001 == packet.data[6]); // 17

    packet.setXPacket(0x56, 0x78, 0x9B);
    ASSERT(0x08 == packet.data[0]); // 18
    ASSERT(0x00 == packet.data[1]);
    ASSERT(0x40 == packet.data[2]);
    ASSERT(0x00 == packet.data[3]);
    ASSERT(0x56 == packet.data[4]); //B0101 0110
    ASSERT(0x78 == packet.data[5]); //B0111 1000
    ASSERT(0x9B == packet.data[6]); //B1001 1011
    ASSERT(B10110101 == packet.data[7]); // 25

    packet.setXPacket(0x12, 0x34, 0x56, 0x78);
    ASSERT(0x09 == packet.data[0]); // 26
    ASSERT(0x00 == packet.data[1]);
    ASSERT(0x40 == packet.data[2]);
    ASSERT(0x00 == packet.data[3]);
    ASSERT(0x12 == packet.data[4]); //B0001 0010
    ASSERT(0x34 == packet.data[5]); //B0011 0100
    ASSERT(0x56 == packet.data[6]); //B0101 0110
    ASSERT(0x78 == packet.data[7]); //B0111 1000 
    ASSERT(B00001000 == packet.data[8]); // 34

    packet.setXPacket(0xA9, 0x87, 0x65, 0x43, 0x21);
    ASSERT(0x0A == packet.data[0]); // 35
    ASSERT(0x00 == packet.data[1]);
    ASSERT(0x40 == packet.data[2]);
    ASSERT(0x00 == packet.data[3]); // 38
    ASSERT(0xA9 == packet.data[4]); //B1010 1001
    ASSERT(0x87 == packet.data[5]); //B1000 0111
    ASSERT(0x65 == packet.data[6]); //B0110 0101
    ASSERT(0x43 == packet.data[7]); //B0100 0011
    ASSERT(0x21 == packet.data[8]); //B0010 0001
    ASSERT(B00101001 == packet.data[9]); // 44

    packet.setXPacket(0xFE, 0x12, 0xDC, 0x34, 0xBA, 0x56);
    ASSERT(0x0B == packet.data[0]); // 45
    ASSERT(0x00 == packet.data[1]);
    ASSERT(0x40 == packet.data[2]);
    ASSERT(0x00 == packet.data[3]); // 48
    ASSERT(0xFE == packet.data[4]); // B1111 1110
    ASSERT(0x12 == packet.data[5]); // B0001 0010
    ASSERT(0xDC == packet.data[6]); // B1101 1100
    ASSERT(0x34 == packet.data[7]); // B0011 0100
    ASSERT(0xBA == packet.data[8]); // B1011 1010
    ASSERT(0x56 == packet.data[9]); // B0101 0110
    ASSERT(B11101000 == packet.data[10]); // 55

    packet.setXPacket(0xF0, 0xE1, 0xD2, 0xC3, 0xB4, 0xA5, 0x96);
    ASSERT(0x0C == packet.data[0]); // 56
    ASSERT(0x00 == packet.data[1]);
    ASSERT(0x40 == packet.data[2]);
    ASSERT(0x00 == packet.data[3]); // 59
    ASSERT(0xF0 == packet.data[4]); // B1111 0000
    ASSERT(0xE1 == packet.data[5]); // B1110 0001 
    ASSERT(0xD2 == packet.data[6]); // B1101 0010
    ASSERT(0xC3 == packet.data[7]); // B1100 0011
    ASSERT(0xB4 == packet.data[8]); // B1011 0100
    ASSERT(0xA5 == packet.data[9]); // B1010 0101
    ASSERT(0x96 == packet.data[10]);// B1001 0110
    ASSERT(B10000111 == packet.data[11]); // 67
}

void Z21PacketTest::testAddress() {
    UnitTest::start();

    ASSERT(0xE4 == Z21Packet::MSBLocoAddress(0xA412));
    ASSERT(0x12 == Z21Packet::LSBLocoAddress(0xA412));    

    ASSERT(0xA4 == Z21Packet::MSBAccessoryAddress(0xA412));
    ASSERT(0x12 == Z21Packet::LSBAccessoryAddress(0xA412));

    ASSERT(B00010000 == Z21Packet::MSBAccessoryPosition(0xA412)); //B1010 0100 0001 0010
    ASSERT(B01001101 == Z21Packet::LSBAccessoryPosition(0xA412, Z21_Accessory_Pos::P1));
    ASSERT(B01000000 == Z21Packet::LSBAccessoryPosition(0xA412, Z21_Accessory_Pos::ALL));

    ASSERT(0x00 == Z21Packet::MSBCVAddress(0xA412));
    ASSERT(0x12 == Z21Packet::LSBCVAddress(0xA412));
}

void Z21PacketTest::testBasicGet() {
    UnitTest::start();

    uint8_t buffer[]= {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};

    ASSERT(0x01        == Z21Packet::getByte(buffer, 0));
    ASSERT(0x4523      == Z21Packet::getLEuint16(buffer, 1));
    ASSERT(0xAB896745L == Z21Packet::getLEuint32(buffer, 2));

    ASSERT(0x6789 == Z21Packet::getBEuint16(buffer, 3));
    ASSERT(0x89ABCDEFL == Z21Packet::getBEuint32(buffer, 4));

    ASSERT( Z21Packet::hasBit(B01010101, B00011000));
    ASSERT(!Z21Packet::hasBit(B01010101, B10101010));
}


void Z21PacketTest::testPacketGet() {
    UnitTest::start();

    uint8_t buffer[]= {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0xF0, 0xE1, 0xD2, 0xC3, 0xB4, 0xA5, 0x96, 0x87};

    ASSERT(0x2301 == Z21Packet::getLength(buffer));
    ASSERT(0x6745 == Z21Packet::getHeader(buffer));
    ASSERT(0x89   == Z21Packet::getXHeader(buffer));
    ASSERT(0xAB   == Z21Packet::getDB0(buffer));
    ASSERT(0xCD   == Z21Packet::getDB1(buffer));
    ASSERT(0xEF   == Z21Packet::getDB2(buffer));
    ASSERT(0xF0   == Z21Packet::getDB3(buffer));
    ASSERT(0xE1   == Z21Packet::getDB4(buffer));
    ASSERT(0xD2   == Z21Packet::getDB5(buffer));
    ASSERT(0xC3   == Z21Packet::getDB6(buffer));
    ASSERT(0xB4   == Z21Packet::getDB7(buffer));
}

boolean Z21PacketTest::testAll() {
    UnitTest::suite("Z21 Packet");

    testBasicSet();
    testSetHeader();
    testAddress();
    
    testBasicGet();
    testPacketGet();
    
    return UnitTest::report();
}



