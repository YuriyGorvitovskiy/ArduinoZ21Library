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

Z21Translator Z21;

Z21Packet& Z21Translator::getSerialNumber() {
    packet.setHeader(4, Z21_LAN::GET_SERIAL_NUMBER);
    return packet;
}

Z21Packet& Z21Translator::getHardwareInfo() {
    packet.setHeader(4, Z21_LAN::GET_HWINFO);
    return packet;
}

Z21Packet& Z21Translator::getVersion() {
    packet.setXPacket(Z21TX_LAN_X::GET_VERSION, Z21TX_DB0::GET_VERSION);
    return packet;
}

Z21Packet& Z21Translator::getFirmwareVersion() {
    packet.setXPacket(Z21TX_LAN_X::GET_FIRMWARE_VERSION, Z21TX_DB0::GET_FIRMWARE_VERSION);
    return packet;
}

Z21Packet& Z21Translator::getStatus() {
    packet.setXPacket(Z21TX_LAN_X::GET_STATUS, Z21TX_DB0::GET_STATUS);
    return packet;
}

Z21Packet& Z21Translator::getSystemState() {
    packet.setHeader(4, Z21_LAN::SYSTEMSTATE_GETDATA);
    return packet;
}

Z21Packet& Z21Translator::railcomGetData() {
    packet.setHeader(4, Z21_LAN::RAILCOM_GETDATA);
    return packet;
}

Z21Packet& Z21Translator::setTrackPowerOff() {
    packet.setXPacket(Z21TX_LAN_X::SET_TRACK_POWER_OFF, Z21TX_DB0::SET_TRACK_POWER_OFF);
    return packet;
}

Z21Packet& Z21Translator::setTrackPowerOn() {
    packet.setXPacket(Z21TX_LAN_X::SET_TRACK_POWER_ON, Z21TX_DB0::SET_TRACK_POWER_ON);
    return packet;
}

Z21Packet& Z21Translator::getBroadcastFlags() {
    packet.setHeader(4, Z21_LAN::GET_BROADCASTFLAGS);
    return packet;
}

Z21Packet& Z21Translator::setBroadcastFlags(uint32_t flags) {
    packet.setHeader(8, Z21_LAN::SET_BROADCASTFLAGS);
    packet.setLEuint32(4, flags);
    return packet;
}

Z21Packet& Z21Translator::logoff() {
    packet.setHeader(4, Z21_LAN::LOGOFF);
    return packet;
}

Z21Packet& Z21Translator::setStop() {
    packet.setXPacket(Z21TX_LAN_X::SET_STOP);
    return packet;
}

Z21Packet& Z21Translator::getLocoInfo (uint16_t address) {
    packet.setXPacket(Z21TX_LAN_X::GET_LOCO_INFO,
                      Z21TX_DB0::GET_LOCO_INFO,
                      Z21Packet::MSBLocoAddress(address),
                      Z21Packet::LSBLocoAddress(address));
    return packet;
}

Z21Packet& Z21Translator::setLocoDrive(uint16_t address,
                                       boolean  forward,
                                       uint8_t  speedRange,
                                       uint8_t  speed) {
    packet.setXPacket(Z21TX_LAN_X::SET_LOCO_DRIVE,
                      Z21TX_DB0::SET_LOCO_DRIVE | (speedRange & 0xF),
                      Z21Packet::MSBLocoAddress(address),
                      Z21Packet::LSBLocoAddress(address),
                      ((forward ? 0x80 : 0x00) | (speed & 0x7F)));
    return packet;
}

Z21Packet& Z21Translator::setLocoFunction(uint16_t address,
                                          uint8_t  function,
                                          uint8_t  action) {
    packet.setXPacket(Z21TX_LAN_X::SET_LOCO_FUNCTION,
                      Z21TX_DB0::SET_LOCO_FUNCTION,
                      Z21Packet::MSBLocoAddress(address),
                      Z21Packet::LSBLocoAddress(address),
                      ((action & 0x03) << 6) | (function & 0x1F));
    return packet;
}

Z21Packet& Z21Translator::getAccessoryInfo(uint16_t address) {
    packet.setXPacket(Z21TX_LAN_X::GET_TURNOUT_INFO,
                      Z21Packet::MSBAccessoryAddress(address),
                      Z21Packet::LSBAccessoryAddress(address));
    return packet;
}

