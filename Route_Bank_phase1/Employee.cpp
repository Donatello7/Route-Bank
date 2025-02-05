#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee() : salary(5000) {}

void Employee::setSalary(double salary) {
    if (salary >= 5000) {
        this->salary = salary;
    }
    else {
        cout << "Salary cannot be less than 5000!" << endl;
    }
}

double Employee::getSalary() const {
    return salary;
}

void Employee::display() const {
    cout << "Employee ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
}

void Employee::addClient(Client& client) {
    
}

Client* Employee::searchClient(int id) {
    
}

void Employee::listClient() {
   
}

void Employee::editClient(int id, const string& name, const string& password, double balance) {
    
}
