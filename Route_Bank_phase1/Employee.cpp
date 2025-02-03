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
    cout << "Added client: " << client.getName() << endl;
}

Client* Employee::searchClient(int id) {
    // Placeholder function, implement search logic as required
    return nullptr;
}

void Employee::listClient() {
    // Placeholder function, implement listing logic as required
    cout << "Listing all clients (currently empty)." << endl;
}

void Employee::editClient(int id, const string& name, const string& password, double balance) {
    // Placeholder function, implement editing logic as required
    cout << "Editing client with ID " << id << endl;
}
