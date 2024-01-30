/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

#include <iostream>
const size_t TOKEN_COUNT = 14;

/**
 * @typedef TokenType
 * @brief The type of token
 * @property {int} ILLEGAL - 0
 * @property {int} END_OF_FILE - 1
 * @property {int} INSTRUCTION - 2
 * @property {int} REGISTER - 3
 * @property {int} MEMORY_ADDRESS - 4
 * @property {int} CONSTANT - 5
 * @property {int} IMMEDIATE - 6
 * @property {int} LABEL - 7
 * @property {int} DIRECTIVE - 8
 * @property {int} COMMA - 9
 * @property {int} COMMENT - 10
 * @property {int} SEMICOLON - 11
 * @property {int} OPERATOR - 12
 * @property {int} WHITESPACE - 13
 */
enum TokenType
{
    ILLEGAL,
    END_OF_FILE,
    INSTRUCTION,
    REGISTER,
    MEMORY_ADDRESS,
    CONSTANT,
    IMMEDIATE,
    LABEL,
    DIRECTIVE,
    COMMA,
    COMMENT,
    SEMICOLON,
    OPERATOR,
    WHITESPACE,
};

extern std::string TokenMap[TOKEN_COUNT];

struct Token
{
    TokenType Type;
    std::string Literal;
};

class Lexer
{
public:
    Lexer(std::string);
    ~Lexer();

    Token nextToken();
    int getPosition();

private:
    char m_Ch;
    size_t m_Position;
    size_t m_NextPosition;
    std::string m_Input;

private:
    Token createToken(TokenType, std::string);
    bool isLetter(char);
    bool isDigit(char);
    char peekChar();
    void readChar();
    std::string readInstruction();
    std::string readRegister();
    std::string readConstant();
    std::string readImmediate();
    std::string readComment();
    std::string readLabel();
    std::string readWord();
};

/*
 * Copyright (C) 2024 Austin Choi
 * 
 * lpu
 * A custom 8 bit pure harvard architecture CPU built in minecraft. This project will consist of the specifications of the CPU as well as an external assembler that will assemble code down to the target machine code as well as a compiler for a custom language called CMine that will compile down to the target assembly code then be assembled into the machine code. This langugae will be a subset of C just to make develping for the CPU easier
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the full license details.
 */
