/*
Copyright (C) 2023 Lysus
See end of file for extended copyright information
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>

#pragma once

enum TokenType
{
    INSTRUCTION,    // 0
    REGISTER,       // 1
    LABEL,          // 2
    DIRECTIVE,      // 3
    CONSTANT,       // 4
    VARIABLE,       // 5
    NUMBER,         // 6
    CHARACTER,      // 7
    STRING,         // 8
    WHITESPACE,     // 9
    NEWLINE,        // 10
    IDENTIFIER,     // 11
    COMMENT,        // 12
    ENDOFFILE,      // 13
};

struct Token
{
    TokenType m_Type;
    std::string lexeme;
    size_t m_Line;

    Token(TokenType, const std::string&, size_t);
    Token();
};

class Lexer
{
public:
    Lexer(std::istream&);
    std::vector<Token> tokenize();
private:
    Token tokenize(std::string code, size_t);
    /* TokenType identifyToken(const std::string&, const char*[], int, const char*[], int); */
    TokenType identifyToken(const std::string&);
    bool isLabel(const std::string&);
    bool isInstruction(const std::string&);
    bool isRegister(const std::string&);
private:
    std::istream& m_InputStream;
    std::vector<Token> m_Tokens;
    std::vector<std::string> m_CodeString;
    std::string m_Code;
    
};

/*
Copyright (C) 2023 Lysus

cpp_LPUAssembler

Assembler for the LPU V1 CPU Instruction Set Architecture

This code is licensed under the GNU General Public License v3.0
Please see the LICENSE file in the root directory of this project for the full license details.
*/
