#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string password;

public:
    Person();
    void setName(const string& name);
    void setPassword(const string& password);
    void setId(int id);

    string getName() const;
    int getId() const;
    string getPassword() const;
};

#endif

