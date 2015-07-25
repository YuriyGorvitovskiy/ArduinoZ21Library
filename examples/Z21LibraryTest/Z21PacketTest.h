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
 
#ifndef __Z21_PACKET_TEST_H__
#define __Z21_PACKET_TEST_H__

class Z21PacketTest  {
public:

    static void testBasicSet();
    static void testSetHeader();
    static void testAddress();

    static void testBasicGet();
    static void testPacketGet();


    static boolean testAll();
};


#endif //__Z21_PACKET_TEST_H__

