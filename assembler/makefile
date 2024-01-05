# Makefile for Austin Choi's braifuck compiler

MAIN		= ./main.cpp
INCLUDES	= ./source/ISA.cpp ./source/lexer.cpp
OUTFILE		= ./lpuAssembler

all: a.out

a.out: main.cpp
	g++ $(MAIN) $(INCLUDES) -o $(OUTFILE)

clean:
	rm -rf $(OUTFILE)
