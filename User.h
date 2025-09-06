#ifndef USER_H
#define USER_H

#include <string>
using std::string;

struct user {
    int id;
    string name;
    user() : id(0), name("") {}
    user(int id, string name);

    void read();
    void print();
};

#endif
