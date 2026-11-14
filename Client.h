#pragma once
#include <iostream>
#include <string>
#include "person.cpp"
#include "Validation.cpp"
using namespace std;

class Client : public Person {
private:
    double balance = 1500;

public:
    bool setBalance(double b) {
        if (Validation::checkBalance(b)) {
            balance = b;
            return true;
        }
        return false;
    }

    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful" << endl;
        } else {
            cout << "Invalid amount" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance - amount >= 1500) {
            balance -= amount;
            cout << "Withdraw successful" << endl;
        } else {
            cout << "Insufficient balance" << endl;
        }
    }

    void transferTo(double amount, Client& recipient) {
        if (amount <= 0) {
            cout << "Invalid amount" << endl;
        } else if (balance - amount < 1500) {
            cout << "Insufficient balance or minimum balance requirement (1500) not met" << endl;
        } else {
            balance -= amount;
            recipient.deposit(amount);
            cout << "Transfer successful" << endl;
        }
    }

    void checkBalance() const {
        cout << "Current Balance: " << balance << endl;
    }

    void display() const {
        cout << "Client ID: " << getId() << endl;
        cout << "Client Name: " << getName() << endl;
        cout << "Balance: " << balance << endl;
    }
};