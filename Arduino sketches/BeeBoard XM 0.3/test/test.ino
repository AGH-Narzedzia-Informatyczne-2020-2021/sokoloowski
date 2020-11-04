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
#include "./defines.hpp"

void setup()
{
    pinMode(LED, OUTPUT);    // Set LED as output
    digitalWrite(LED, HIGH); // Turn LED off
    Wire.begin();            // Enable I²C interface
    Serial.begin(115200);    // Enable serial interface at baudrate 115200
    Serial.println();        // After boot there are some chars, so let's go to new line before test
    i2c_scan();              // Submit scan
    // Post-setup message
    Serial.println("Now you can test out serial interface.");
    Serial.println("Send something via serial monitor in Arduino IDE.");
}

void loop()
{
    if (readVoltage(ADC, MAX_VOLTAGE, MAX_ADC_VALUE) <= 9.0f)
    {
        // critical voltage on batteries!
        Serial.println("Shutting off all systems, going to deepsleep");
        ESP.deepSleep(0); // Going into sleep mode until the system is restarted
    }
    else
    {
        if (readVoltage(ADC, MAX_VOLTAGE, MAX_ADC_VALUE) <= 9.5f)
        {
            // warning
            Serial.println("Battery low!");
        }

        // Let's display on monitor everything, what it gets!
        if (Serial.available() > 0)
        {
            digitalWrite(LED, LOW);            // On data recieve, turn LED on
            Serial.print(Serial.readString()); // Print recieved string
            digitalWrite(LED, HIGH);           // Turn LED off
        }

        // Read ADC value
        Serial.print("ADC value: ");
        Serial.println(readADC(ADC));

        // Read voltage
        Serial.print("Voltage: ");
        Serial.print(readVoltage(ADC, MAX_VOLTAGE, MAX_ADC_VALUE));
        Serial.println("V");

        Serial.println(); // Empty line
        delay(1000);
    }
}