Z21Packet& Z21Translator::setAccessory(uint16_t    address,
                                       uint8_t     pos,
                                       boolean     activate,
                                       boolean     queue) {
    packet.setXPacket(Z21TX_LAN_X::SET_TURNOUT,
                      Z21Packet::MSBAccessoryAddress(address),
                      Z21Packet::LSBAccessoryAddress(address),
                      0x80 | (queue ? 0x20: 0) | (activate ? 0x08: 0) | (pos == Z21_Accessory_Pos::P1 ? 0x01 : 0)
                      );
    return packet;
}

Z21Packet& Z21Translator::getLocoMode(uint16_t address) {
    packet.setHeader(6, Z21_LAN::GET_LOCOMODE);
    packet.setBEuint16(4, address);
    return packet;
}

Z21Packet& Z21Translator::setLocoMode(uint16_t address, uint8_t mode) {
    packet.setHeader(7, Z21_LAN::SET_LOCOMODE);
    packet.setBEuint16(4, address);
    packet.setByte(6, mode);
    return packet;
}

Z21Packet& Z21Translator::getAccessoryMode(uint16_t address) {
    packet.setHeader(6, Z21_LAN::GET_TURNOUTMODE);
    packet.setBEuint16(4, address);
    return packet;
}

Z21Packet& Z21Translator::setAccessoryMode(uint16_t address, uint8_t mode) {
    packet.setHeader(7, Z21_LAN::SET_TURNOUTMODE);
    packet.setBEuint16(4, address);
    packet.setByte(6, mode);
    return packet;
}

Z21Packet& Z21Translator::dccReadRegister(uint8_t reg) {
    packet.setXPacket(Z21TX_LAN_X::DCC_READ_REGISTER,
                      Z21TX_DB0::DCC_READ_REGISTER,
                      reg);
    return packet;
}

Z21Packet& Z21Translator::dccWriteRegister(uint8_t reg, uint8_t value) {
    packet.setXPacket(Z21TX_LAN_X::DCC_WRITE_REGISTER,
                      Z21TX_DB0::DCC_WRITE_REGISTER,
                      reg,
                      value);
    return packet;
}

Z21Packet& Z21Translator::dccReadCV(uint16_t cv) {
    packet.setXPacket(Z21TX_LAN_X::CV_READ,
                      Z21TX_DB0::CV_READ,
                      Z21Packet::MSBCVAddress(cv),
                      Z21Packet::LSBCVAddress(cv));
    return packet;
}

Z21Packet& Z21Translator::dccWriteCV(uint16_t cv, uint8_t value) {
    packet.setXPacket(Z21TX_LAN_X::CV_WRITE,
                      Z21TX_DB0::CV_WRITE,
                      Z21Packet::MSBCVAddress(cv),
                      Z21Packet::LSBCVAddress(cv),
                      value);
    return packet;
}

Z21Packet& Z21Translator::mmWriteByte(uint8_t reg, uint8_t value) {
    packet.setXPacket(Z21TX_LAN_X::MM_WRITE_BYTE,
                      Z21TX_DB0::MM_WRITE_BYTE,
                      0,
                      reg,
                      value);
    return packet;
}

