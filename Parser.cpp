#include "Parser.h"

Parser::Parser(Lexer *lex){
    lexer = lex;
    token = new Token();
}

Parser::~Parser(){
    delete token;
}

void Parser::parse(){
    std::cout << "Hello, world!" << std::endl;
}
