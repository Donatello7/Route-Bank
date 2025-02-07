// Client.h
#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
using namespace std;

class Client : public Person {
private:
    double balance;

public:
    Client(int id, const string& name, const string& password, double balance);
    void setBalance(double balance);
    double getBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
    void transferTo(double amount, Client& recipient);
    void checkBalance() const;
    void display() const override;
};

#endif


// Client.cpp
//#include "Client.h"
#include "Validation.h"
#include <iostream>

Client::Client(int id, const string& name, const string& password, double balance)
    : Person(id, name, password) {
    setBalance(balance);
}

void Client::setBalance(double balance) {
    if (Validation::validateBalance(balance)) {
        this->balance = balance;
    }
    else {
        throw invalid_argument("Balance must be at least 1500");
    }
}

double Client::getBalance() const {
    return balance;
}

void Client::deposit(double amount) {
    balance += amount;
}

void Client::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
    }
    else {
        throw runtime_error("Insufficient balance");
    }
}

void Client::transferTo(double amount, Client& recipient) {
    if (balance >= amount) {
        balance -= amount;
        recipient.deposit(amount);
    }
    else {
        throw runtime_error("Insufficient balance for transfer");
    }
}

void Client::checkBalance() const {
    cout << "Current Balance: " << balance << endl;
}

void Client::display() const {
    cout << "Client ID: " << id << ", Name: " << name << ", Balance: " << balance << endl;
}