Z21Packet& Z21Translator::dccReadOnMainLocoCVByte (uint16_t address, uint16_t cv) {
    packet.setXPacket(Z21TX_LAN_X::CV_POM_READ_BYTE,
                      Z21TX_DB0::CV_POM_READ_BYTE,
                      Z21Packet::MSBLocoAddress(address),
                      Z21Packet::LSBLocoAddress(address),
                      Z21Packet::MSBCVAddress(cv) | Z21TX_Option::CV_POM_READ_BYTE,
                      Z21Packet::LSBCVAddress(cv),
                      0);
    return packet;
}
Z21Packet& Z21Translator::dccWriteOnMainLocoCVByte(uint16_t address, uint16_t cv, uint8_t value) {
    packet.setXPacket(Z21TX_LAN_X::CV_POM_WRITE_BYTE,
                      Z21TX_DB0::CV_POM_WRITE_BYTE,
                      Z21Packet::MSBLocoAddress(address),
                      Z21Packet::LSBLocoAddress(address),
                      Z21Packet::MSBCVAddress(cv) | Z21TX_Option::CV_POM_WRITE_BYTE,
                      Z21Packet::LSBCVAddress(cv),
                      value);
    return packet;
}
Z21Packet& Z21Translator::dccWriteOnMainLocoCVBit (uint16_t address, uint16_t cv, uint8_t bit, boolean value) {
    packet.setXPacket(Z21TX_LAN_X::CV_POM_WRITE_BIT,
                      Z21TX_DB0::CV_POM_WRITE_BIT,
                      Z21Packet::MSBLocoAddress(address),
                      Z21Packet::LSBLocoAddress(address),
                      Z21Packet::MSBCVAddress(cv) | Z21TX_Option::CV_POM_WRITE_BIT,
                      Z21Packet::LSBCVAddress(cv),
                      (value ? 0x08 : 0) | (bit & 0x7));
    return packet;
}

Z21Packet& Z21Translator::dccReadOnMainAccessoryCVByte(uint16_t address, uint8_t pos, uint16_t cv) {
    packet.setXPacket(Z21TX_LAN_X::CV_POM_ACCESSORY_READ_BYTE,
                      Z21TX_DB0::CV_POM_ACCESSORY_READ_BYTE,
                      Z21Packet::MSBAccessoryPosition(address),
                      Z21Packet::LSBAccessoryPosition(address, pos),
                      Z21Packet::MSBCVAddress(cv) | Z21TX_Option::CV_POM_ACCESSORY_READ_BYTE,
                      Z21Packet::LSBCVAddress(cv),
                      0);
    return packet;
}

Z21Packet& Z21Translator::dccWriteOnMainAccessoryCVByte(uint16_t address, uint8_t pos, uint16_t cv, uint8_t value) {
    packet.setXPacket(Z21TX_LAN_X::CV_POM_ACCESSORY_WRITE_BYTE,
                      Z21TX_DB0::CV_POM_ACCESSORY_WRITE_BYTE,
                      Z21Packet::MSBAccessoryPosition(address),
                      Z21Packet::LSBAccessoryPosition(address, pos),
                      Z21Packet::MSBCVAddress(cv) | Z21TX_Option::CV_POM_ACCESSORY_WRITE_BYTE,
                      Z21Packet::LSBCVAddress(cv),
                      value);
    return packet;
}

Z21Packet& Z21Translator::dccWriteOnMainAccessoryCVBit (uint16_t address, uint8_t pos, uint16_t cv, uint8_t bit, boolean value) {
    packet.setXPacket(Z21TX_LAN_X::CV_POM_ACCESSORY_WRITE_BIT,
                      Z21TX_DB0::CV_POM_ACCESSORY_WRITE_BIT,
                      Z21Packet::MSBAccessoryPosition(address),
                      Z21Packet::LSBAccessoryPosition(address, pos),
                      Z21Packet::MSBCVAddress(cv) | Z21TX_Option::CV_POM_ACCESSORY_WRITE_BIT,
                      Z21Packet::LSBCVAddress(cv),
                      (value ? 0x08 : 0) | (bit & 0x7));
    return packet;
}

Z21Packet& Z21Translator::rbusGetData(uint8_t group) {
    packet.setHeader(5, Z21_LAN::RMBUS_GETDATA);
    packet.setByte(4, group);
    return packet;
}

Z21Packet& Z21Translator::rbusProgramModule(uint8_t addr) {
    packet.setHeader(5, Z21_LAN::RMBUS_PROGRAMMODULE);
    packet.setByte(4, addr);
    return packet;
}

Z21Packet& Z21Translator::loconetDispatchAddress(uint16_t address) {
    packet.setHeader(6, Z21_LAN::LOCONET_DISPATCH_ADDR);
    packet.setLEuint16(4, address);
    return packet;
}

Z21Packet& Z21Translator::loconetDetector(uint8_t type, uint16_t address) {
    packet.setHeader(7, Z21_LAN::LOCONET_DETECTOR);
    packet.setByte(4, type);
    packet.setLEuint16(5, address);
    return packet;
}

