/*
Copyright (C) 2023 Lysus
See end of file for extended copyright information
*/

// Include header files
#include <iostream>
#include <fstream>
#include "./header/old_lexer.h"

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

    std::istringstream inputStream(asmCode);
    Lexer lexer(inputStream);
    std::vector<Token> tokens = lexer.tokenize();

    for(const Token& token : tokens)
    {
        std::cout << "Type: " << static_cast<int>(token.m_Type) << " , Lexeme: " << token.lexeme << std::endl;
    }

    // End program
    return 0;
}

/*
Copyright (C) 2023 Lysus

cpp_LPUAssembler

Assembler for the LPU V1 CPU Instruction Set Architecture

This code is licensed under the GNU General Public License v3.0
Please see the LICENSE file in the root directory of this project for the full license details.
*/
