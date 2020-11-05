/**
 * @file test.ino
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief Test file for BeeBoard XM 0.3
 * @version 0.1
 * @date 2020-11-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Wire.h>
#include "defines.hpp"
#include "logstruct.hpp"

// Set up broadcast address to AA:BB:CC:DD:EE:FF
uint8_t broadcastAddress[] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};

logstruct beeboard;

void setup()
{
    pinMode(LED, OUTPUT);    // Set LED as output
    digitalWrite(LED, HIGH); // Turn LED off
    Wire.begin();            // Enable I²C interface
    Serial.begin(115200);    // Enable serial interface at baudrate 115200
    enableEspNow(BroadcastAddress);
    // Serial.println();        // After boot there are some chars, so let's go to new line before test
    // i2c_scan();              // Submit scan
    // Post-setup message
    // Serial.println("Now you can test out serial interface.");
    // Serial.println("Send something via serial monitor in Arduino IDE.");
}

void loop()
{
    beeboard.adcValue = readADC(ADC);
    beeboard.voltage = readVoltage(ADC, MAX_VOLTAGE, MAX_ADC_VALUE);
    beeboard.messageCode = checkBattery();
    esp_now_send(0, (uint8_t *)&beeboard, sizeof(beeboard));
    delay(1000);      // Wait for one second
}