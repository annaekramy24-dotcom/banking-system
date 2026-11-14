#include <iostream>
#include "Client"
#include "Employee"
#include "Admin"
using namespace std;

int main() {
    cout << Validation::checkName("       ") << endl; // 0 (spaces only)

    Client a, b;
    a.setId(1); a.setName("Ahmed Ali"); a.setPassword("pass@1234"); a.setBalance(5000);
    b.setId(2); b.setName("Sara Hassan"); b.setPassword("secret#99"); b.setBalance(2000);
    a.transferTo(1000, b);
    a.display();
    b.display();

    Admin ad;
    ad.setId(1);
    cout << ad.setName("This name is longer than twenty") << endl; // 0
    ad.setName("Admin One"); ad.setPassword("admin@123"); ad.setSalary(9000);
    ad.display();
    return 0;
}