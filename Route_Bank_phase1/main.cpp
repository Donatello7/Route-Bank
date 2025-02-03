#include <iostream>
#include "Admin.h"
#include "Validation.h"

using namespace std;

int main() {
   
    Client client1;
    client1.setId(1);
    client1.setName("Zainab");
    client1.setPassword("Iraq123");
    client1.setBalance(2000);

    
    client1.display();

    
    client1.deposit(500);

    
    client1.withdraw(300);

    // Create client to recieve money
    Client client2;
    client2.setId(2);
    client2.setName("Shymaa");
    client2.setPassword("Doctor123");
    client2.setBalance(2500);

    // tranfer
    client1.transferTo(200, client2);

    // Data of 2 Clients after transfer
    client1.display();
    client2.display();

    // Create Employee
    Employee employee;
    employee.setId(100);
    employee.setName("Ahmed");
    employee.setPassword("Superman123");
    employee.setSalary(6000);

    // Data of Emloyee
    employee.display();

    // Employee add Client
    employee.addClient(client1);

    // Create Admin
    Admin admin;
    admin.setId(200);
    admin.setName("Mohamed");
    admin.setPassword("Egypt123");
    admin.setSalary(10000);

    // Data of Admin
    admin.display();

    // Admin add Employee
    admin.addEmployee(employee);

    // Admin add Client
    admin.addClient(client2);

    //  Validation
    string testName = "Ali";
    if (Validation::isValidName(testName)) {
        cout << testName << " is a valid name." << endl;
    }
    else {
        cout << testName << " is not a valid name." << endl;
    }

    string testPassword = "short";
    if (Validation::isValidPassword(testPassword)) {
        cout << testPassword << " is a valid password." << endl;
    }
    else {
        cout << testPassword << " is not a valid password." << endl;
    }

    return 0;
}
