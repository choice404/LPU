/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "../header/lexer.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

/**
 * ILLEGAL
 * END_OF_FILE
 * INSTRUCTION
 * REGISTER
 * MEMORY_ADDRESS
 * CONSTANT
 * IMMEDIATE
 * LABEL
 * DIRECTIVE
 * COMMA
 * COMMENT
 * SEMICOLON
 * OPERATOR
 * WHITESPACE
 */

std::string TokenMap[TOKEN_COUNT] =
{
    "ILLEGAL",
    "END_OF_FILE",
    "INSTRUCTION",
    "REGISTER",
    "MEMORY_ADDRESS",
    "CONSTANT",
    "IMMEDIATE",
    "LABEL",
    "DIRECTIVE",
    "COMMA",
    "COMMENT",
    "SEMICOLON",
    "OPERATOR",
    "WHITESPACE",
};

// Constructors and destructors

/**
 * @description: Constructor for the lexer class
 * @param {std::string} input - Assembly code as input to be lexed
 * @return {void}
 */
Lexer::Lexer(std::string input) : m_Input(input), m_Position(0), m_NextPosition(1), m_Ch(0)
{
    this->readChar();
};

/**
 * @description: Destructor for the lexer class
 * @param {void}
 * @return {void}
 */
Lexer::~Lexer() {}

// Public methods

/**
 * @description: Returns the next token in the input
 * @param {void}
 * @return {Token} - The next token in the input
 */
Token Lexer::nextToken()
{
    Token tok;

    switch(this->m_Ch)
    {
    case ',':
        tok.Literal = ",";
        tok.Type = TokenType::COMMA;
        /* tok = createToken(TokenType::COMMA, ","); */
        break;;
    case ';':
        tok.Literal = ";";
        tok.Type = TokenType::SEMICOLON;
        /* tok = createToken(TokenType::SEMICOLON, ";"); */
        break;;
    case '_':
        tok.Literal = readLabel();
        tok.Type = TokenType::LABEL;
        break;;
    case '#':
        tok.Literal = readComment();
        tok.Type = TokenType::COMMENT;
        break;;
    case '\n':
    case ' ':
    case '\t':
    /* case '\r': */
        tok.Literal = this->m_Ch;
        tok.Type = TokenType::WHITESPACE;
        break;;
    case 'R':
    /* case 'r': */
        if(this->isDigit(this->peekChar()))
        {
            tok.Literal = readRegister();
            tok.Type = TokenType::REGISTER;
            return tok;
        }
    default:
        if(this->isLetter(this->m_Ch))
        {
          tok.Literal = readWord();
          if(this->peekChar() == ':')
          {
              tok.Type = TokenType::LABEL;
          }
          else
          {
              tok.Type = TokenType::INSTRUCTION;
          }
        }
        else if(this->isDigit(this->m_Ch))
        {
            tok.Literal = readImmediate();
            tok.Type = TokenType::IMMEDIATE;
        }
        else if(this->m_Ch == 0)
        {
            tok.Literal = "";
            tok.Type = TokenType::END_OF_FILE;
        }
        else
        {
            tok.Literal = this->m_Ch;
            tok.Type = TokenType::ILLEGAL;
        }
        break;;
    }
    this->readChar();
    return tok;
}

// Private methods

/**
 * @description: Moves the position of the lexer forward
 * @param {void}
 * @return {void}
 */
void Lexer::readChar()
{
    if(this->m_NextPosition >= this->m_Input.length())
    {
        this->m_Ch = 0;
    }
    else
    {
        this->m_Ch = this->m_Input[this->m_NextPosition];
    }
    this->m_Position = this->m_NextPosition++;
}

/**
 * @description: Creates a token using a given type and literal
 * @param {TokenType} type - The type of the token
 * @param {std::string} literal - The literal value of the token
 * @return {Token}
 */
Token createToken(TokenType type, std::string literal)
{
    Token tok;
    tok.Type = type;
    tok.Literal = literal;
    return tok;
}

