/**
 * @file serial.ino
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief The simplest test for serial interface
 * @version 0.1
 * @date 2020-11-05
 * 
 * @copyright Copyright (c) 2020
 * 
 */

void testSerial()
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
    Serial.print(readVoltage(ADC, MAX_VOLTAGE, MAX_ADC_VALUE));
    Serial.println("V");

    checkBattery(); // Check battery voltage

    Serial.println(); // Empty line
}