#include "Parser.h"
#include <stdexcept>
using namespace std;

vector<string> Parser::split(string line) {
    vector<string> parts;
    string current;
    for (size_t i = 0; i < line.size(); i++) {
        if (line[i] == FIELD_DELIMITER) {
            parts.push_back(current);
            current.clear();
        } else {
            current += line[i];
        }
    }
    parts.push_back(current);
    return parts;
}

static bool unpack(const string& line, int& id, string& name, string& password, double& value) {
    vector<string> p = Parser::split(line);
    if (p.size() < 4)
        return false;
    try {
        id = stoi(p[0]);
        value = stod(p[p.size() - 1]);
    } catch (...) {
        return false;
    }
    name = p[1];
    password = p[2];
    for (size_t i = 3; i + 1 < p.size(); i++)
        password += FIELD_DELIMITER + p[i];
    return true;
}
Client Parser::parseToClient(string line) {
    Client c;
    int id; string name, password; double balance;
    if (!unpack(line, id, name, password, balance))
        return c;
    c.setId(id);
    c.setName(name);
    c.setPassword(password);
    c.setBalance(balance);
    return c;
}

Employee Parser::parseToEmployee(string line) {
    Employee e;
    int id; string name, password; double salary;
    if (!unpack(line, id, name, password, salary))
        return e;
    e.setId(id);
    e.setName(name);
    e.setPassword(password);
    e.setSalary(salary);
    return e;
}

Admin Parser::parseToAdmin(string line) {
    Admin a;
    int id; string name, password; double salary;
    if (!unpack(line, id, name, password, salary))
        return a;
    a.setId(id);
    a.setName(name);
    a.setPassword(password);
    a.setSalary(salary);
    return a;
}