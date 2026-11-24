#include "Admin.h"
#include "File Manager.h"
#include "FilesHelper.h"
using namespace std;



Client* Admin::searchClient(int id) {
    return Employee::searchClient(id);
}

void Admin::listClient() {
    Employee::listClient();
}

void Admin::editClient(int id, string name, string password, double balance) {
    Employee::editClient(id, name, password, balance);
}