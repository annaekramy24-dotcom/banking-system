#pragma once
#include <string>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

const string CLIENTS_FILE = "clients.txt";
const string EMPLOYEES_FILE = "employees.txt";
const string ADMINS_FILE = "admins.txt";
const string CLIENTS_LAST_ID_FILE = "clientsLastId.txt";
const string EMPLOYEES_LAST_ID_FILE = "employeesLastId.txt";
const string ADMINS_LAST_ID_FILE = "adminsLastId.txt";

class FilesHelper {
public:
    static vector<Client> clients;
    static vector<Employee> employees;
    static vector<Admin> admins;

    static void saveLast(string fileName, int id);
    static int getLast(string fileName);
    static void saveClient(Client c);
    static void saveEmployee(string fileName, string lastIdFile, Employee e);
    static void fetchClients();
    static void fetchEmployees();
    static void fetchAdmins();
    static void clearFile(string fileName, string lastIdFile);
};