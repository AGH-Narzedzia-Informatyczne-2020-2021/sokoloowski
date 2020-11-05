/**
 * @file pwrmgmt.ino
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief Power management functions
 * @version 0.1
 * @date 2020-11-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief Check voltage and return info code
 */
int checkBattery()
{
    if (readVoltage(ADC, MAX_VOLTAGE, MAX_ADC_VALUE) <= 9.0f)
    {
        // critical voltage on batteries!
        // Serial.println("Shutting off all systems, going to deepsleep");
        return 2;
        // ESP.deepSleep(0); // Going into sleep mode until the system is restarted
    }
    else if (readVoltage(ADC, MAX_VOLTAGE, MAX_ADC_VALUE) <= 9.5f)
    {
        if (readVoltage(ADC, MAX_VOLTAGE, MAX_ADC_VALUE) <= 9.5f)
        {
            // warning
            // Serial.println("Battery low!");
            return 1;
        }
    }
    return 0;
}