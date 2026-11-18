
#pragma once
#include <iostream>
#include <string>
#include "Employee"
#include "Validation.cpp"
using namespace std;
 
class Admin : public Employee {
public:
    bool setName(string n) override {
        if (!Validation::checkName(n, 3, 20))
            return false;
        return Employee::setName(n);
    }
 
    void display() const {
        cout << "Admin ID: " << getId() << endl;
        cout << "Admin Name: " << getName() << endl;
        cout << "Admin Salary: " << getSalary() << endl;
    }
};
