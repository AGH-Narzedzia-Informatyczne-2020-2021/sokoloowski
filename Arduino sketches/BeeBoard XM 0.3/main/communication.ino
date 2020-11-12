/**
 * @file communication.ino
 * @author Piotr Sokołowski (https://sokoloowski.pl)
 * @brief ESP-NOW config, handlers and communication
 * @version 0.1
 * @date 2020-11-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <ESP8266WiFi.h>
#include <espnow.h>
#include "datastruct.hpp"

// Set up broadcast address to AA:BB:CC:DD:EE:FF
uint8_t broadcastAddress[] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};

/**
 * @brief Initializing ESP-NOW connection
 * 
 */
void espNowInit()
{
    WiFi.mode(WIFI_OFF);
    WiFi.mode(WIFI_STA);
    if (isGsmAvailable())
    {
        wifi_set_macaddr(STATION_IF, broadcastAddress);
        if (esp_now_init() != 0)
        {
            return;
        }
        esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
        esp_now_register_recv_cb(OnDataRecv);
    }
    else
    {
        WiFi.setOutputPower(20);
        if (esp_now_init() != 0)
        {
            return;
        }
        esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
        esp_now_register_send_cb(OnDataSent);
        esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
    }
}

