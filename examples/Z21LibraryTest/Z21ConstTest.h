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
 
#ifndef __Z21_CONST_TEST_H__
#define __Z21_CONST_TEST_H__

class Z21ConstTest  {
public:  
    static void testZ21_Broadcast();
    static void testZ21_Status();
    static void testZ21_Status_EX();
    
    static void testZ21_Decoder_Mode();
    static void testZ21_Speed_Range();
    static void testZ21_Function();
    static void testZ21_Function_Action();
    
    static void testZ21_Accessory_Pos();
    static void testZ21_Accessory_State();

    static void testZ21_LAN();
    static void testZ21RX_LAN_X();
    static void testZ21RX_DB0();
    static void testZ21TX_LAN_X();

    static void testZ21_Loconet_Detector();
    
    static boolean testAll();
};


#endif //__Z21_CONST_TEST_H__

