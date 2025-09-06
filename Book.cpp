#include "Book.h"
#include <iostream>
using std::cout;
using std::cin;

book::book(int id, string title, string author, int total_quantity)
    : id(id), title(title), author(author), total_quantity(total_quantity), borrowed(0) {}

void book::read() {
    cout << "Enter Book Id, Title, Author, Total Quantity: ";
    cin >> id >> title >> author >> total_quantity;
    borrowed = 0;
}

void book::print() {
    cout << "Id: " << id
         << ", Title: " << title
         << ", Author: " << author
         << ", Total Quantity: " << total_quantity
         << ", Borrowed: " << borrowed << '\n';
}
