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

#include <Wire.h>
#include <Adafruit_BMP280.h> // https://github.com/adafruit/Adafruit_BMP280_Library/archive/master.zip
#include "defines.hpp"

Adafruit_BMP280 bmp;

void setup()
{
    pinMode(LED, OUTPUT);    // Set LED as output
    digitalWrite(LED, HIGH); // Turn LED off
    Wire.begin();            // Enable I²C interface
    Serial.begin(115200);    // Enable serial interface at baudrate 115200
    Serial.println();        // After boot there are some chars, so let's go to new line before test
    i2c_scan();              // Submit scan

    // Set up BMP280 sensor
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL);
    bmp.begin();
    Serial.println("BMP280 sensor enabled");    

    // Post-setup message
    Serial.println("Now you can test out serial interface.");
    Serial.println("Send something via serial monitor in Arduino IDE.");
}

void loop()
{
    if (Serial.available() > 0)
    {
        digitalWrite(LED, LOW);            // On data recieve, turn LED on
        Serial.print(Serial.readString()); // Print recieved string
        digitalWrite(LED, HIGH);           // Turn LED off
    }

    // Read ADC value
    Serial.print("ADC value:   ");
    Serial.println(readADC(ADC));

    // Read voltage
    Serial.print("Voltage:     ");
    Serial.print(readVoltage(ADC, MAX_VOLTAGE, MAX_ADC_VALUE));
    Serial.println("V");

    // Read BMP280 sensor data
    Serial.print("Pressure:    ");
    Serial.print(bmp.readPressure() / 100);
    Serial.println(" hPa");
    Serial.print("Temperature: ");
    Serial.print(bmp.readTemperature());
    Serial.println("*C");

    // Check battery voltage
    switch (checkBattery())
    {
    case 1:
        Serial.println("Battery low!");
        break;

    case 2:
        Serial.println("Shutting off all systems, going to deepsleep");
        // ESP.deepSleep(0);
        break;

    default:
        break;
    }

    Serial.println(); // Empty line
    delay(1000);      // Wait for one second
}