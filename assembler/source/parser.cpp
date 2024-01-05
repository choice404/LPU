/*
Copyright (C) 2023 Lysus
See end of file for extended copyright information
*/

// Include header files
#include <iostream>
#include "../header/parser.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

Parser::Parser()
{

}

Parser::Parser(std::vector<Token> tokens) : m_Tokens(tokens), head(nullptr), tail(nullptr) {}

void Parser::parse()
{
}

/*
Copyright (C) 2023 Lysus

cpp_LPUAssembler

Assembler for the LPU V1 CPU Instruction Set Architecture

This code is licensed under the GNU General Public License v3.0 license.
Please see the LICENSE file in the root directory of this project for the full license details.
*/
