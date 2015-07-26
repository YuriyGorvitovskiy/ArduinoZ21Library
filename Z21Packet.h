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

#ifndef __Z21_PACKET_H__
#define __Z21_PACKET_H__

class Z21Packet {
public:
    static const int MIN_PACKET_SIZE = 4;
    static const int MAX_PACKET_SIZE = 64;

public:
    uint16_t length;
    uint8_t  data[Z21Packet::MAX_PACKET_SIZE];

    void setHeader(uint16_t length, uint16_t header);
    void setXPacket(uint8_t xHeader);
    void setXPacket(uint8_t xHeader, uint8_t xd0);
    void setXPacket(uint8_t xHeader, uint8_t xd0, uint8_t xd1);
    void setXPacket(uint8_t xHeader, uint8_t xd0, uint8_t xd1, uint8_t xd2);
    void setXPacket(uint8_t xHeader, uint8_t xd0, uint8_t xd1, uint8_t xd2, uint8_t xd3);
    void setXPacket(uint8_t xHeader, uint8_t xd0, uint8_t xd1, uint8_t xd2, uint8_t xd3, uint8_t xd4);
    void setXPacket(uint8_t xHeader, uint8_t xd0, uint8_t xd1, uint8_t xd2, uint8_t xd3, uint8_t xd4, uint8_t xd5);

    void setByte (uint8_t pos, int       value)  {data[pos] = value & 0xFF;}

    void setLEuint16(uint8_t pos, uint16_t value);
    void setLEuint32(uint8_t pos, uint32_t value);

    void setBEuint16(uint8_t pos, uint16_t value);
    void setBEuint32(uint8_t pos, uint32_t value);

    static uint8_t MSBLocoAddress(uint16_t address) {return ((address >> 8) & 0x3F) | 0xC0;}
    static uint8_t LSBLocoAddress(uint16_t address) {return address & 0xFF;}

    static uint8_t MSBAccessoryAddress(uint16_t address) {return (address >> 8) & 0xFF;}
    static uint8_t LSBAccessoryAddress(uint16_t address) {return address & 0xFF;}

    static uint8_t MSBAccessoryPosition(uint16_t address) {return (address & 0x7C0) >> 6;}
    static uint8_t LSBAccessoryPosition(uint16_t address, uint8_t pos);

    static uint8_t MSBCVAddress(uint16_t address) {return (address >> 8) & 0x03;}
    static uint8_t LSBCVAddress(uint16_t address) {return address & 0xFF;}

    static uint8_t  getByte    (uint8_t *data, uint8_t pos)  {return data[pos];}
    static uint16_t getLEuint16(uint8_t *data, uint8_t pos)  {return ((uint16_t)data[pos]) | (((uint16_t)data[pos + 1]) << 8);}
    static uint32_t getLEuint32(uint8_t *data, uint8_t pos)  {return ((uint32_t)data[pos]) | (((uint32_t)data[pos + 1]) << 8) | (((uint32_t)data[pos + 2]) << 16) | (((uint32_t)data[pos + 3]) << 24);};

    static uint16_t getBEuint16(uint8_t *data, uint8_t pos)  {return ((uint16_t)data[pos + 1]) | (((uint16_t)data[pos]) << 8);}
    static uint32_t getBEuint32(uint8_t *data, uint8_t pos)  {return ((uint32_t)data[pos + 3]) | (((uint32_t)data[pos + 2]) << 8) | (((uint32_t)data[pos + 1]) << 16) | (((uint32_t)data[pos]) << 24);};

    static uint16_t getLength(uint8_t *data)  { return getLEuint16(data, 0);}
    static uint16_t getHeader(uint8_t *data)  { return getLEuint16(data, 2);}
    static uint8_t  getXHeader(uint8_t *data) { return data[4];}
    static uint8_t  getDB0(uint8_t *data)     { return data[5];}
    static uint8_t  getDB1(uint8_t *data)     { return data[6];}
    static uint8_t  getDB2(uint8_t *data)     { return data[7];}
    static uint8_t  getDB3(uint8_t *data)     { return data[8];}
    static uint8_t  getDB4(uint8_t *data)     { return data[9];}
    static uint8_t  getDB5(uint8_t *data)     { return data[10];}
    static uint8_t  getDB6(uint8_t *data)     { return data[11];}
    static uint8_t  getDB7(uint8_t *data)     { return data[12];}

    static boolean  hasBit(uint8_t data, uint8_t mask)  { return (data & mask) != 0;}
};

#endif //__Z21_PACKET_H__
