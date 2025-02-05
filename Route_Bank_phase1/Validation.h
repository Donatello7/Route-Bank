#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
using namespace std;

class Validation {
public:
    static bool isValidName(const string& name);
    static bool isValidPassword(const string& password);
    static bool isValidBalance(double balance);
    static bool isValidSalary(double salary);
};

#endif