Z21Packet& Z21Translator::loconetSendMessage(uint16_t messageLength) {
    packet.setHeader(4 + messageLength, Z21_LAN::LOCONET_FROM_LAN);
    return packet;
}

void Z21Translator::processPacket(uint8_t* data) {
    switch (Z21Packet::getHeader(data)) {
        case Z21_LAN::X:
            processXPacket(data);
            break;
        case Z21_LAN::GET_SERIAL_NUMBER:
            if (onSerialNumber != NULL)
                onSerialNumber(Z21Packet::getLEuint32(data, 4));
            break;
        case Z21_LAN::GET_HWINFO:
            if (onHardwareInfo != NULL)
                onHardwareInfo(Z21Packet::getLEuint32(data, 4), Z21Packet::getLEuint32(data, 8));
            break;
        case Z21_LAN::GET_BROADCASTFLAGS:
            if (onBroadcastFlags != NULL)
                onBroadcastFlags(Z21Packet::getLEuint32(data, 4));
            break;
        case Z21_LAN::GET_LOCOMODE:
            if (onLocoMode != NULL)
                onLocoMode(Z21Packet::getBEuint16(data, 4), Z21Packet::getByte(data, 6));
            break;
        case Z21_LAN::GET_TURNOUTMODE:
            if (onAccessoryMode != NULL)
                onAccessoryMode(Z21Packet::getBEuint16(data, 4), Z21Packet::getByte(data, 6));
            break;
        case Z21_LAN::RMBUS_DATACHANGED:
            if (onRBusDataChanged != NULL)
                onRBusDataChanged(Z21Packet::getByte(data, 4), data + 5, Z21Packet::getLength(data) - 5);
            break;
        case Z21_LAN::RAILCOM_DATACHANGED:
            if (onRailComDataChanged != NULL)
                onRailComDataChanged(data + 4, Z21Packet::getLength(data) - 4);
            break;
        case Z21_LAN::SYSTEMSTATE_DATACHANGED:
            if (onSystemStateDataChanged != NULL)
                onSystemStateDataChanged(Z21Packet::getLEuint16(data, 4),
                                         Z21Packet::getLEuint16(data, 6),
                                         Z21Packet::getLEuint16(data, 8),
                                         Z21Packet::getLEuint16(data, 10),
                                         Z21Packet::getLEuint16(data, 12),
                                         Z21Packet::getLEuint16(data, 14),
                                         Z21Packet::getByte(data, 16),
                                         Z21Packet::getByte(data, 17));
            break;
        case Z21_LAN::LOCONET_Z21_RX:
            if (onLoconetRX != NULL)
                onLoconetRX(data + 4, Z21Packet::getLength(data) - 4);
            break;
        case Z21_LAN::LOCONET_Z21_TX:
            if (onLoconetTX != NULL)
                onLoconetTX(data + 4, Z21Packet::getLength(data) - 4);
            break;
        case Z21_LAN::LOCONET_FROM_LAN:
            if (onLoconetFromLAN != NULL)
                onLoconetFromLAN(data + 4, Z21Packet::getLength(data) - 4);
            break;
        case Z21_LAN::LOCONET_DISPATCH_ADDR:
            if (onLoconetDispatchAddress != NULL)
                onLoconetDispatchAddress(Z21Packet::getLEuint16(data, 4), Z21Packet::getByte(data, 6));
            break;
        case Z21_LAN::LOCONET_DETECTOR:
            if (onLoconetDetector != NULL)
                onLoconetDetector(Z21Packet::getByte(data, 4), Z21Packet::getLEuint16(data, 5), data + 7, Z21Packet::getLength(data) - 7);
            break;
        default:
            break;
    }
}

