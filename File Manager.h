#pragma once
#include <vector>
#include "DataSourceInterface.h"
using namespace std;

class FileManager : public DataSourceInterface {
public:
    void addClient(Client obj) override;
    void addEmployee(Employee obj) override;
    void addAdmin(Admin obj) override;

    vector<Client> getAllClients() override;
    vector<Employee> getAllEmployees() override;
    vector<Admin> getAllAdmins() override;


    vector<Client> fetchAllClients() { return getAllClients(); }
    vector<Employee> fetchAllEmployees() { return getAllEmployees(); }
    vector<Admin> fetchAllAdmins() { return getAllAdmins(); }

   
};