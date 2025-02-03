#include "Client.h"
#include <iostream>
using namespace std;

Client::Client() : balance(1500) {}

void Client::setBalance(double balance) {
    if (balance >= 1500) {
        this->balance = balance;
    }
    else {
        cout << "Minimum balance must be 1500!" << endl;
    }
}

double Client::getBalance() const {
    return balance;
}

void Client::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposited " << amount << " to your account. New balance: " << balance << endl;
    }
    else {
        cout << "Invalid deposit amount!" << endl;
    }
}

void Client::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        cout << "Withdraw " << amount << " from your account. New balance: " << balance << endl;
    }
    else {
        cout << "Invalid withdrawal amount or insufficient balance!" << endl;
    }
}

void Client::transferTo(double amount, Client& recipient) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        recipient.deposit(amount);
        cout << "Transferred " << amount << " to client ID " << recipient.getId() << endl;
    }
    else {
        cout << "Transfer failed! Invalid amount or insufficient balance." << endl;
    }
}

void Client::checkBalance() const {
    cout << "Your current balance: " << balance << endl;
}

void Client::display() const {
    cout << "Client ID: " << id << ", Name: " << name << ", Balance: " << balance << endl;
}
