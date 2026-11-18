#pragma once
#include <iostream>
#include <string>
#include "Client.h"
#include "person.h"
#include "Validation.h"
using namespace std;

class Employee : public Person {
private:
    double salary = 5000;

public:
    bool setSalary(double s) {
        if (Validation::checkSalary(s)) {
            salary = s;
            return true;
        }
        return false;
    }

    double getSalary() const { return salary; }

    void display() const {
        cout << "Employee ID: " << getId() << endl;
        cout << "Employee Name: " << getName() << endl;
        cout << "Employee Salary: " << salary << endl;
    }
void addClient(Client& client);
    Client* searchClient(int id);   
    void listClient();
    void editClient(int id, string name, string password, double balance);

};