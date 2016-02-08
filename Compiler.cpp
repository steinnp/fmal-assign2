#include "Parser.h"

int main(){
    Lexer myLexer;
    Parser myParser = Parser(&myLexer);
    myParser.parse();
    return 0;
}
