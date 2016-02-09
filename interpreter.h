#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <map>

class Interpret{
public:
    Interpret(std::stack<std::string>);
    void calculate();
private:
    std::stack<std::string> values;
    std::map<std::string,std::string> variables;
    std::stack<std::string> commands;
    bool err;
    void processCommand(std::string);
    bool subtract();
    bool add();
    bool multiply();
    bool assign();
    bool print();
    bool push(std::string);
    void error(std::string);
};
