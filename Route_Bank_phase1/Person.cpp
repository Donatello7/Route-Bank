#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() : id(0), name(""), password("") {}

void Person::setName(const string& name) {
    this->name = name;
}

void Person::setPassword(const string& password) {
    this->password = password;
}

void Person::setId(int id) {
    this->id = id;
}

string Person::getName() const {
    return name;
}

int Person::getId() const {
    return id;
}

string Person::getPassword() const {
    return password;
}
