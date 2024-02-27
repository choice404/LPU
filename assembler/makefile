# Makefile for Austin Choi's braifuck compiler

MAIN		= ./main.cpp
INCLUDES	= ./source/lexer.cpp
OUTFILE		= ./lpu

all: a.out

a.out: main.cpp
	g++ -std=c++11 $(MAIN) $(INCLUDES) -o $(OUTFILE)

clean:
	rm -rf $(OUTFILE)
