#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

class Validation {
public:
    static bool isValidName(const std::string& name);
    static bool isValidPassword(const std::string& password);
    static bool isValidBalance(double balance);
    static bool isValidSalary(double salary);
};

#endif

