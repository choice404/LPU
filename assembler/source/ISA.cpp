/*
Copyright (C) 2023 Lysus
See end of file for extended copyright information
*/

// Include header files
#include "../header/ISA.h"
#include <regex>

std::unordered_map<std::string, uint64_t> g_TokenMap =
{
    {"NOP", 1},
    {"HLT", 1},
    {"CMP", 1},
    {"BRC", 1},
    {"MST", 1},
    {"MLD", 1},
    {"PST", 1},
    {"PLD", 1},
    {"LDI", 1},
    {"MOV", 1},
    {"ADD", 1},
    {"SUB", 1},
    {"ADI", 1},
    {"XOR", 1},
    {"AND", 1},
    {"IOR", 1},
    
    {"r0", 2},   // 0 Register
    {"r1", 2},   // Return register
    {"r2", 2},   // Arguement 1
    {"r3", 2},   // Arguement 2
    {"r4", 2},   // Arguement 3
    {"r5", 2},   // Arguement 4
    {"r6", 2},   // Arguement 5
    {"r7", 2},   // Arguement 6
    {"r8", 2},   // GPR
    {"r9", 2},   // GPR
    {"r10", 2},  // GPR
    {"r11", 2},  // GPR
    {"r12", 2},  // GPR
    {"PC", 2},   // Program Counter
    {"CSP", 2},  // Call Stack Pointer
    {"SP", 2},    // Stack Pointer
};

/*
Copyright (C) 2023 Lysus

cpp_LPUAssembler

Assembler for the LPU V1 CPU Instruction Set Architecture

This code is licensed under the GNU General Public License v3.0 license.
Please see the LICENSE file in the root directory of this project for the full license details.
*/
