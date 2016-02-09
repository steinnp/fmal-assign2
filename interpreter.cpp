//#include "interpreter.h"
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

Interpret::Interpret(std::stack<std::string> command){
    commands = command;
    err = false;
}

bool areDigits(std::string digits){
    if(digits[0] != '-' && !isdigit(digits[0])){
        return false;
    }
    for(unsigned int i = 1; i < digits.length(); i++){
        if(!isdigit(digits[i])){
            return false;
        }
    }
    return true;
}

bool Interpret::subtract(){
    if(values.size() < 2){
        return false;
    } else{
        std::string first = values.top();
        values.pop();
        std::string second = values.top();
        values.pop();
        int a;
        int b;
        if(areDigits(first)){
            b = stoi(first);
        } else{
            if(variables.count(first) > 0){
                b = stoi(variables[first]);
            } else{
                return false;
            }
        }
        if(areDigits(second)){
            a = stoi(second);
        } else{
            if(variables.count(second) > 0){
                a = stoi(variables[second]);
            } else{
                return false;
            }
        }
        a = a-b;
        values.push(std::to_string(static_cast<long long>(a)));
        return true;
    }
}

bool Interpret::add(){
    if(values.size() < 2){
        return false;
    } else{
        std::string first = values.top();
        values.pop();
        std::string second = values.top();
        values.pop();
        int a;
        int b;
        if(areDigits(first)){
            a = stoi(first);
        } else{
            if(variables.count(first) > 0){
                a = stoi(variables[first]);
            } else{
                return false;
            }
        }
        if(areDigits(second)){
            b = stoi(second);
        } else{
            if(variables.count(second) > 0){
                b = stoi(variables[second]);
            } else{
                return false;
            }
        }
        a = a+b;
        values.push(std::to_string(static_cast<long long>(a)));
        return true;
    }
}

bool Interpret::multiply(){
    if(values.size() < 2){
        return false;
    } else{
        std::string first = values.top();
        values.pop();
        std::string second = values.top();
        values.pop();
        int a;
        int b;
        if(areDigits(first)){
            a = stoi(first);
        } else{
            if(variables.count(first) > 0){
                a = stoi(variables[first]);
            } else{
                return false;
            }
        }
        if(areDigits(second)){
            b = stoi(second);
        } else{
            if(variables.count(second) > 0){
                b = stoi(variables[second]);
            } else{
                return false;
            }
        }
        a = a*b;
        values.push(std::to_string(static_cast<long long>(a)));
        return true;
    }
}

bool Interpret::assign(){
    if(values.size() < 2){
        return false;
    } else{
        std::string value = values.top();
        values.pop();
        std::string variable = values.top();
        values.pop();
        variables[variable] = value;
        return true;
    }
}

bool Interpret::print(){
    if(!values.empty()){
        if(variables.count(values.top()) > 0){
            std::cout << variables[values.top()] << std::endl;
            values.pop();
            return true;
        }else{
            return false;
        }
    } else{
        return false;
    }
}

bool Interpret::push(std::string val){
    values.push(val);
    return true;
}

void Interpret::error(std::string command){
    std::cout << "Error for operator: " << command << std::endl;
    err = true;
    return;
}

void Interpret::processCommand(std::string command){
    if(command == "SUB"){
        if(!subtract()){
            error(command);
            return;
        }
    } else if(command == "ADD"){
        if(!add()){
            error(command);
            return;
        }
    } else if(command == "MULT"){
        if(!multiply()){
            error(command);
            return;
        }
    } else if(command == "ASSIGN"){
        if(!assign()){
            error(command);
            return;
        }
    } else if(command == "PRINT"){
        if(!print()){
            error(command);
            return;
        }
    } else if(command.size() > 5 && command.substr(0,4) == "PUSH"){
        if(!push(command.substr(5))){
            error(command);
            return;
        }
    } else{
        error(command);
    }
}

void Interpret::calculate(){
    while(!commands.empty() && err == false){
        std::string nextCommand = commands.top();
        commands.pop();
        processCommand(nextCommand);
    }
}

int main(){
    std::string nextCommand;
    std::stack<std::string> reverseCommands;
    std::stack<std::string> commands;
    while(getline(std::cin, nextCommand)){
        reverseCommands.push(nextCommand);
    }
    while(!reverseCommands.empty()){
        commands.push(reverseCommands.top());
        reverseCommands.pop();
    }
    Interpret interpreter(commands);
    interpreter.calculate();
    return 0;
}