/**
 * @description: Checks if a character is a letter
 * @param {char} ch - The character to check
 * @return {bool} - True if the character is a letter, false otherwise
 */
bool Lexer::isLetter(char ch)
{
    return((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

/**
 * @description: Checks if a character is a digit
 * @param {char} ch - The character to check
 * @return {bool} - True if the character is a digit, false otherwise
 */
bool Lexer::isDigit(char ch)
{
    return(ch >= '0' && ch <= '9');
}

/**
 * @description: Reads a number from the input
 * @param {void}
 * @return {std::string} - The number read from the input
 */
char Lexer::peekChar()
{
    if(this->m_NextPosition >= this->m_Input.length())
    {
        return 0;
    }
    else
    {
        return this->m_Input[this->m_NextPosition];
    }
}

/**
 * @description: Reads a number from the input
 * @param {void}
 * @return {std::string} - The number read from the input
 */
std::string Lexer::readImmediate()
{
    size_t position = this->m_Position;
    while(this->isDigit(this->m_Ch))
    {
        this->readChar();
    }
    return this->m_Input.substr(position, this->m_Position - position);
}

/**
 * @description: Reads an instruction from the input
 * @param {void}
 * @return {std::string} - The instruction read from the input
 */
std::string Lexer::readInstruction()
{
    size_t position = this->m_Position;
    while(this->isLetter(this->m_Ch) || this->isDigit(this->m_Ch))
    {
        this->readChar();
    }
    return this->m_Input.substr(position, this->m_Position - position);
}

/**
 * @description: Reads a register from the input
 * @param {void}
 * @return {std::string} - The register read from the input
 */
std::string Lexer::readRegister()
{
    size_t position = this->m_Position;
    this->readChar();
    while(this->isDigit(this->m_Ch))
    {
        this->readChar();
    }
    return this->m_Input.substr(position, this->m_Position - position);
}

/**
 * @description: Reads a label from the input
 * @param {void}
 * @return {std::string} - The label read from the input
 */
std::string Lexer::readLabel()
{
    size_t position = this->m_Position;
    this->readChar();
    while(this->isLetter(this->m_Ch) || this->isDigit(this->m_Ch))
    {
        this->readChar();
    }
    if(this->peekChar() == ':')
    {
        this->readChar();
    }
    return this->m_Input.substr(position, this->m_Position - position);
}

/**
 * @description: Reads a comment from the input
 * @param {void}
 * @return {std::string} - The comment read from the input
 */
std::string Lexer::readComment()
{
    size_t position = this->m_Position;
    while(this->m_Ch != '\n' && this->m_Ch != 0)
    {
        this->readChar();
    }
    return this->m_Input.substr(position, this->m_Position - position);
}

/**
 * @description: Reads a constant from the input
 * @param {void}
 * @return {std::string} - The constant read from the input
 */
std::string Lexer::readConstant()
{
    size_t position = this->m_Position;
    while(this->isDigit(this->m_Ch))
    {
        this->readChar();
    }
    return this->m_Input.substr(position, this->m_Position - position);
}

/**
 * @description: Reads a word from the input
 * @param {void}
 * @return {std::string} - The word read from the input
 */
std::string Lexer::readWord()
{
    size_t position = this->m_Position;
    while(this->isLetter(this->m_Ch) || this->isDigit(this->m_Ch))
    {
        this->readChar();
    }
    return this->m_Input.substr(position, this->m_Position - position);
}

/**
 * @description: Returns the current position of the lexer
 * @param {void}
 * @return {size_t} - The current position of the lexer
 */
int Lexer::getPosition() { return this->m_Position; }

/*
 * Copyright (C) 2024 Austin Choi
 * 
 * lpu
 * A custom 8 bit pure harvard architecture CPU built in minecraft. This project will consist of the specifications of the CPU as well as an external assembler that will assemble code down to the target machine code as well as a compiler for a custom language called CMine that will compile down to the target assembly code then be assembled into the machine code. This langugae will be a subset of C just to make develping for the CPU easier
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the full license details.
 */
