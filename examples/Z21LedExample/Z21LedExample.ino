#include <SPI.h>
#include <Wire.h>

#include <Scout.h>
#include <GS.h>
#include <peripherals/halRgbLed.h>
#include <backpacks/wifi/WifiModule.h>
#include <bitlash.h>
#include <lwm.h>
#include <js0n.h>
#include <Timer.h>

#include <Z21.h>

const int          SERVER_PORT = 21105;

const IPAddress    Z21_IP(192, 168, 0, 111);
const int          Z21_PORT = 21105;

GSUdpServer*       UDP = NULL;
boolean            connected = false;

uint8_t            RX_UDP_BUFFER[Z21Packet::MAX_PACKET_SIZE + 10]; // in case

int                left_to_read = 0;
uint8_t*           read_to = RX_UDP_BUFFER;

Timer              timer;

pinoccio::WifiBackpack *bp = NULL;
void setup() {
    Scout.setup();

    bp = pinoccio::WifiModule::instance.bp();
    if (bp != NULL) {
        UDP = new GSUdpServer(bp->gs);
        connected = UDP->begin(SERVER_PORT);
        timer.every(5000, refreshZ21);
    } else {
        Serial.print("No Backpack\n");   
    }

    Z21.onLocoInfo = onLocoInfo;  
}

void loop() {
    Scout.loop();
    readUDP();
    timer.update();
}

void readUDP() {
    if (!connected)
        return;

    if (left_to_read <= 0) {
        left_to_read = UDP->parsePacket();
        
        if (left_to_read <= 0) 
            return;

        if (left_to_read < Z21Packet::MIN_PACKET_SIZE || left_to_read > Z21Packet::MAX_PACKET_SIZE) {
            left_to_read = 0; // skip this packet
        }

        if (left_to_read <= 0) 
            return;
            
        read_to = RX_UDP_BUFFER;
    }
    
    int read = UDP->read(read_to, left_to_read);
    left_to_read -= read;
    read_to += read;

    if (left_to_read <= 0) {
        Z21.processPacket(RX_UDP_BUFFER);
    }
}

void refreshZ21() {
    if (UDP == NULL)
        return;

    if (!connected) {
        connected = UDP->begin(SERVER_PORT);
        if (connected) { 
            Led.blinkBlue();
            Serial.println("UDP Connected.");   
            sendPacket(Z21.logoff());
            delay(10);
            sendPacket(Z21.getStatus());
            sendPacket(Z21.getSerialNumber());
            sendPacket(Z21.getHardwareInfo());
            sendPacket(Z21.getFirmwareVersion());
            sendPacket(Z21.getVersion());
            sendPacket(Z21.setBroadcastFlags(Z21_Broadcast::STATUS_LOCO_TURNOUT));
        } else {
            Serial.println("UDP Not Connected.");   
            return;
        }
    }
    sendPacket(Z21.getLocoInfo(18));
}

void onLocoInfo(uint16_t address,
                boolean busy, boolean consist, boolean transpond,
                boolean forward, uint8_t speed, uint32_t functions) {
    if (address != 18)
        return;

    boolean f25 = ((Z21_Function::F25_BIT & functions) != 0);
    boolean f26 = ((Z21_Function::F26_BIT & functions) != 0);
    boolean f27 = ((Z21_Function::F27_BIT & functions) != 0);

    Serial.print("Loco 18 update. Speed: ");
    Serial.print(speed, DEC);
    Serial.print(", F25: ");
    Serial.print(f25);
    Serial.print(", F26: ");
    Serial.print(f26);
    Serial.print(", F27: ");
    Serial.println(f27);

    Led.setColor(f25 ? 255 : 0, f26 ? 255 : 0, f27 ? 255 : 0);

    uint8_t newSpeed = 0;
    if (f25 && f26)
        newSpeed = 96;
    else if (f25)
        newSpeed = 127;
    else if (f26)
        newSpeed = 64;
    else
        newSpeed = 0;
        
    if (newSpeed == speed && f27 == forward)
        return;
        
    sendPacket(Z21.setLocoDrive(18, f27, Z21_Speed_Range::STEPS_128, newSpeed));
}

void sendPacket(Z21Packet& packet) {
    UDP->beginPacket(Z21_IP, Z21_PORT);
    UDP->write(packet.data, packet.length);
    UDP->endPacket();
}


