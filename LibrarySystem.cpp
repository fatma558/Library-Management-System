#include "LibrarySystem.h"
#include <iostream>
#include <algorithm>
using namespace std;

Library_System::Library_System() {
    total_books = total_users = 0;
}

int Library_System::menu() {
    cout << "1) Add book\n2) Search book by prefix\n3) Print who borrowed book\n";
    cout << "4) Print library by ID\n5) Print library by title\n6) Add user\n";
    cout << "7) User borrow book\n8) User return book\n9) Print users\nChoice: ";
    int choice; cin >> choice;
    return choice;
}

void Library_System::run() {
    while (true) {
        int choice = menu();
        switch (choice) {
            case 1: add_book(); break;
            case 2: search_book_by_prefix(); break;
            case 3: print_who_borrowd_book_by_title(); break;
            case 4: print_library_by_id(); break;
            case 5: print_library_by_title(); break;
            case 6: add_user(); break;
            case 7: user_borrow_book(); break;
            case 8: user_return_book(); break;
            case 9: print_users(); break;
            default: return; // exit loop
        }
    }
}

void Library_System::add_book() {
    books[total_books].read();
    bookTitleToId[books[total_books].title] = books[total_books].id;
    bookIdToIndex[books[total_books].id] = total_books;
    total_books++;
}

void Library_System::search_book_by_prefix() {
    cout << "Enter Prefix: ";
    string prefix; cin >> prefix;
    int cnt = 0;
    for (int i = 0; i < total_books; i++) {
        if (books[i].title.rfind(prefix, 0) == 0) {
            cout << books[i].title << '\n';
            cnt++;
        }
    }
    if (!cnt) cout << "No such book\n";
}

void Library_System::print_who_borrowd_book_by_title() {
    cout << "Enter Book Name: ";
    string name; cin >> name;
    if (!bookTitleToId.count(name)) {
        cout << "No such book\n";
        return;
    }
    int bookId = bookTitleToId[name];
    int cnt = 0;
    for (auto userId : usersBorrowedBookId[bookId]) {
        cout << userIdToName[userId] << '\n';
        cnt++;
    }
    if (!cnt) cout << "Nobody borrowed this book\n";
}

bool Library_System::compareByID(const book &a, const book &b) {
    return a.id < b.id;
}

bool Library_System::compareByTitle(const book &a, const book &b) {
    return a.title < b.title;
}

void Library_System::print_library_by_id() {
    sort(books, books + total_books, compareByID);
    for (int i = 0; i < total_books; i++) {
        books[i].print();
    }
}

void Library_System::print_library_by_title() {
    sort(books, books + total_books, compareByTitle);
    for (int i = 0; i < total_books; i++) {
        books[i].print();
    }
}

void Library_System::add_user() {
    users[total_users].read();
    userIdToName[users[total_users].id] = users[total_users].name;
    userNameToId[users[total_users].name] = users[total_users].id;
    total_users++;
}

void Library_System::user_borrow_book() {
    cout << "Enter User Name, Book Title: ";
    string name, title; cin >> name >> title;
    int bookId = bookTitleToId[title];
    int userId = userNameToId[name];
    int bookIndx = bookIdToIndex[bookId];
    if (books[bookIndx].borrowed == books[bookIndx].total_quantity)
        cout << "There is no remaining copies\n";
    else {
        usersBorrowedBookId[bookId].insert(userId);
        books[bookIndx].borrowed++;
        cout << "Borrowing is done successfully\n";
    }
}

void Library_System::user_return_book() {
    cout << "Enter User Name, Book Title: ";
    string name, title; cin >> name >> title;
    int bookId = bookTitleToId[title];
    int userId = userNameToId[name];
    int bookIndx = bookIdToIndex[bookId];
    usersBorrowedBookId[bookId].erase(userId);
    books[bookIndx].borrowed--;
    cout << "Returning is done successfully\n";
}

void Library_System::print_users() {
    for (int i = 0; i < total_users; i++) {
        users[i].print();
    }
}
