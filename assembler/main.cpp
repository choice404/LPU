/**
Copyright (C) 2023 Lysus
See end of file for extended copyright information
*/

// Include header files
#include <iostream>
#include <fstream>
#include "./header/lexer.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

int main(const int argc, const char* argv[])
{
    std::ifstream iFile(argv[1]);

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
          std::cout << "Type: " << static_cast<int>(token.Type) << " , Lexeme: " << token.Literal << std::endl;
        i++;
    }

    // End program
    return 0;
}

/**
Copyright (C) 2023 Lysus

cpp_LPUAssembler

Assembler for the LPU V1 CPU Instruction Set Architecture

This code is licensed under the GNU General Public License v3.0
Please see the LICENSE file in the root directory of this project for the full license details.
*/
