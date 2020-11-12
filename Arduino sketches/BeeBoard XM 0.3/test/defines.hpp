/**
 * @file defines.hpp
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief Definitions of constants used in project
 * @version 0.1
 * @date 2020-11-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma region ESP-12F pins
// Analog pin
#define ADC 0

// Built-in LED
#define LED 2

// HX711 data pin
#define HX711_DT 12

#define CALIBRATION_FACTOR 21700

// HX711 clock pin
#define HX711_SCK 13
#pragma endregion

#pragma region ADC constants
// Maximum voltage
#define MAX_VOLTAGE 12.65f

// Maximum ADC value
#define MAX_ADC_VALUE 1024
#pragma endregion