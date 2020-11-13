/**
 * @file measurements.ino
 * @author Piotr Sokołowski (https://sokoloowski.pl)
 * @brief Getting information from sensors
 * @version 0.1
 * @date 2020-11-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <Adafruit_BMP280.h> // https://github.com/adafruit/Adafruit_BMP280_Library/archive/master.zip
#include <HX711.h>           // https://github.com/bogde/HX711/archive/master.zip
#include <DHT.h>             // https://github.com/markruys/arduino-DHT/archive/master.zip

int pressure,
    humidity;
float weight,
    temperature_in,
    temperature_out;