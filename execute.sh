#!/bin/bash

g++ Compiler.cpp Parser.cpp Lexer.cpp -o compiler
g++ interpreter.cpp -o interpreter
./compiler | ./interpreter

