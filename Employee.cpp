#include "Employee.h"
#include "File Manager.h"
#include "FilesHelper.h"
using namespace std;

void Employee::addClient(Client& client) {
    FileManager fm;
    client.setId(FilesHelper::getLast(CLIENTS_LAST_ID_FILE) + 1);
    fm.addClient(client);
    cout << "Client added with ID: " << client.getId() << endl;
}

Client* Employee::searchClient(int id) {
    FileManager fm;
    vector<Client> all = fm.getAllClients();
    for (size_t i = 0; i < all.size(); i++) {
        if (all[i].getId() == id)
            return new Client(all[i]);
    }
    return nullptr;
}

void Employee::listClient() {
    FileManager fm;
    vector<Client> all = fm.getAllClients();
    if (all.empty()) {
        cout << "No clients found" << endl;
        return;
    }
    for (size_t i = 0; i < all.size(); i++) {
        all[i].display();
        cout << "-------------------" << endl;
    }
}

void Employee::editClient(int id, string name, string password, double balance) {
    Client* found = searchClient(id);
    if (found == nullptr) {
        cout << "Client not found" << endl;
        return;
    }

    Client updated = *found;
    delete found;

    if (!updated.setName(name) || !updated.setPassword(password) || !updated.setBalance(balance)) {
        cout << "Invalid data, client was not updated" << endl;
        return;
    }

    FileManager fm;
    fm.UpdateClient(updated);
    cout << "Client updated" << endl;
}