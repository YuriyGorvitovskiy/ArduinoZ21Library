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
 
#ifndef __Z21_TEST_H__
#define __Z21_TEST_H__

class Z21RXTest  {
public:  
    static void test_onSerialNumber();
    static void test_onHardwareInfo();
    static void test_onFirmwareVersion();
    static void test_onGetVersion();

    static void test_onBroadcastFlags();

    static void test_onBCStopped();
    static void test_onTrackPowerOff();
    static void test_onTrackPowerOn();
    static void test_onTrackProgrammingMode();
    static void test_onTrackShortCircuit();    
    static void test_onStatusChanged();             
    static void test_onSystemStateDataChanged();
    static void test_onUnknownCommand();

    static void test_onLocoInfo();
    static void test_onAccessoryInfo();     
    static void test_onLocoMode();
    static void test_onAccessoryMode();

    static void test_onCVResult();
    static void test_onCVAccessFailed();
    static void test_onCVAccessFailedShortCircuit();

    static void test_onRailComDataChanged();
    static void test_onRBusDataChanged();
    static void test_onLoconetRX();
    static void test_onLoconetTX();
    static void test_onLoconetFromLAN();   
    static void test_onLoconetDispatchAddress();  
    static void test_onLoconetDetector();  

    static boolean testAll();
};

class Z21TXTest  {
public:  
    static void     test_getSerialNumber();
    static void     test_getHardwareInfo();
    static void     test_getVersion();
    static void     test_getFirmwareVersion();
    
    static void     test_getStatus();
    static void     test_getSystemState();

    static void     test_setTrackPowerOff();
    static void     test_setTrackPowerOn();
    
    static void     test_getBroadcastFlags();
    static void     test_setBroadcastFlags();
    
    static void     test_logoff();
    
    static void     test_setStop();
    
    static void     test_getLocoInfo();
    static void     test_setLocoDrive();
    static void     test_setLocoFunction();
    
    static void     test_getAccessoryInfo();
    static void     test_setAccessory();
    
    static void     test_getLocoMode();
    static void     test_setLocoMode();
    
    static void     test_getAccessoryMode();
    static void     test_setAccessoryMode();
    
    static void     test_dccReadRegister();
    static void     test_dccWriteRegister();
    
    static void     test_dccReadCV();
    static void     test_dccWriteCV();
    
    static void     test_mmWriteByte();
    
    static void     test_dccReadOnMainLocoCVByte();
    static void     test_dccWriteOnMainLocoCVByte();
    static void     test_dccWriteOnMainLocoCVBit();
    
    static void     test_dccReadOnMainAccessoryCVByte();
    static void     test_dccWriteOnMainAccessoryCVByte();
    static void     test_dccWriteOnMainAccessoryCVBit();

    static void     test_railcomGetData();
    
    static void     test_rbusGetData();
    static void     test_rbusProgramModule();

    static void     test_loconetDispatchAddress();
    static void     test_loconetDetector();
    static void     test_loconetSendMessage();

    static boolean  testAll();
};


#endif //__Z21_TEST_H__

