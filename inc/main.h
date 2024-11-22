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

#ifndef MAIN_H
#define MAIN_H

/**
 * @file main.h
 * @brief Header file for the main function definition.
 *
 * This header file contains the declaration of the main function, which is the entry point
 * of the program. It also includes other necessary function declarations for initialization
 * and program flow.
 */

/* === Headers files inclusions ================================================================ */

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/* Comentario normal */

/**
 * @brief Main function of the program.
 *
 * This function is executed when the program starts. It initializes a GPIO pin for controlling
 * a red LED and sets its initial state to OFF. The function is the entry point of the program
 * and handles the basic setup required for operation.
 *
 * @return int Returns zero if the program executed successfully, negative if an error occurred.
 */
int main(void);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* MAIN_H */
