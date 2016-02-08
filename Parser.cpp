#include "Parser.h"

Parser::Parser(Lexer *lex){
    lexer = lex;
}

Parser::~Parser(){
}



void Parser::parse(){
    token = lexer->nextToken();
}
