/**
 * @file datastruct.hpp
 * @author Piotr Sokołowski (https://sokoloowski.pl)
 * @brief Struct for all data transferred over ESP-NOW
 * @version 0.1
 * @date 2020-11-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

struct Beeboard {
    int secretKey;
    int messageCode;
    int humidity;
    float temperatureIn;
    float temperatureOut;
    float pressure;
    float weight;
}