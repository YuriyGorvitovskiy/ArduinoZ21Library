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

#include "Z21.h"
#include "Z21Const.h"

void Z21Packet::setHeader(uint16_t len, uint16_t header) {
    length = len;
    data[0] = (len & 0xFF);
    data[1] = ((len >> 8) & 0xFF);
    data[2] = (header & 0xFF);
    data[3] = ((header >> 8) & 0xFF);
}

void Z21Packet::setXPacket(uint8_t xHeader) {
    setHeader(6, Z21_LAN::X);
    data[4] = (xHeader & 0xFF);
    data[5] = (xHeader & 0xFF);
}

void Z21Packet::setXPacket(uint8_t xHeader, uint8_t xd0) {
    setHeader(7, Z21_LAN::X);
    setByte(4, xHeader);
    setByte(5, xd0);
    setByte(6, xHeader ^ xd0);
}

void Z21Packet::setXPacket(uint8_t xHeader, uint8_t xd0, uint8_t xd1) {
    setHeader(8, Z21_LAN::X);
    data[4] = (xHeader & 0xFF);
    setByte(4, xHeader);
    setByte(5, xd0);
    setByte(6, xd1);
    setByte(7, xHeader ^ xd0 ^ xd1);
}

void Z21Packet::setXPacket(uint8_t xHeader, uint8_t xd0, uint8_t xd1, uint8_t xd2) {
    setHeader(9, Z21_LAN::X);
    setByte(4, xHeader);
    setByte(5, xd0);
    setByte(6, xd1);
    setByte(7, xd2);
    setByte(8, xHeader ^ xd0 ^ xd1 ^ xd2);
}

void Z21Packet::setXPacket(uint8_t xHeader, uint8_t xd0, uint8_t xd1, uint8_t xd2, uint8_t xd3) {
    setHeader(10, Z21_LAN::X);
    setByte(4, xHeader);
    setByte(5, xd0);
    setByte(6, xd1);
    setByte(7, xd2);
    setByte(8, xd3);
    setByte(9, xHeader ^ xd0 ^ xd1 ^ xd2 ^ xd3);
}

void Z21Packet::setXPacket(uint8_t xHeader, uint8_t xd0, uint8_t xd1, uint8_t xd2, uint8_t xd3, uint8_t xd4) {
    setHeader(11, Z21_LAN::X);
    setByte(4, xHeader);
    setByte(5, xd0);
    setByte(6, xd1);
    setByte(7, xd2);
    setByte(8, xd3);
    setByte(9, xd4);
    setByte(10, xHeader ^ xd0 ^ xd1 ^ xd2 ^ xd3 ^ xd4);
}

void Z21Packet::setXPacket(uint8_t xHeader, uint8_t xd0, uint8_t xd1, uint8_t xd2, uint8_t xd3, uint8_t xd4, uint8_t xd5) {
    setHeader(12, Z21_LAN::X);
    setByte(4, xHeader);
    setByte(5, xd0);
    setByte(6, xd1);
    setByte(7, xd2);
    setByte(8, xd3);
    setByte(9, xd4);
    setByte(10, xd5);
    setByte(11, xHeader ^ xd0 ^ xd1 ^ xd2 ^ xd3 ^ xd4 ^ xd5);
}

void Z21Packet::setLEuint16(uint8_t pos, uint16_t value) {
    setByte(pos, value);
    setByte(pos + 1, value >> 8);
}

void Z21Packet::setLEuint32(uint8_t pos, uint32_t value) {
    setByte(pos,     value);
    setByte(pos + 1, value >> 8);
    setByte(pos + 2, value >> 16);
    setByte(pos + 3, value >> 24);
}

void Z21Packet::setBEuint16(uint8_t pos, uint16_t value) {
    setByte(pos,     value >> 8);
    setByte(pos + 1, value);
}

void Z21Packet::setBEuint32(uint8_t pos, uint32_t value) {
    setByte(pos,     value >> 24);
    setByte(pos + 1, value >> 16);
    setByte(pos + 2, value >> 8);
    setByte(pos + 3, value);
}

uint8_t Z21Packet::LSBAccessoryPosition(uint16_t address, uint8_t pos) {
    if (pos == Z21_Accessory_Pos::ALL)
        return ((address & 0x3C) << 2);

    return ((address & 0x3C) << 2) | 0x08 | ((address & 0x3) << 1) | (pos == Z21_Accessory_Pos::P1 ? 0x1 : 0);
}
