/**
 * @file at24c.h
 *
 * ESP-IDF driver for AT24C I2C EEPROM
 *
 * Copyright (c) 2023 Jakub Arm
 * MIT license
 */

#ifndef __AT24C_H__
#define __AT24C_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include "driver/i2c.h"

/**
 * @brief AT24C device structure
 *
 * Structure to define the GPIO expander device
 */
typedef struct {
    i2c_port_t port;    /**< I2C_NUM_0 or I2C_NUM_1 */
    uint8_t address;    /**< Hardware address of the device */
    uint32_t size;      /**< Size of the memoru in bytes */
} at24c_t;

/**
 * @brief Initialize the driver
 * @param me Pointer to the device structure
 * @return 'ESP_OK' on success
*/
esp_err_t at24c_init(at24c_t *me);

/**
 * @brief Reads byte from address
 * @param me Pointer to the device structure
 * @param memAddr Memory address
 * @param d Pointer to a 8 bit to hold value
 * @return 'ESP_OK' on success
*/
esp_err_t at24c_read_byte(at24c_t *me, uint16_t memAddr, uint8_t *d);

/**
 * @brief Writes byte to address
 * @param me Pointer to the device structure
 * @param memAddr Memory address
 * @param d New value
 * @return 'ESP_OK' on success
*/
esp_err_t at24c_write_byte(at24c_t *me, uint16_t memAddr, uint8_t d);

/**
 * @brief Reads bytes from address
 * @param me Pointer to the device structure
 * @param memAddr Memory address
 * @param len Data length
 * @param buffer Pointer to byte buffer for reading
 * @return 'ESP_OK' on success
*/
esp_err_t at24c_read(at24c_t *me, uint16_t memAddr, uint16_t len, uint8_t *buffer);

/**
 * @brief Writes byte to address
 * @param me Pointer to the device structure
 * @param memAddr Memory address
 * @param len Data length
 * @param buffer Pointer to byte buffer for writing
 * @return 'ESP_OK' on success
*/
esp_err_t at24c_write(at24c_t *me, uint16_t memAddr, uint16_t len, uint8_t *buffer);

#ifdef __cplusplus
}
#endif

#endif  // __AT24C_H__