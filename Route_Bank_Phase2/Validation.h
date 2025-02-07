// Validation.h
#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
#include <cctype>
using namespace std;

class Validation {
public:
    static bool validateName(const string& name);
    static bool validatePassword(const string& password);
    static bool validateBalance(double balance);
    static bool validateSalary(double salary);
};

#endif 


// Validation.cpp
//#include "Validation.h"

bool Validation::validateName(const string& name) {
    if (name.size() < 5 || name.size() > 20) return false;
    for (char c : name) {
        if (!isalpha(c) && c != ' ') return false;
    }
    return true;
}

bool Validation::validatePassword(const string& password) {
    return password.size() >= 8 && password.size() <= 20;
}

bool Validation::validateBalance(double balance) {
    return balance >= 1500;
}

bool Validation::validateSalary(double salary) {
    return salary >= 5000;
}

