#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"

class Client : public Person {
private:
    double balance;

public:
    Client();
    void setBalance(double balance);
    double getBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
    void transferTo(double amount, Client& recipient);
    void checkBalance() const;
    void display() const;
};

#endif

