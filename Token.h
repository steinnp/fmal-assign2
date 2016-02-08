#include <iostream>
#include <string>

enum TokenCode {ID, ASSIGN, SEMICOL, INT, ADD, SUB, MULT, LPAREN, RPAREN, PRINT, END, ERROR };

struct Token {
    std::string lexeme;
    TokenCode tCode;
};
