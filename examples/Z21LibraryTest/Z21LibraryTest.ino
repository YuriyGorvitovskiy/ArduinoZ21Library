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
#include <Z21.h>
#include <UnitTest.h>

#include "Z21ConstTest.h"
#include "Z21PacketTest.h"
#include "Z21Test.h"

#define LED (13)

boolean success = true;

void setup() {
   Serial.begin(115200);
   
   //Teensy 3.0 required some time before Serial become functional.
   delay(500);
   
   success &= Z21ConstTest::testAll();
   success &= Z21PacketTest::testAll();
   success &= Z21RXTest::testAll();
   success &= Z21TXTest::testAll();

   pinMode(LED, OUTPUT);
}

void loop() {
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, success ? HIGH : LOW);
    delay(200);
}
