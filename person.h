#pragma once
#include <string>
#include "Validation.cpp"
using namespace std;
class Person {
private:
    int id = 0;
    string name;
    string password;

public:
    virtual ~Person() {}

    void setId(int i) {
        id = i;
    }

    virtual bool setName(string n) {
        if (Validation::checkName(n)) {
            name = n;
            return true;
        }
        return false;
    }

    bool setPassword(string p) {
        if (Validation::checkPassword(p)) {
            password = p;
            return true;
        }
        return false;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    string getPassword() const { return password; }
};