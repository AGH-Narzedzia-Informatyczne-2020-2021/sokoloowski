/**
 * @file adc.ino
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief Functions for reading ADC data
 * @version 0.1
 * @date 2020-11-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief Read raw ADC value on specified port
 * @param port number of analog port
 */
int readADC(int port)
{
    int analogValue = 0;
    analogValue = analogRead(ADC);
    return analogValue;
}

/**
 * @brief Read voltage basing on maximum voltage
 * @param port number of analog port
 * @param maxVoltage voltage, that shows maximum ADC value
 * @param maxValue maximum ADC value
 */
float readVoltage(int port, float maxVoltage, int maxValue)
{
    int adcVal = readADC(port);
    float voltage = (adcVal * maxVoltage) / maxValue;
    return voltage;
}