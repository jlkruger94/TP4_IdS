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

/** @file gpio.c
 ** @brief
 **/

/* === Headers files inclusions =============================================================== */

#include "gpio.h"
#include <stddef.h>

/* === Macros definitions ====================================================================== */

#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10 /**< Maximum number of GPIO instances available. */
#endif

/* === Private data type declarations ========================================================== */

/**
 * @struct gpio_s
 * @brief Represents a GPIO pin and its configuration.
 *
 * This structure is used to define the configuration and state of a GPIO pin.
 */
struct gpio_s {
    uint8_t port; /**< Port number where the GPIO pin is located. */
    uint8_t bit;  /**< Pin number on the specified port. */
    bool output;  /**< Flag indicating whether the GPIO is set as output. */
#ifndef USE_DYNAMIC_MEM
    bool used; /**< Flag indicating if the GPIO instance is in use. Only applicable in static
                  allocation mode. */
#endif
};

/* === Private function declarations =========================================================== */

/**
 * @brief Allocates a GPIO instance from the static pool.
 *
 * This function is used to allocate a GPIO instance in systems where dynamic memory allocation is
 * disabled.
 *
 * @return gpio_t A pointer to the GPIO instance, or `NULL` if no available instances are left.
 */
#ifndef USE_DYNAMIC_MEM
static gpio_t allocateInstance(void);
#endif

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

#ifndef USE_DYNAMIC_MEM
/**
 * @brief Allocates an instance of GPIO from a static pool.
 *
 * This function scans through a predefined pool of GPIO instances and allocates the first available
 * one. It only works when dynamic memory allocation is disabled.
 *
 * @return gpio_t A pointer to the GPIO instance, or `NULL` if no instances are available.
 */
static gpio_t allocateInstance(void) {
    static struct gpio_s instances[GPIO_MAX_INSTANCES] = {0};

    gpio_t result = NULL;
    for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
        if (!instances[index].used) {
            result = &instances[index];
            result->used = true; /**< Mark the instance as used */
            break;
        }
    }
    return result;
}
#endif

/* === Public function implementation ========================================================== */

/**
 * @brief Creates a new GPIO instance.
 *
 * This function initializes a new GPIO instance, either by allocating memory dynamically or using a
 * static pool, depending on the system configuration.
 *
 * @param port The GPIO port number.
 * @param bit The GPIO pin number.
 * @return gpio_t A pointer to the newly created GPIO instance, or `NULL` if creation failed.
 */
gpio_t gpioCreate(uint8_t port, uint8_t bit) {
#ifdef USE_DYNAMIC_MEM
    gpio_t self =
        malloc(sizeof(struct gpio_s)); /**< Dynamically allocate memory for the GPIO instance. */
#else
    gpio_t self = allocateInstance(); /**< Allocate from static pool of GPIO instances. */
#endif

    if (self) {
        self->port = port;
        self->bit = bit;
        self->output = false; /**< Default state is input (output = false). */
    }
    return self; /**< Return the created GPIO instance or NULL if creation failed. */
}

/**
 * @brief Configures the GPIO as either input or output.
 *
 * This function sets the direction of the GPIO pin (input or output).
 *
 * @param gpio The GPIO instance to configure.
 * @param output If `true`, sets the pin as output, otherwise sets it as input.
 */
void gpioSetOutput(gpio_t self, bool output) {
    self->output = output;
    hal_gpio_set_direction(
        self->port, self->bit,
        output); /**< Configures GPIO direction using the hardware abstraction layer. */
}

/**
 * @brief Sets the logical state of a GPIO pin.
 *
 * If the GPIO is configured as an output, this function will set its state (high or low).
 *
 * @param gpio The GPIO instance to modify.
 * @param state The state to set: `true` for high, `false` for low.
 */
void gpioSetState(gpio_t self, bool state) {
    if (self->output) {
        hal_gpio_set_output(self->port, self->bit,
                            state); /**< Sets the output value of the GPIO pin. */
    }
}

/**
 * @brief Reads the current logical state of a GPIO pin.
 *
 * This function reads the state of a GPIO pin configured as input and returns its value.
 *
 * @param gpio The GPIO instance to read.
 * @return bool The current state of the GPIO pin: `true` for high, `false` for low.
 */
bool gpioGetState(gpio_t self) {
    return hal_gpio_get_input(self->port, self->bit); /**< Reads the input value of the GPIO pin. */
}

/* === End of documentation ==================================================================== */
