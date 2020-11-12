/**
 * @file gsm.ino
 * @author Piotr Sokołowski (https://sokoloowski.pl)
 * @brief GSM scripts
 * @version 0.1
 * @date 2020-11-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <Wire.h>

// I²C address for BeeBoard GSM Module
#define GSM_ADDRESS 104

bool isGsmAvailable()
{
    Wire.beginTransmission(GSM_ADDRESS);
    if (Wire.endTransmission() == 0)
    {
        // If GSM is available under specified address
        return true;
    }
    else
    {
        // If GSM is not available under specified address
        return false;
    }
}