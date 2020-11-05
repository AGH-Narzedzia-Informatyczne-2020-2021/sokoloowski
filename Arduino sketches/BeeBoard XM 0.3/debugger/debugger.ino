/**
 * @file debugger.ino
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief Recieve debug informations using ESP-NOW protocol
 * @version 0.1
 * @date 2020-11-05
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <ESP8266WiFi.h>
#include <espnow.h>
#include "logstruct.hpp"

// Set up broadcast address to AA:BB:CC:DD:EE:FF
uint8_t broadcastAddress[] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
int adcValue = 0,
    messageCode = 0;
float voltage = 0.0f;
bool gsmAvailable = false;
logstruct beeboard;

void setup()
{
    Serial.begin(115200);
    Serial.println();
    enableEspNow(broadcastAddress);
    Serial.println();
}

void loop()
{
    Serial.print("ADC value: ");
    Serial.println(adcValue);

    Serial.print("Voltage:   ");
    Serial.println(voltage);

    if (gsmAvailable)
        Serial.println("GSM connected!");

    switch (messageCode)
    {
    case 1:
        Serial.println("Battery low!");
        break;

    case 2:
        Serial.println("Shutting off all systems, going to deepsleep");
        break;

    default:
        break;
    }

    Serial.println();
    delay(1000);
}