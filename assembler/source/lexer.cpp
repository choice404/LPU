/*
Copyright (C) 2023 Lysus
See end of file for extended copyright information
*/

// Include header files
#include "../header/lexer.h"
#include "../header/ISA.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

Token::Token() {};

Token::Token(TokenType type, const std::string& lexeme, size_t line) : m_Type(type), lexeme(lexeme), m_Line(line) {}

Lexer::Lexer(std::istream& input) : m_InputStream(input) {}

TokenType Lexer::identifyToken(const std::string& tokenString)
{
    std::regex registerPattern("r[1-9][1-9]?");
    if(g_TokenMap[tokenString] == 1)
    {
        return TokenType::INSTRUCTION;
    }
    /* if(g_TokenMap[tokenString] == 2) */
    if(std::regex_match(tokenString, registerPattern))
    {
        return TokenType::REGISTER;
    }
    if(tokenString.back() == ':') { return TokenType::LABEL; }
    else if(tokenString.front() == '.') { return TokenType::DIRECTIVE; }
    else if(isdigit(tokenString.front())) { return TokenType::CONSTANT; }
    else if((tokenString.front() == '"' && tokenString.back() == '"') || (tokenString.front() == '\'' && tokenString.back() == '\''))
    {
        return TokenType::STRING;
    }
    else if(tokenString.find_first_not_of(" \t\r\n") == std::string::npos) { return TokenType::WHITESPACE; }
    else if(tokenString == "\n") { return TokenType::NEWLINE; }
    else if(tokenString.front() == ';' || tokenString.front() == '#') { return TokenType::COMMENT; }
    else { return TokenType::ENDOFFILE; }
}

Token Lexer::tokenize(std::string code, size_t line)
{
    Token x;
    m_Code += code;
    m_CodeString.push_back(code);
    x.m_Type = identifyToken(code);
    x.m_Line = line;
    return x;
}

std::vector<Token> Lexer::tokenize()
{
    std::vector<Token> tokens;
    size_t line = 0;
    while(!m_InputStream.eof())
    {
        line++;
        char currentChar = m_InputStream.get();
        std::string lexeme(1, currentChar);
        if(currentChar == ';' || currentChar == '#')
        {
            while(!m_InputStream.eof() && m_InputStream.peek() != '\n')
            {
                lexeme += m_InputStream.get();
            }
            tokens.push_back(Token(TokenType::COMMENT, lexeme, line));
        }
        else if(isspace(currentChar))
        {
            continue;
        }
        else if(currentChar == '\n')
        {
            tokens.push_back(Token(TokenType::NEWLINE, lexeme, line));
        }
        else if(currentChar == '"' || currentChar =='\'')
        {
            char quote = currentChar;
            while(!m_InputStream.eof() && m_InputStream.peek() != quote)
            {
                currentChar = m_InputStream.get();
                lexeme += currentChar;
            }
            if(!m_InputStream.eof())
            {
                lexeme += m_InputStream.get();
            }
        }
        else if(currentChar == ':')
        {
            while(!m_InputStream.eof() && isalnum(m_InputStream.peek()))
            {
                currentChar = m_InputStream.get();
                lexeme += currentChar;
            }
            tokens.push_back(Token(TokenType::LABEL, lexeme, line));
        }
        else if(currentChar == '.')
        {
            while(!m_InputStream.eof() && isalnum(m_InputStream.peek()))
            {
                currentChar = m_InputStream.get();
                lexeme += currentChar;
            }
            tokens.push_back(Token(TokenType::DIRECTIVE, lexeme, line));
        }
        else if(isdigit(currentChar))
        {
            while(!m_InputStream.eof() && isdigit(m_InputStream.peek()))
            {
                currentChar = m_InputStream.get();
                lexeme += currentChar;
            }
        }
        else if(isalpha(currentChar))
        {
            while(!m_InputStream.eof() && isalnum(m_InputStream.peek()))
            {
                currentChar = m_InputStream.get();
                lexeme += currentChar;
            }
            if(isInstruction(lexeme))
            {
                tokens.push_back(Token(TokenType::INSTRUCTION, lexeme, line));
            }
            else if(isRegister(lexeme))
            {
                tokens.push_back(Token(TokenType::REGISTER, lexeme, line));
            }
            else if(isLabel(lexeme))
            {
                tokens.push_back(Token(TokenType::LABEL, lexeme, line));
            }
            else
            {
                tokens.push_back(Token(TokenType::IDENTIFIER , lexeme, line));
            }
        }
    }
    tokens.push_back(Token(TokenType::ENDOFFILE, "", line++));

    return tokens;
}

bool Lexer::isLabel(const std::string& lexeme)
{
    for(char c : lexeme)
    {
        if(!isalnum(c) && c != '_') { return false; }
    }
    return true;
}

bool Lexer::isInstruction(const std::string& lexeme)
{
    if(g_TokenMap[lexeme] == 1) { return true; }
    return false;
}

bool Lexer::isRegister(const std::string& lexeme)
{
    if(g_TokenMap[lexeme] == 2) { return true; }
    return false;
}

/*
Copyright (C) 2023 Lysus

cpp_LPUAssembler

Assembler for the LPU V1 CPU Instruction Set Architecture

This code is licensed under the GNU General Public License v3.0
Please see the LICENSE file in the root directory of this project for the full license details.
*/
