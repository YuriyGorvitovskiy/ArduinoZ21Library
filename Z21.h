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

#ifndef __Z21_H__
#define __Z21_H__

#include <Arduino.h>
#include "Z21Const.h"
#include "Z21Packet.h"

class Z21Translator {
public:

    void processPacket(uint8_t *packet);

protected:
    void processXPacket(uint8_t *packet);
    void processBCPacket(uint8_t *packet);
    void processLocoInfo(uint8_t *packet);

public:
// add your handler

// Z21 Version Info
    void (*onSerialNumber)(uint32_t serial);
    void (*onHardwareInfo)(uint32_t hardware, uint32_t firmware);
    void (*onFirmwareVersion)(uint8_t major, uint8_t minor);
    void (*onGetVersion)(uint8_t xbus, uint8_t station);

// Z21 Runtime Info
    void (*onBroadcastFlags)(uint32_t flags);                           // See: const in class Z21_Broadcast

    void (*onBCStopped)();
    void (*onTrackPowerOff)();
    void (*onTrackPowerOn)();
    void (*onTrackProgrammingMode)();
    void (*onTrackShortCircuit)();
    void (*onStatusChanged)(uint8_t status);                            // See: const in class Z21_Status
    void (*onSystemStateDataChanged)(uint16_t mainCurrent,              // mA
                                     uint16_t progCurrent,              // mA
                                     uint16_t mainCurrentFiltered,      // mA
                                     uint16_t temperature,              // °C
                                     uint16_t voltageSupply,            // mV
                                     uint16_t voltageVCC,               // mV
                                     uint8_t  status,                   // See: const in class Z21_Status
                                     uint8_t  statisEX);                // See: const in class Z21_Status_EX
    void (*onUnknownCommand)();

// Layout Info
    void (*onLocoInfo)(uint16_t address,
                       boolean  busy,
                       boolean  consist,
                       boolean  transpond,
                       boolean  forward,
                       uint8_t  speed,                                  // In 128 speed range
                       uint32_t functions);                             // See: const in class Z21_Function::BIT_FXX

    void (*onAccessoryInfo)(uint16_t address, uint8_t accessoryState);  // See: const in class Z21_ACCESSORY_STATE_XXX

    void (*onLocoMode)     (uint16_t address, uint8_t decoderMode);     // See: const in class Z21_Decoder_Mode
    void (*onAccessoryMode)(uint16_t address, uint8_t decoderMode);     // See: const in class Z21_Decoder_Mode

// Programming
    void (*onCVResult)(uint16_t cvAddress, uint8_t value);

    void (*onCVAccessFailed)();
    void (*onCVAccessFailedShortCircuit)();


// Other Networks
    void (*onRailComDataChanged)(uint8_t* data, uint16_t length);
    void (*onRBusDataChanged)(uint8_t groupId, uint8_t* data, uint16_t length);
    void (*onLoconetRX)(uint8_t* data, uint16_t length);
    void (*onLoconetTX)(uint8_t* data, uint16_t length);
    void (*onLoconetFromLAN)(uint8_t* data, uint16_t length);
    void (*onLoconetDispatchAddress)(uint16_t address, uint8_t result);
    void (*onLoconetDetector)(uint8_t request, uint16_t address, uint8_t* data, uint16_t length);   // See: const in class Z21_Loconet_Detector::REQUEST_XXX

public:
// Z21 Control
    Z21Packet& getSerialNumber();
    Z21Packet& getHardwareInfo();
    Z21Packet& getVersion();
    Z21Packet& getFirmwareVersion();

    Z21Packet& getStatus();
    Z21Packet& getSystemState();

    Z21Packet& setTrackPowerOff();
    Z21Packet& setTrackPowerOn();

    Z21Packet& getBroadcastFlags();
    Z21Packet& setBroadcastFlags(uint32_t flags);                   // See: const in class Z21_Broadcast

    Z21Packet& logoff();

// Layout Control
    Z21Packet& setStop();
    Z21Packet& getLocoInfo (uint16_t address);
    Z21Packet& setLocoDrive(uint16_t address,
                            boolean  forward,
                            uint8_t  speedRange,                    // See: const in class Z21_Speed_Range
                            uint8_t  speed);
    Z21Packet& setLocoFunction(uint16_t address,
                               uint8_t  function,                   // See: const in class Z21_Function::FXX
                               uint8_t  action);                    // See: const in class Z21_Function_Action

    Z21Packet& getAccessoryInfo(uint16_t address);
    Z21Packet& setAccessory(uint16_t    address,
                            uint8_t     pos,                        // See: const in class Z21_Accessory_Pos
                            boolean     activate,
                            boolean     queue);

// Programming
    Z21Packet& getLocoMode(uint16_t address);
    Z21Packet& setLocoMode(uint16_t address, uint8_t mode);         // See: const in class Z21_Decoder_Mode

    Z21Packet& getAccessoryMode(uint16_t address);
    Z21Packet& setAccessoryMode(uint16_t address, uint8_t mode);    // See: const in class Z21_Decoder_Mode

    Z21Packet& dccReadRegister(uint8_t register);
    Z21Packet& dccWriteRegister(uint8_t register, uint8_t value);

    //CV1 = 0, ..., CV256 = 255, ..., CV1024 = 1023
    Z21Packet& dccReadCV(uint16_t cv);
    Z21Packet& dccWriteCV(uint16_t cv, uint8_t value);

    Z21Packet& mmWriteByte(uint8_t register, uint8_t value);

    //CV1 = 0, ..., CV256 = 255, ..., CV1024 = 1023
    Z21Packet& dccReadOnMainLocoCVByte (uint16_t address, uint16_t cv);
    Z21Packet& dccWriteOnMainLocoCVByte(uint16_t address, uint16_t cv, uint8_t value);
    Z21Packet& dccWriteOnMainLocoCVBit (uint16_t address, uint16_t cv, uint8_t bit, boolean value);         // See: const Z21_CV_BIT_XXX

    // See: const Z21_ACCESSORY_POS_XXX
    Z21Packet& dccReadOnMainAccessoryCVByte(uint16_t address, uint8_t pos, uint16_t cv);
    Z21Packet& dccWriteOnMainAccessoryCVByte(uint16_t address, uint8_t pos, uint16_t cv, uint8_t value);
    Z21Packet& dccWriteOnMainAccessoryCVBit (uint16_t address, uint8_t pos, uint16_t cv, uint8_t bit, boolean value);    // See: const Z21_CV_BIT_XXX

// Other Networks
    Z21Packet& railcomGetData();

    Z21Packet& rbusGetData(uint8_t group);
    Z21Packet& rbusProgramModule(uint8_t addr);

    Z21Packet& loconetDispatchAddress(uint16_t address);
    Z21Packet& loconetDetector(uint8_t type, uint16_t address);     // See: const in class Z21_Loconet_Detector::REPORT_XXX

    Z21Packet& loconetSendMessage(uint16_t messageLength);          // Z21Packet contains only 4-byte header of the message.

public:
//Access to packet created
    Z21Packet packet;

};

extern Z21Translator Z21;

#endif //__Z21_H__
