#pragma once
#include <iostream>
#include <string>
#include "person.cpp"
#include "Validation.cpp"
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
};