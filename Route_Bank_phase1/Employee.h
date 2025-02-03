#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Client.h"

class Employee : public Person {
private:
    double salary;

public:
    Employee();
    void setSalary(double salary);
    double getSalary() const;
    void display() const;
    void addClient(Client& client);
    Client* searchClient(int id);
    void listClient();
    void editClient(int id, const string& name, const string& password, double balance);
};

#endif

