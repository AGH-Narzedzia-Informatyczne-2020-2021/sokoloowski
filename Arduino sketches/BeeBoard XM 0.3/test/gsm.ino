/**
 * @file gsm.ino
 * @author Piotr Sokołowski
 * @brief GSM features as detecting and communication
 * @version 0.1
 * @date 2020-11-05
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief Detecting BeeBoard GSM module
 * 
 * @return true when GSM module is connected
 * @return false when GSM module is disconnected
 */
bool isGsmAvailable()
{
    int gsmAddr = 118;
    Wire.beginTransmission(gsmAddr);
    if (Wire.endTransmission() == 0)
    {
        // If GSM is available under specified address
        return true;
    }
    else
    {
        // If GSM is not available under specified address
        return false;
    }
}