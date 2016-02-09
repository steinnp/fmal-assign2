#include "Parser.h"

//enum TokenCode {ID, ASSIGN, SEMICOL, INT, ADD, SUB, MULT, LPAREN, RPAREN, PRINT, END, ERROR };

Parser::Parser(Lexer *lex){
    lexer = lex;
    error = false;
}

Parser::~Parser(){
}

void Parser::raiseError(){
    std::cout << "Syntax error!" << std::endl;
    error = true;
}

//returns true if the lexer retrieves a legal token, else it returns false
bool Parser::getNext(){
    token = lexer->nextToken();
    if(token.tCode == ERROR){
        raiseError();
        return 0;
    } else{
        return 1;
    }
}

int Parser::accept(TokenCode t){
    if(t == token.tCode){
        return 1;
    } else{
        return 0;
    }
}

void Parser::factor(){
    if(!error){
        if(!getNext()){
            return;
        }
        if(accept(ID)){
            if(!error){
                std::cout << "PUSH " + token.lexeme << std::endl;
                return;
            }
        } else if(accept(INT)){
            if(!error){
                std::cout << "PUSH " + token.lexeme << std::endl;
            }
            return;
        } else if(accept(LPAREN)){
            expression();
            if(accept(RPAREN)){
                return;
            } else{
                raiseError();
                return;
            }
        } else{
            raiseError();
            return;
        }
    }else{
        return;
    }
}

void Parser::term(){
    factor();
    if(!getNext()){
        return;
    }
    if(accept(MULT)){
        term();
        std::cout << "MULT" << std::endl;
    }
    return;
    
}

void Parser::expression(){
    if(!error){
        term();
        if(accept(ADD)){
            expression();
            if(!error){
                std::cout << "ADD" << std::endl;
            }else{
                return;
            }
        } else if(accept(SUB)){
            expression();
            if(!error){
                std::cout << "SUB" << std::endl;
            } else{
                return;
            }
        }else{
            return;
        }
    } else{
        return;
    }
}

void Parser::statement(){
    if(!error){
        std::cout << "PUSH " + token.lexeme << std::endl;
        if(!getNext()){
            return;
        }
        if(accept(ASSIGN)){
            expression();
            std::cout << "ASSIGN" << std::endl;
        }else{
            raiseError();
            return;
        }
        if(!accept(SEMICOL)){
            raiseError();
            return;
        }
    } else{
        return;
    }
}

void Parser::statements(){
    if(!error){
        if(!getNext()){
            return;
        }
        if(accept(ID)){
            statement();
            statements();
            return;
        } else if(accept(PRINT)){
            if(!getNext()){
                return;
            }
            if(accept(ID)){
                std::cout << "PUSH " + token.lexeme << std::endl;
                std::cout << "PRINT" << std::endl;
            } else{
                raiseError();
                return;
            }
            if(!getNext()){
                return;
            }
            if(accept(SEMICOL)){
                statements();
                return;
            } else{
                raiseError();
                return;
            }
        } else if(accept(END)){
            return;
        }
    }else{
        return;
    }
}

void Parser::parse(){
    statements();
}
