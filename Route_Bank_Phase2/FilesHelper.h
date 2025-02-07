// FilesHelper.h
#ifndef FILESHELPER_H
#define FILESHELPER_H

#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <string>
#include <vector>
using namespace std;

class FilesHelper {
public:
    static void saveLast(const string& fileName, int id);  //Saves the last ID in a specific file.
    static int getLast(const string& fileName);  //Retrieves the last ID from a file
    static void saveClient(const Client& c);  
    static void saveEmployee(const string& fileName, const string& lastIdFile, const Employee& e);
    static vector<Client> getClients();
    static vector<Employee> getEmployees();
    static vector<Admin> getAdmins();
    static void clearFile(const string& fileName, const string& lastIdFile);
};

#endif



// FilesHelper.cpp
//#include "FilesHelper.h"
#include "Parser.h"
#include <fstream>
#include <iostream>

void FilesHelper::saveLast(const string& fileName, int id) {
    ofstream file(fileName);
    if (file.is_open()) {
        file << id;
        file.close();
    }
    else {
        cerr << "Error opening file: " << fileName << endl;
    }
}

int FilesHelper::getLast(const string& fileName) {
    ifstream file(fileName);
    int id = 0;
    if (file.is_open()) {
        file >> id;
        file.close();
    }
    return id;
}

void FilesHelper::saveClient(const Client& c) {
    ofstream file("clients.txt", ios::app);
    if (file.is_open()) {
        file << c.getId() << "," << c.getName() << "," << c.getPassword() << "," << c.getBalance() << endl;
        file.close();
    }
    else {
        cerr << "Error opening clients.txt" << endl;
    }
}

void FilesHelper::saveEmployee(const string& fileName, const string& lastIdFile, const Employee& e) {
    ofstream file(fileName, ios::app);
    if (file.is_open()) {
        file << e.getId() << "," << e.getName() << "," << e.getPassword() << "," << e.getSalary() << endl;
        file.close();
        saveLast(lastIdFile, e.getId());
    }
    else {
        cerr << "Error opening " << fileName << endl;
    }
}

vector<Client> FilesHelper::getClients() {
    vector<Client> clients;
    ifstream file("clients.txt");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            clients.push_back(Parser::parseToClient(line));
        }
        file.close();
    }
    else {
        cerr << "Error opening clients.txt" << endl;
    }

    return clients;
}

vector<Employee> FilesHelper::getEmployees() {
    vector<Employee> employees;
    ifstream file("employees.txt");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            employees.push_back(Parser::parseToEmployee(line));
        }
        file.close();
    }
    else {
        cerr << "Error opening employees.txt" << endl;
    }

    return employees;
}

vector<Admin> FilesHelper::getAdmins() {
    vector<Admin> admins;
    ifstream file("admins.txt");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            admins.push_back(Parser::parseToAdmin(line));
        }
        file.close();
    }
    else {
        cerr << "Error opening admins.txt" << endl;
    }

    return admins;
}

void FilesHelper::clearFile(const string& fileName, const string& lastIdFile) {
    ofstream file(fileName, ios::trunc);
    ofstream lastId(lastIdFile, ios::trunc);

    if (file.is_open() && lastId.is_open()) {
        file.close();
        lastId.close();
    }
    else {
        cerr << "Error clearing file: " << fileName << endl;
    }
}
