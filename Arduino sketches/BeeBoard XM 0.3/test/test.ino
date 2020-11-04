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
#define ADC 0
#define LED 2

void setup()
{
    pinMode(LED, OUTPUT);    // Set LED as output
    digitalWrite(LED, HIGH); // Turn LED off
    Wire.begin();            // Enable I²C interface
    Serial.begin(9600);      // Enable serial interface at baudrate 9600
    Serial.println();        // After boot there are some chars, so let's go to new line before test
    i2c_scan();              // Submit scan
    // Post-setup message
    Serial.println("Now you can test out serial interface.");
    Serial.println("Send something via serial monitor in Arduino IDE.");
}

void loop()
{
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
    Serial.print(readVoltage(ADC, 12.65f, 1024));
    Serial.println("V");
    
    Serial.println(); // Empty line
    delay(1000);
}