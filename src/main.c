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
/**
 * @file main.c
 * @brief Defines the main function of the program.
 *
 * This file contains the entry point of the program, where the main system logic is executed.
 * It initializes the GPIO pin for controlling a red LED and sets the LED state.
 */

/* === Header files inclusions =============================================================== */

#include "main.h"
#include <stdbool.h>

#include "gpio.h"

/* === Macros definitions ====================================================================== */

#define LED_ROJO_PORT 1 ///< Port number for the red LED.
#define LED_ROJO_BIT  7 ///< Pin number for the red LED.

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

/**
 * @brief Main function of the program.
 *
 * This function is executed when the program starts. It initializes a GPIO pin for controlling
 * a red LED and sets its initial state to OFF. The function is the entry point of the program
 * and handles the basic setup required for operation.
 *
 * @return int Returns zero if the program executed successfully, negative if an error occurred.
 */
int main(void) {
    gpio_t red_led =
        gpioCreate(LED_ROJO_PORT, LED_ROJO_BIT); ///< Create the GPIO instance for the red LED.
    gpioSetOutput(red_led, true);                ///< Set the red LED GPIO as output.
    gpioSetState(red_led, false);                ///< Set the red LED state to OFF.
}

/* === End of documentation ==================================================================== */
