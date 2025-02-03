#ifndef ADMIN_H
#define ADMIN_H

#include "Employee.h"

class Admin : public Employee {
public:
    void addEmployee(Employee& employee);
    Employee* searchEmployee(int id);
    void editEmployee(int id, const string& name, const string& password, double salary);
    void listEmployee();
    void addClient(Client& client);
    void editClient(int id, const string& name, const string& password, double balance);
    void listClient();
};

#endif

