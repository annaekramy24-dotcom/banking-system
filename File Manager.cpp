#include "File Manager.h"
#include "FilesHelper.h"
using namespace std;

void FileManager::addClient(Client obj) {
    FilesHelper::saveClient(obj);
}

void FileManager::addEmployee(Employee obj) {
    FilesHelper::saveEmployee(EMPLOYEES_FILE, EMPLOYEES_LAST_ID_FILE, obj);
}

void FileManager::addAdmin(Admin obj) {
    FilesHelper::saveEmployee(ADMINS_FILE, ADMINS_LAST_ID_FILE, obj);
}

vector<Client> FileManager::getAllClients() {
    FilesHelper::fetchClients();
    return FilesHelper::clients;
}

vector<Employee> FileManager::getAllEmployees() {
    FilesHelper::fetchEmployees();
    return FilesHelper::employees;
}

vector<Admin> FileManager::getAllAdmins() {
    FilesHelper::fetchAdmins();
    return FilesHelper::admins;
}