void Z21Translator::processXPacket(uint8_t* data) {
    switch (Z21Packet::getXHeader(data)) {
        case Z21RX_LAN_X::BC:
            processBCPacket(data);
            break;
        case Z21RX_LAN_X::TURNOUT_INFO:
            if (onAccessoryInfo != NULL)
                onAccessoryInfo(Z21Packet::getBEuint16(data, 5), Z21Packet::getByte(data, 7));
            break;
        case Z21RX_LAN_X::STATUS_CHANGED:
            if (onStatusChanged != NULL && Z21Packet::getDB0(data) == Z21RX_DB0::STATUS_CHANGED)
                onStatusChanged(Z21Packet::getDB1(data));
            break;
        case Z21RX_LAN_X::GET_VERSION:
            if (onGetVersion != NULL && Z21Packet::getDB0(data) == Z21RX_DB0::GET_VERSION)
                onGetVersion(Z21Packet::getDB1(data), Z21Packet::getDB2(data));
            break;
        case Z21RX_LAN_X::CV_RESULT:
            if (onCVResult != NULL && Z21Packet::getDB0(data) == Z21RX_DB0::CV_RESULT)
                onCVResult(Z21Packet::getBEuint16(data, 6), Z21Packet::getDB3(data));
            break;
        case Z21RX_LAN_X::BC_STOPPED:
            if (onBCStopped != NULL)
                onBCStopped();
            break;
        case Z21RX_LAN_X::LOCO_INFO:
            if (onLocoInfo != NULL)
                processLocoInfo(data);
            break;
        case Z21RX_LAN_X::GET_FIRMWARE_VERSION:
            if (onFirmwareVersion != NULL && Z21Packet::getDB0(data) == Z21RX_DB0::GET_FIRMWARE_VERSION)
                onFirmwareVersion(Z21Packet::getDB1(data), Z21Packet::getDB2(data));
            break;
        default:
            break;
    }
}

void Z21Translator::processLocoInfo(uint8_t* data) {
    uint16_t addr = Z21Packet::getBEuint16(data, 5) & 0x3FFF;

    uint8_t XDB2 = Z21Packet::getDB2(data);
    uint8_t XDB3 = Z21Packet::getDB3(data);
    uint8_t XDB4 = Z21Packet::getDB4(data);
    uint32_t XDB5 = Z21Packet::getDB5(data);
    uint32_t XDB6 = Z21Packet::getDB6(data);
    uint32_t XDB7 = Z21Packet::getDB7(data);

    boolean busy      = Z21Packet::hasBit(XDB2, 0x08);
    boolean forward   = Z21Packet::hasBit(XDB3, 0x80);
    boolean consist   = Z21Packet::hasBit(XDB4, 0x40);
    boolean transpond = Z21Packet::hasBit(XDB4, 0x20);

    int speed = (XDB3 & 0x7F);
    if (speed > 1) {
        int speedFormat = (XDB2 & 0x7);
        if (speedFormat == 0) // 14 steps
            speed = (speed << 3);
        if (speedFormat == 2) // 28 steps
            speed = (speed << 2);
        // if (speedFormat == 4) // 128 steps
    }

    uint32_t functions = ((XDB4 & 0x10)>>4);//F0
    functions |= ((XDB4 & 0x0F)<<1);        //F4 - F1
    functions |= (XDB5 << 5);               //F5 - F12
    functions |= (XDB6 << 13);              //F13 - F20
    functions |= (XDB7 << 21);              //F21 - F28

    onLocoInfo(addr, busy, consist, transpond, forward, speed, functions);
}

void Z21Translator::processBCPacket(uint8_t* data) {
    switch (Z21Packet::getDB0(data)) {
        case Z21RX_DB0::BC_TRACK_POWER_OFF:
            if (onTrackPowerOff != NULL)
                onTrackPowerOff();
            break;

        case Z21RX_DB0::BC_TRACK_POWER_ON:
            if (onTrackPowerOn != NULL)
                onTrackPowerOn();
            break;

        case Z21RX_DB0::BC_PROGRAMMING_MODE:
            if (onTrackProgrammingMode != NULL)
                onTrackProgrammingMode();
            break;

        case Z21RX_DB0::BC_TRACK_SHORT_CIRCUIT:
            if (onTrackShortCircuit != NULL)
                onTrackShortCircuit();
            break;

        case Z21RX_DB0::CV_NACK_SC:
            if (onCVAccessFailedShortCircuit != NULL)
                onCVAccessFailedShortCircuit();
            break;

        case Z21RX_DB0::CV_NACK:
            if (onCVAccessFailed != NULL)
                onCVAccessFailed();
            break;

        case Z21RX_DB0::UNKNOWN_COMMAND:
            if (onUnknownCommand != NULL)
                onUnknownCommand();
            break;

        default:
            break;
    }
}
