// DataSourceInterface.h
#ifndef DATASOURCEINTERFACE_H
#define DATASOURCEINTERFACE_H

#include "Client.h"
#include "Employee.h"
#include "Admin.h"

class DataSourceInterface {
public:
    virtual void addClient(Client) = 0;
    virtual void addEmployee(Employee) = 0;
    virtual void addAdmin(Admin) = 0;
    virtual vector<Client> getAllClients() = 0;
    virtual vector<Employee> getAllEmployees() = 0;
    virtual vector<Admin> getAllAdmins() = 0;
    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;
};

#endif



