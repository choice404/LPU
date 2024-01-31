/**
 * Copyright (C) 2024 Lysus
 * See end of file for extended copyright information
 */

#pragma once
#include <stdlib.h>

enum TokenType
{
  ILLEGAL,
  ENDOFFILE,
  IDENT,
  INT,
  ASSIGN,
  PLUS,
  COMMA,
  SEMICOLON,
  LPAREN,
  RPAREN,
  LBRACE,
  RBRACE,
  FUNCTION,
  LET,
};

typedef struct Lexer
{
  char m_Ch = '\0';
  size_t m_Position = 0;
  size_t m_NextPosition = 1;
  char* m_Input = NULL;
} Lexer;

typedef struct Token
{
  char* m_Literal;
  TokenType m_Type;
} Token;

Lexer *constructLexer(void);
void destructLexer(Lexer *lexer);

char peekChar(Lexer *lexer);
char readChar(Lexer *lexer);
Token generateToken(Lexer *lexer);

/**
 * Copyright (C) 2024 Lysus
 * 
 * c_assembler
 * The LPU assembler implemented in C
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the full license details.
 */
