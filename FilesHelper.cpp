#include "FilesHelper.h"
#include <fstream>
#include <iomanip>
#include "Parser.h"
using namespace std;

vector<Client> FilesHelper::clients;
vector<Employee> FilesHelper::employees;
vector<Admin> FilesHelper::admins;

static void appendLine(const string& fileName, int id, const string& name,
                       const string& password, double value) {
    ofstream out(fileName.c_str(), ios::app);
    out << id << FIELD_DELIMITER << name << FIELD_DELIMITER << password
        << FIELD_DELIMITER << fixed << setprecision(2) << value << endl;
}

static bool readLine(ifstream& in, string& line) {
    while (getline(in, line)) {
        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);
        if (!line.empty())
            return true;
    }
    return false;
}

void FilesHelper::saveLast(string fileName, int id) {
    ofstream out(fileName.c_str());
    out << id;
}

int FilesHelper::getLast(string fileName) {
    ifstream in(fileName.c_str());
    int id = 0;
    if (in >> id)
        return id;
    return 0;
}

void FilesHelper::saveClient(Client c) {
    appendLine(CLIENTS_FILE, c.getId(), c.getName(), c.getPassword(), c.getBalance());
    saveLast(CLIENTS_LAST_ID_FILE, c.getId());
}

void FilesHelper::saveEmployee(string fileName, string lastIdFile, Employee e) {
    appendLine(fileName, e.getId(), e.getName(), e.getPassword(), e.getSalary());
    saveLast(lastIdFile, e.getId());
}

void FilesHelper::fetchClients() {
    clients.clear();
    ifstream in(CLIENTS_FILE.c_str());
    string line;
    while (readLine(in, line)) {
        Client c = Parser::parseToClient(line);
        if (c.getId() != 0)
            clients.push_back(c);
    }
}

void FilesHelper::fetchEmployees() {
    employees.clear();
    ifstream in(EMPLOYEES_FILE.c_str());
    string line;
    while (readLine(in, line)) {
        Employee e = Parser::parseToEmployee(line);
        if (e.getId() != 0)
            employees.push_back(e);
    }
}

void FilesHelper::fetchAdmins() {
    admins.clear();
    ifstream in(ADMINS_FILE.c_str());
    string line;
    while (readLine(in, line)) {
        Admin a = Parser::parseToAdmin(line);
        if (a.getId() != 0)
            admins.push_back(a);
    }
}

void FilesHelper::clearFile(string fileName, string lastIdFile) {
    ofstream out(fileName.c_str(), ios::trunc);
    saveLast(lastIdFile, 0);
}