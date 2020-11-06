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
    pinMode(LED, OUTPUT);           // Set LED as output
    digitalWrite(LED, HIGH);        // Turn LED off
    Wire.begin();                   // Enable I²C interface
    Serial.begin(115200);           // Enable serial interface at baudrate 115200
    enableEspNow(broadcastAddress); // Enable ESP-NOW communication
}

void loop()
{
    beeboard.adcValue = readADC(ADC);                                // Read ADC value
    beeboard.voltage = readVoltage(ADC, MAX_VOLTAGE, MAX_ADC_VALUE); // Read voltage
    beeboard.messageCode = checkBattery();                           // Check battery state
    beeboard.isGsmConnected = isGsmAvailable();                      // Check GSM state
    esp_now_send(0, (uint8_t *)&beeboard, sizeof(beeboard));         // Send data
    delay(1000);                                                     // Wait for one second
}