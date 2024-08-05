#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;
    bool status;

    // Constructor
    Book(string t, string a, string isbn) : title(t), author(a), ISBN(isbn), status(true) {}

    // Display Book Details
    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << ISBN << ", Available: " << (status ? "Yes" : "No") << endl;
    }

    //Setters
    void setStatus(bool s) { status = s; }

    //Getters
    bool getStatus() const { return status; }
};
class Member {
public:
    string name;
    string memberID;
    vector<Book> borrowedBooks;

    // Constructor
    Member(string n, string id) : name(n), memberID(id) {}

    // Display Member Details
    void display() const {
        cout << "Name: " << name << ", Member ID: " << memberID << endl;
        cout << "Borrowed Books: " << endl;
        for (Book b : borrowedBooks) {
            b.display();
        }
    }

    // Borrow Book
    void borrowBook(Book &b) {
        if (b.getStatus()) {
            borrowedBooks.push_back(b);
            b.setStatus(false);
        } else {
            cout << "Book is not available" << endl;
        }
    }

    // Return Book
    void returnBook(Book &b) {
        for (int i = 0; i < borrowedBooks.size(); i++) {
            if (borrowedBooks[i].ISBN == b.ISBN) {
                borrowedBooks.erase(borrowedBooks.begin() + i);
                b.setStatus(true);
                return;
            }
        }
        cout << "Book not found" << endl;
    }
};
class Library{
public:
    vector<Book> books;
    vector<Member> members;

    // Add Book
    void addBook(Book b) {
        books.push_back(b);
    }

    // Add Member
    void addMember(Member m) {
        members.push_back(m);
    }

    // Display Books
    void displayBooks() const {
        cout << "Books in Library: " << endl;
        for (Book b : books) {
            b.display();
        }
    }

    // Display Members
    void displayMembers() const {
        cout << "Members in Library: " << endl;
        for (Member m : members) {
            m.display();
        }
    }
};
int main(){
    Library lib;
    Book listOfBooks[10] = {
        {"Book1","Author1","ISBN1"},
        {"Book2","Author2","ISBN2"},
        {"Book3","Author3","ISBN3"},
        {"Book4","Author4","ISBN4"},
        {"Book5","Author5","ISBN5"},
        {"Book6","Author6","ISBN6"},
        {"Book7","Author7","ISBN7"},
        {"Book8","Author8","ISBN8"},
        {"Book9","Author9","ISBN9"},
        {"Book10","Author10","ISBN10"}
    };
    for(int i =0; i<10; i++){
        lib.addBook(listOfBooks[i]);
    }
    Member listOfMembers[5] = {
        {"Member1","M1"},
        {"Member2","M2"},
        {"Member3","M3"},
        {"Member4","M4"},
        {"Member5","M5"}
    };
    for(int i =0; i<5; i++){
        lib.addMember(listOfMembers[i]);
    }
    lib.displayBooks();
    lib.displayMembers();
    listOfMembers[0].borrowBook(listOfBooks[0]);
    cout << "After borrowing Book1 by Member1" << endl;
    lib.displayBooks();
    lib.displayMembers();
    return 0;
}