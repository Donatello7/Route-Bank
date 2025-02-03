#include "Admin.h"
#include <iostream>
using namespace std;

void Admin::addEmployee(Employee& employee) {
    cout << "Added new employee: " << employee.getName() << endl;
}

Employee* Admin::searchEmployee(int id) {
    // Placeholder function, implement search logic as required
    return nullptr;
}

void Admin::editEmployee(int id, const string& name, const string& password, double salary) {
    // Placeholder function, implement editing logic as required
    cout << "Editing employee with ID " << id << endl;
}

void Admin::listEmployee() {
    // Placeholder function, implement listing logic as required
    cout << "Listing all employees (currently empty)." << endl;
}

void Admin::addClient(Client& client) {
    cout << "Admin added client: " << client.getName() << endl;
}

void Admin::editClient(int id, const string& name, const string& password, double balance) {
    cout << "Admin edited client with ID " << id << endl;
}

void Admin::listClient() {
    cout << "Listing all clients (currently empty)." << endl;
}
