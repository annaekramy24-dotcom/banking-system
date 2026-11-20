#include<iostream>
#include<vector>
using namespace std;

class Client;
class Employee;
class Admin;

class DataSourceInterface { //class has operations that file manager class must define using abstraction
public:
//destructor 3lashan y delete el object sa7 w y clean anything that belongs to it & it doesn’t contain cleanup instructions 
//default 3lashan y ask  the compiler to generate its cleanup behavior automatic

    virtual ~DataSourceInterface() = default;

//functions that is declared in another class
    virtual void addClient(Client obj) = 0;
    virtual void addEmployee(Employee obj) = 0;
    virtual void addAdmin(Admin obj) = 0;

//a method that returns a collection of clients,employees & admins.
    virtual vector<Client> getAllClients() = 0;
    virtual vector<Employee> getAllEmployees() = 0;
    virtual vector<Admin> getAllAdmins() = 0;

    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;
};
//mn el a5errr this file has the nine operations that FileManager must implemnttt