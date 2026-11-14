#pragma once
#include <string>
using namespace std;

class Validation {
public:
   
 static bool checkName(const string& name, size_t minLength = 3, size_t maxLength = 40) {
        if (name.length() < minLength || name.length() > maxLength)
            return false;

        // No leading or trailing space
        if (name.front() == ' ' || name.back() == ' ')
            return false;

        bool hasLetter = false;
        for (size_t i = 0; i < name.length(); i++) {
            char c = name[i];
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                hasLetter = true;
            else if (c == ' ') {
                // No two spaces in a row
                if (i > 0 && name[i - 1] == ' ')
                    return false;
            }
            else
                return false;
        }
        return hasLetter;
    }

  
    static bool checkPassword(const string& password) {
        if (password.length() < 8 || password.length() > 20)
            return false;

        for (size_t i = 0; i < password.length(); i++) {
            if (password[i] == ' ')
                return false;
        }
        return true;
    }

    static bool checkBalance(double balance) {
        return balance >= 1500;
    }

    static bool checkSalary(double salary) {
        return salary >= 5000;
    }
};