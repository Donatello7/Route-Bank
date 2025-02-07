// Parser.h
#ifndef PARSER_H
#define PARSER_H

#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <vector>
#include <string>
using namespace std;

class Parser {
public:
    static vector<string> split(const string& line);
    static Client parseToClient(const string& line);
    static Employee parseToEmployee(const string& line);
    static Admin parseToAdmin(const string& line);
};

#endif


// Parser.cpp
//#include "Parser.h"
#include <sstream>

vector<string> Parser::split(const string& line) {
    vector<string> result;
    stringstream ss(line);
    string item;
    while (getline(ss, item, ',')) {
        result.push_back(item);
    }
    return result;
}

Client Parser::parseToClient(const string& line) {
    vector<string> data = split(line);
    return Client(stoi(data[0]), data[1], data[2], stod(data[3]));
}

Employee Parser::parseToEmployee(const string& line) {
    vector<string> data = split(line);
    return Employee(stoi(data[0]), data[1], data[2], stod(data[3]));
}

Admin Parser::parseToAdmin(const string& line) {
    vector<string> data = split(line);
    return Admin(stoi(data[0]), data[1], data[2], stod(data[3]));
}

