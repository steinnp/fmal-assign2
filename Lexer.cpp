#include "Lexer.h"

TokenCode inputType(char nextChar){
    int type = (int)nextChar;
    if(isdigit(nextChar)){
        return INT;
    } else if(isalpha(nextChar)){
        return ID;
    } else if(type == 40){
        return LPAREN;
    } else if(type == 41){
        return RPAREN;
    } else if(type == 43){
        return ADD;
    } else if(type == 45){
        return SUB;
    } else if(type == 42){
        return MULT;
    } else if(type == 61){
        return ASSIGN;
    } else if(type == 59){
        return SEMICOL;
    } else{
        return ERROR;
    }
}

Token Lexer::nextToken(){
    Token current;
    std::cin >> std::ws;
    current.lexeme = std::string(1,(char)getchar());
    current.tCode = inputType(current.lexeme[0]);
    if(current.tCode == INT || current.tCode == ID){
        while(current.tCode == inputType((char)std::cin.peek())){
            current.lexeme += std::string(1,(char)getchar());
        }
        if(current.lexeme == "end"){
            current.tCode = END;
            return current;
        } else if(current.lexeme == "print"){
            current.tCode = PRINT;
            return current;
        }
    }
    return current;
}
