/**
 * @file battery.ino
 * @author Piotr Sokołowski (https://sokoloowski.pl)
 * @brief Battery management
 * @version 0.1
 * @date 2020-11-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

// Analog pin on ESP8266
#define ADC 0

/**
 * @brief Read raw ADC value on specified port
 * @param port number of analog port
 */
int readADC()
{
    int analogValue = 0;
    analogValue = analogRead(ADC);
    return analogValue;
}