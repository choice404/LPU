/*
 * Copyright (C) 2024 Lysus
 * See end of file for extended copyright information
 */

// Include header files
#include <stdio.h>
#include <string.h>
#include "../header/string.h"

String* constructString(void) {
    String* str = malloc(sizeof(String));
    str->length = 0;
    str->capacity = 0;
    str->data = NULL;
    return str;
}

String* constructStringWithString(char* str)
{
    String* newStr = constructString();
    newStr->length = strlen(str);
    newStr->capacity = newStr->length + 1;
    newStr->data = malloc(newStr->capacity);
    strcpy(newStr->data, str);
    return newStr;
}

void destructString(String* str) {
    free(str->data);
    free(str);
}

String* setString(String* str, char* newStr) {
    str->length = strlen(newStr);
    str->capacity = str->length + 1;
    str->data = malloc(str->capacity);
    strcpy(str->data, newStr);
    return str;
}

/*
 * Copyright (C) 2024 Lysus
 * 
 * c_assembler
 * The LPU assembler implemented in C
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the full license details.
 */
