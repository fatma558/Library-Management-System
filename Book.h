#ifndef BOOK_H
#define BOOK_H

#include <string>
using std::string;

struct book {
    int id;
    string title, author;
    int total_quantity;
    int borrowed;
    book() : id(0), title(""), author(""), total_quantity(0), borrowed(0) {}
    book(int id, string title, string author, int total_quantity);

    void read();
    void print();
};

#endif
