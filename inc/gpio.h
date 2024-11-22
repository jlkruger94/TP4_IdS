/************************************************************************************************
Copyright (c) 2024, José Luis Krüger <jlkruger94@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef GPIO_H
#define GPIO_H

/**
 * @file gpio.h
 * @brief Interface for managing GPIO pins.
 *
 * This file provides the definitions and declarations required for
 * configuring and manipulating GPIO pins, allowing their use as inputs or outputs.
 */

/* === Headers files inclusions ================================================================ */
#include <stdint.h>
#include <stdbool.h>

/* === C++ Header ============================================================================== */
#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */
/**
 * @brief Default permission settings for GPIO.
 *
 * These settings may vary depending on the operating system or platform.
 */
#define GPIO_MAX_INSTANCES 10 /**< Maximum number of GPIO instances. */

/* === Public data type declarations =========================================================== */

/**
 * @typedef gpio_t
 * @brief Pointer to the structure representing a GPIO.
 *
 * This pointer is used to manipulate and manage a GPIO instance.
 */
typedef struct gpio_s * gpio_t;

/* === Public function declarations ============================================================ */

/**
 * @brief Creates a GPIO object associated with a specific port and pin.
 *
 * In systems with dynamic memory, memory is allocated for the instance.
 * In systems without dynamic memory, a pre-defined static pool is used.
 *
 * @param port GPIO port number.
 * @param bit GPIO pin number within the port.
 * @return gpio_t Pointer to the created GPIO instance, or `NULL` if creation fails.
 */
gpio_t gpioCreate(uint8_t port, uint8_t bit);

/**
 * @brief Configures the GPIO as input or output.
 *
 * @param gpio Pointer to the GPIO to be configured.
 * @param output `true` to configure as output, `false` to configure as input.
 */
void gpioSetOutput(gpio_t gpio, bool output);

/**
 * @brief Sets the logical state of a GPIO.
 *
 * If the GPIO is configured as output, this function sets its logical state (high or low).
 *
 * @param gpio Pointer to the GPIO whose state is to be modified.
 * @param state `true` for high level, `false` for low level.
 */
void gpioSetState(gpio_t gpio, bool state);

/**
 * @brief Reads the current logical state of a GPIO.
 *
 * Retrieves the logical value of the GPIO pin configured as input.
 *
 * @param gpio Pointer to the GPIO to be read.
 * @return bool Logical state of the GPIO (`true` for high, `false` for low).
 */
bool gpioGetState(gpio_t gpio);

/* === End of documentation ==================================================================== */
#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
