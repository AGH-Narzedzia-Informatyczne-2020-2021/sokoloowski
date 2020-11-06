/**
 * @file test-remote.ino
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief Test file for BeeBoard XM 0.3
 * @version 0.1
 * @date 2020-11-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

void remoteSetup()
{
    pinMode(LED, OUTPUT);           // Set LED as output
    digitalWrite(LED, HIGH);        // Turn LED off
    Wire.begin();                   // Enable I²C interface
    Serial.begin(115200);           // Enable serial interface at baudrate 115200
    enableEspNow(broadcastAddress); // Enable ESP-NOW communication
}

void remoteLoop()
{
    beeboard.adcValue = readADC(ADC);                                // Read ADC value
    beeboard.voltage = readVoltage(ADC, MAX_VOLTAGE, MAX_ADC_VALUE); // Read voltage
    beeboard.messageCode = checkBattery();                           // Check battery state
    beeboard.isGsmConnected = isGsmAvailable();                      // Check GSM state
    esp_now_send(0, (uint8_t *)&beeboard, sizeof(beeboard));         // Send data
    delay(1000);                                                     // Wait for one second
}