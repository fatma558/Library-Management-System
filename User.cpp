#include "User.h"
#include <iostream>
using std::cout;
using std::cin;

user::user(int id, string name)
    : id(id), name(name) {}

void user::read() {
    cout << "Enter User Id, Name: ";
    cin >> id >> name ;
}

void user::print() {
    cout << "Id: " << id
         << ", Name: " << name<<'\n';
}
