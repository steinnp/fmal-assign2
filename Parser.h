#include "Lexer.h"

class Parser{
    public:
        void parse();
        Parser(Lexer*);
        ~Parser();
    private:
        Lexer *lexer;
        Token *token;
};
