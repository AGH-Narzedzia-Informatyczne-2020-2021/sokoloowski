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

// ADC pin on ESP8266
#define ADC 0

// Maximum voltage that board can read
#define MAX_VOLTAGE 12.6f

// Maximum ADC value
#define MAX_ADC_VALUE 1024

// Voltage for "battery low" notification
#define BATTERY_WARN 9.5f

// Voltage to power off device
#define BATTERY_EMPTY 9.0f

#define STATUS_BATTERY_GOOD 10
#define STATUS_BATTERY_LOW 11
#define STATUS_BATTERY_EMPTY 12

/**
 * @brief Read raw ADC value on specified port
 * 
 * @return int ADC value
 */
int readADC()
{
    int analogValue = 0;
    analogValue = analogRead(ADC);
    return analogValue;
}

/**
 * @brief Read voltage basing on maximum voltage
 * 
 * @return float Power supply voltage
 */
float readVoltage()
{
    int adcVal = readADC(port);
    float voltage = (adcVal * MAX_VOLTAGE) / MAX_ADC_VALUE;
    return voltage;
}

/**
 * @brief Check battery voltage and notify about battery state
 * 
 */
int batteryState()
{
    if (readVoltage() <= BATTERY_EMPTY)
    {
        return STATUS_BATTERY_EMPTY;
    }
    else if (readVoltage() <= BATTERY_WARN)
    {
        return STATUS_BATTERY_LOW;
    }
    else
    {
        return STATUS_BATTERY_GOOD;
    }
}