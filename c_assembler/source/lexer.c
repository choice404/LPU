/**
 * Copyright (C) 2024 Lysus
 * See end of file for extended copyright information
 */

// Include header files
#include <stdio.h>
#include <string.h>
#include "../header/lexer.h"

Lexer *constructLexer(void)
{
    printf("Constructing lexer\n");
    Lexer *lexer = malloc(sizeof(Lexer));
    return lexer;
}

void destructLexer(Lexer *lexer)
{
    printf("Destructing lexer\n");
    free(lexer);
}

char peekChar(Lexer *lexer)
{
    return lexer->m_Input[lexer->m_NextPosition];
}

char readChar(Lexer *lexer)
{
    char ch = lexer->m_Input[lexer->m_Position];
    lexer->m_Position = lexer->m_NextPosition;
    lexer->m_NextPosition += 1;
    return ch;
}

Token generateToken(Lexer *lexer)
{
    Token token;
    token.m_Type = 0;
    token.m_Literal = "";
    switch(lexer->m_Ch)
    {
    case '=':
        token.m_Type = ASSIGN;
        token.m_Literal = "=";
        break;
    case ';':
        token.m_Type = SEMICOLON;
        token.m_Literal = ";";
        break;
    }
}

/**
 * Copyright (C) 2024 Lysus
 * 
 * c_assembler
 * The LPU assembler implemented in C
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the full license details.
 */
