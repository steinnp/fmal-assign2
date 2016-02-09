#include "Lexer.h"

class Parser{
public:
    void parse();
    Parser(Lexer* lex);
private:
    Lexer *lexer;
    Token token;
    bool error;
    void statements();
    void statement();
    int accept(TokenCode);
    bool getNext();
    void raiseError();
    void expression();
    void term();
    void factor();
};
