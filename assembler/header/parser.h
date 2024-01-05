/*
Copyright (C) 2023 Lysus
See end of file for extended copyright information
*/

#pragma once

#include <vector>
#include "./lexer.h"

struct Node
{
    Token m_Token;
    Node* child;
    Node* next;

};

class Parser
{
public:
    Parser();
    Parser(std::vector<Token>);
    void parse();
private:
    std::vector<Token> m_Tokens;
    Node* head;
    Node* tail;    
};

/*
Copyright (C) 2023 Lysus

cpp_LPUAssembler

Assembler for the LPU V1 CPU Instruction Set Architecture

This code is licensed under the GNU General Public License v3.0 license.
Please see the LICENSE file in the root directory of this project for the full license details.
*/
