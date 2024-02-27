/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include <iomanip>
#include <fstream>
#include "./header/lexer.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

int main(const int argc, const char* argv[])
{
    if(argc < 2)
    {
        std::cerr << "Error: No input file" << std::endl;
        return 1;
    }

    std::ifstream iFile(argv[1]);

    if(!iFile.is_open())
    {
        std::cerr << "Error: File not found" << std::endl;
        return 1;
    }

    std::string TokenTypeArray[14] = {
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
        "WHITESPACE"
    };

    std::string asmCode = "", line = "";

    while(!iFile.eof())
    {
        std::getline(iFile, line);
        asmCode += line;
        asmCode += '\n';
    }
    Lexer lexer(asmCode);

    int i = 0;
    /* while(i < 10) //int(lexer.getPosition()) < asmCode.length()) */
    Token token;
    while(token.Type != TokenType::END_OF_FILE)
    {
        token = lexer.nextToken();
        if(token.Type != TokenType::WHITESPACE)
          std::cout << "Type: " << std::setw(15) << std::left << TokenTypeArray[static_cast<int>(token.Type)] << "- Lexeme: " << token.Literal << std::endl;
        i++;
    }

    // End program
    return 0;
}

/*
 * Copyright (C) 2024 Austin Choi
 * 
 * lpu
 * A custom 8 bit pure harvard architecture CPU built in minecraft. This project will consist of the specifications of the CPU as well as an external assembler that will assemble code down to the target machine code as well as a compiler for a custom language called CMine that will compile down to the target assembly code then be assembled into the machine code. This langugae will be a subset of C just to make develping for the CPU easier
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the full license details.
 */
