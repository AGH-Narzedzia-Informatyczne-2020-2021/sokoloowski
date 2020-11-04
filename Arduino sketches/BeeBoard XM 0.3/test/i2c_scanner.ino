/**
 * @file i2c_scanner.ino
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief Scan for I2C devices connected to Your board
 * @version 0.1
 * @date 2020-11-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief Scan for I2C devices connected to Your board.
 * This function requires Wire.h library and enabled I2C
 * interface
 */
void i2c_scan()
{
    byte error, address;
    int nDevices;

    Serial.println("Scanning for I2C devices...");

    nDevices = 0;
    for (address = 1; address < 127; address++)
    {
        // The i2c_scanner uses the return value of
        // the Write.endTransmisstion to see if
        // a device did acknowledge to the address.
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0)
        {
            Serial.print("I2C device found at address 0x");
            if (address < 16)
                Serial.print("0");
            Serial.print(address, HEX);
            Serial.println("  !");

            nDevices++;
        }
        else if (error == 4)
        {
            Serial.print("Unknown error at address 0x");
            if (address < 16)
                Serial.print("0");
            Serial.println(address, HEX);
        }
    }
    if (nDevices == 0)
        Serial.println("No I2C devices found\n");
    else
        Serial.println("Scan complete\n");
}