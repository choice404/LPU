/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
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
 * Copyright (C) 2024 Austin Choi
 * 
 * lpu
 * A custom 8 bit pure harvard architecture CPU built in minecraft. This project will consist of the specifications of the CPU as well as an external assembler that will assemble code down to the target machine code as well as a compiler for a custom language called CMine that will compile down to the target assembly code then be assembled into the machine code. This langugae will be a subset of C just to make develping for the CPU easier
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the full license details.
 */
