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

#define HX711_DT 12
#define HX711_SCK 13
#define CALIBRATION_FACTOR 21700

int pressure,
    humidity;
float weight,
    temperature_in,
    temperature_out;

void initWeight()
{
    hx711.begin(HX711_DT, HX711_SCK);
    hx711.set_scale(CALIBRATION_FACTOR);
    hx711.tare();
}