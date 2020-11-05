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
int adcValue,
    messageCode;
float voltage;
logstruct beeboard;

void OnDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len)
{
    // code...
}

void setup()
{
    Serial.begin(115200);
    Serial.println();
    WiFi.mode(WIFI_OFF);
    WiFi.mode(WIFI_STA);
    Serial.println("Wi-fi enabled successfully");
    wifi_set_macaddr(STATION_IF, broadcastAddress);
    Serial.println("MAC address changed successfully");
    if (!esp_now_init())
    {
        Serial.println("Cannot initialize ESP-NOW");
        return;
    }
    Serial.println("ESP-NOW initialized successfully");
    esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
    esp_now_register_recv_cb(OnDataRecv);
    Serial.println("ESP-NOW configured successfully");
    Serial.println();
}

void loop()
{
    Serial.print("ADC value: ");
    Serial.println(adcValue);

    Serial.print("Voltage:   ");
    Serial.println(voltage);

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
}