#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include "Book.h"
#include "User.h"
#include <map>
#include <set>
#include <string>
using namespace std;

#define MAX_BOOKS 1000
#define MAX_USERS 1000

struct Library_System {
    int total_books, total_users;
    book books[MAX_BOOKS];
    user users[MAX_USERS];

    map<string,int> bookTitleToId;
    map<int,string> userIdToName;
    map<string,int> userNameToId;
    map<int,set<int>> usersBorrowedBookId;
    map<int,int> bookIdToIndex;

    Library_System();

    int menu();
    void run();

    void add_book();
    void search_book_by_prefix();
    void print_who_borrowd_book_by_title();

    static bool compareByID(const book &a, const book &b);
    static bool compareByTitle(const book &a, const book &b);

    void print_library_by_id();
    void print_library_by_title();
    void add_user();
    void user_borrow_book();
    void user_return_book();
    void print_users();
};

#endif
