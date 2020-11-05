/**
 * @file espnow.ino
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief ESP-NOW functions
 * @version 0.1
 * @date 2020-11-05
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief Enabling ESP-NOW protocol with any important stuff
 * 
 * @param mac MAC address to set up
 */
void enableEspNow(uint8_t *mac)
{
    WiFi.mode(WIFI_OFF);
    WiFi.mode(WIFI_STA);
    Serial.println("Wi-fi enabled successfully");
    wifi_set_macaddr(STATION_IF, mac);
    Serial.println("MAC address changed successfully");
    if (esp_now_init() != 0)
    {
        Serial.println("Cannot initialize ESP-NOW");
        return;
    }
    Serial.println("ESP-NOW initialized successfully");
    esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
    esp_now_register_recv_cb(OnDataRecv);
    Serial.println("ESP-NOW configured successfully");
}

/**
 * @brief This function is triggerred on data recieve event
 * 
 * @param mac 
 * @param incomingData 
 * @param len 
 */
void OnDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len)
{
    memcpy(&beeboard, incomingData, sizeof(beeboard));
    adcValue = beeboard.adcValue;
    voltage = beeboard.voltage;
    messageCode = beeboard.messageCode;
    gsmAvailable = beeboard.isGsmConnected;
}