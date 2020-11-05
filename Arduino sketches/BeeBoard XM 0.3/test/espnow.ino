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
 * @param mac Reciever's MAC address
 */
void enableEspNow(uint8_t *mac)
{
    WiFi.mode(WIFI_OFF);
    WiFi.mode(WIFI_STA);
    Serial.println("Wi-fi enabled successfully");
    WiFi.setOutputPower(20);
    if (esp_now_init() != 0)
    {
        Serial.println("Error initializing ESP-NOW");
        return;
    }
    Serial.println("ESP-NOW initialized successfully");
    esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
    esp_now_register_send_cb(OnDataSent);
    esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
    Serial.println("ESP-NOW configured successfully");
}

/**
 * @brief This function is triggerred on data send event
 * 
 * @param mac_addr 
 * @param sendStatus 
 */
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus)
{
    Serial.print("Last Packet Send Status: ");

    if (sendStatus == 0)
        Serial.println("Delivery success");
    else
        Serial.println("Delivery fail");
}