// Admin.h
#ifndef ADMIN_H
#define ADMIN_H

#include "Employee.h"
using namespace std;

class Admin : public Employee {
private:
    vector<Employee> employees;

public:
    Admin(int id, const string& name, const string& password, double salary);
    void addClient(Client& client);
    Client* searchClient(int id);
    void listClients() const;
    void editClient(int id, const string& name, const string& password, double balance);
    void addEmployee(Employee& employee);
    Employee* searchEmployee(int id);
    void editEmployee(int id, const string& name, const string& password, double salary);
    void listEmployees() const;
    void display() const override;
};

#endif


// Admin.cpp
//#include "Admin.h"
#include <iostream>

Admin::Admin(int id, const string& name, const string& password, double salary)
    : Employee(id, name, password, salary) {
}

void Admin::addClient(Client& client) {
    clients.push_back(client);
}

Client* Admin::searchClient(int id) {
    for (auto& client : clients) {
        if (client.getId() == id) {
            return &client;
        }
    }
    return nullptr;
}

void Admin::listClients() const {
    for (const auto& client : clients) {
        client.display();
    }
}

void Admin::editClient(int id, const string& name, const string& password, double balance) {
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

void Admin::addEmployee(Employee& employee) {
    employees.push_back(employee);
}

Employee* Admin::searchEmployee(int id) {
    for (auto& employee : employees) {
        if (employee.getId() == id) {
            return &employee;
        }
    }
    return nullptr;
}

void Admin::editEmployee(int id, const string& name, const string& password, double salary) {
    Employee* employee = searchEmployee(id);
    if (employee) {
        employee->setName(name);
        employee->setPassword(password);
        employee->setSalary(salary);
    }
    else {
        throw runtime_error("Employee not found");
    }
}

void Admin::listEmployees() const {
    for (const auto& employee : employees) {
        employee.display();
    }
}

void Admin::display() const {
    cout << "Admin ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
}