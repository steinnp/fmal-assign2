#include "Lexer.h"

class Parser{
    public:
        void parse();
        Parser(Lexer*);
        ~Parser();
    private:
        Lexer *lexer;
        Token token;
};

Parser::Parser(Lexer *lex){
    lexer = lex;
}

Parser::~Parser(){
    delete lexer;
}
