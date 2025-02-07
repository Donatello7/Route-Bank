// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;
    string password;

public:
    Person(int id, const string& name, const string& password);
    void setName(const string& name);
    void setPassword(const string& password);
    int getId() const;
    string getName() const;
    string getPassword() const;
    virtual void display() const = 0;
};

#endif 


// Person.cpp
//#include "Person.h"
#include "Validation.h"
#include <iostream>

Person::Person(int id, const string& name, const string& password) : id(id) {
    setName(name);
    setPassword(password);
}

void Person::setName(const string& name) {
    if (Validation::validateName(name)) {
        this->name = name;
    }
    else {
        throw invalid_argument("Invalid name");
    }
}

void Person::setPassword(const string& password) {
    if (Validation::validatePassword(password)) {
        this->password = password;
    }
    else {
        throw invalid_argument("Invalid password");
    }
}

int Person::getId() const {
    return id;
}

string Person::getName() const {
    return name;
}

string Person::getPassword() const {
    return password;
}
