// FileManager.h
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface {
public:
    void addClient(Client client) override;
    void addEmployee(Employee employee) override;
    void addAdmin(Admin admin) override;
    vector<Client> getAllClients() override;
    vector<Employee> getAllEmployees() override;
    vector<Admin> getAllAdmins() override;
    void removeAllClients() override;
    void removeAllEmployees() override;
    void removeAllAdmins() override;
};

#endif


// FileManager.cpp
//#include "FileManager.h"

void FileManager::addClient(Client client) {
    FilesHelper::saveClient(client);
}

void FileManager::addEmployee(Employee employee) {
    FilesHelper::saveEmployee("employees.txt", "lastEmployeeId.txt", employee);
}

void FileManager::addAdmin(Admin admin) {
    FilesHelper::saveEmployee("admins.txt", "lastAdminId.txt", admin);
}

vector<Client> FileManager::getAllClients() {
    return FilesHelper::getClients();
}

vector<Employee> FileManager::getAllEmployees() {
    return FilesHelper::getEmployees();
}

vector<Admin> FileManager::getAllAdmins() {
    return FilesHelper::getAdmins();
}

void FileManager::removeAllClients() {
    FilesHelper::clearFile("clients.txt", "lastClientId.txt");
}

void FileManager::removeAllEmployees() {
    FilesHelper::clearFile("employees.txt", "lastEmployeeId.txt");
}

void FileManager::removeAllAdmins() {
    FilesHelper::clearFile("admins.txt", "lastAdminId.txt");
}
