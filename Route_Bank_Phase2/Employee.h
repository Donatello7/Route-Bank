// Employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Client.h"
#include <vector>
using namespace std;

class Employee : public Person {
protected:
    double salary;
    vector<Client> clients;

public:
    Employee(int id, const string& name, const string& password, double salary);
    void setSalary(double salary);
    double getSalary() const;
    void addClient(Client& client);
    Client* searchClient(int id);
    void listClients() const;
    void editClient(int id, const string& name, const string& password, double balance);
    void display() const override;
};

#endif


// Employee.cpp
//#include "Employee.h"
#include "Validation.h"
#include <iostream>

Employee::Employee(int id, const string& name, const string& password, double salary)
    : Person(id, name, password) {
    setSalary(salary);
}

void Employee::setSalary(double salary) {
    if (Validation::validateSalary(salary)) {
        this->salary = salary;
    }
    else {
        throw invalid_argument("Salary must be at least 5000");
    }
}

double Employee::getSalary() const {
    return salary;
}

void Employee::addClient(Client& client) {
    clients.push_back(client);
}

Client* Employee::searchClient(int id) {
    for (auto& client : clients) {
        if (client.getId() == id) {
            return &client;
        }
    }
    return nullptr;
}

void Employee::listClients() const {
    for (const auto& client : clients) {
        client.display();
    }
}

void Employee::editClient(int id, const string& name, const string& password, double balance) {
    Client* client = searchClient(id);
    if (client) {
        client->setName(name);
        client->setPassword(password);
        client->setBalance(balance);
    }
    else {
        throw runtime_error("Client not found");
    }
}

void Employee::display() const {
    cout << "Employee ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
}
