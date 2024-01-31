/*
 * Copyright (C) 2024 Lysus
 * See end of file for extended copyright information
 */

#pragma once
#include <stdlib.h>

typedef struct {
    char* data;
    size_t length;
    size_t capacity;
} String;

String* constructString(void);
String* constructStringWithString(char* str);
void destructString(String* str);

String* setString(String* str, char* newStr);
void stringAppend(String* str, char character);
void stringAppendString(String* str, char* stringToAppend);
String* substring(String* str, size_t start, size_t length);
size_t sizeOfString(String* str);
size_t capacityOfString(String* str);

char* stringToCharArray(String* str);




/*
 * Copyright (C) 2024 Lysus
 * 
 * c_assembler
 * The LPU assembler implemented in C
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the full license details.
 */
