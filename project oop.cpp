#include <iostream>
#include <string>
using namespace std;

class Validation {
public:

static bool checkName(string name, int minLength = 3, int maxLength = 40) {

    if (name.length() < minLength || name.length() > maxLength)
        return false;

    for (int i = 0; i < name.length(); i++) {

        if (!((name[i] >= 'A' && name[i] <= 'Z') ||
              (name[i] >= 'a' && name[i] <= 'z') ||
              name[i] == ' '))
            return false;
    }

    return true;
}

static bool checkPassword(string password) {

    if (password.length() < 8 || password.length() > 20)
        return false;

    for (int i = 0; i < password.length(); i++) {

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

class Client {

private:
int id = 0;
string name;
string password;
double balance = 1500;

public:
void setId(int i) {
    id = i;
}

bool setName(string n) {

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

bool setBalance(double b) {

    if (Validation::checkBalance(b)) {
        balance = b;
        return true;
    }

    return false;
}


int getId() {
    return id;
}

string getName() {
    return name;
}

string getPassword() {
    return password;
}

double getBalance() {
    return balance;
}

void deposit(double amount) {

    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful" << endl;
    }
    else {
        cout << "Invalid amount" << endl;
    }
}


void withdraw(double amount) {

    if (amount > 0 && balance - amount >= 1500) {

        balance -= amount;
        cout << "Withdraw successful" << endl;
    }
    else {
        cout << "Insufficient balance" << endl;
    }
}


void transferTo(double amount, Client &recipient){
    if(amount > balance || (balance - amount) < 1500){
        cout << "Insufficient balance or minimum balance requirement (1500) not met" << endl;
    }
    else{
        balance -= amount;
        recipient.deposit(amount);
    }
}

void checkBalance() {

    cout << "Current Balance: " << balance << endl;
}


void display() {

    cout << "Client ID: " << id << endl;
    cout << "Client Name: " << name << endl;
    cout << "Balance: " << balance << endl;
}

};


class Employee {

private:
int id = 0;
string name;
string password;
double salary = 5000;

public:

void setId(int i) {
    id = i;
}

bool setName(string n) {

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

bool setSalary(double s) {

    if (Validation::checkSalary(s)) {
        salary = s;
        return true;
    }

    return false;
}

int getId() {
    return id;
}

string getName() {
    return name;
}

string getPassword() {
    return password;
}

double getSalary() {
    return salary;
}

void display() {

    cout << "Employee ID: " << id << endl;
    cout << "Employee Name: " << name << endl;
    cout << "Employee Salary: " << salary << endl;
}
};

class Admin : public Employee {

public:

bool setName(string n) {

    if (Validation::checkName(n)) {

        Employee::setName(n);
        return true;
    }

    return false;
}

void display() {

    cout << "Admin ID: " << getId() << endl;
    cout << "Admin Name: " << getName() << endl;
    cout << "Admin Salary: " << getSalary() << endl;
}

};

int main() {
   cout<< Validation ::checkName("       ");

return 0;
}
