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

void setup()
{
    // code...
}

void loop()
{
    // code...
}