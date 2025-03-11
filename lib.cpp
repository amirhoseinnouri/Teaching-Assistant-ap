#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;

public:
    // سازنده پیش‌فرض
    Book() {}  

    // سازنده با مقداردهی اولیه
    Book(string bTitle, string bAuthor) : title(bTitle), author(bAuthor) {}

    // نمایش اطلاعات کتاب
    void displayInfo() {
        cout << "Title: " << title << ", Author: " << author << endl;
    }
};

class Library {
private:
    Book bookList[10];  // آرایه‌ای برای ذخیره حداکثر 10 کتاب
    int bookCount = 0;   // شمارنده تعداد کتاب‌ها

public:
    // افزودن کتاب جدید
    void addBook(Book newBook) {
        if (bookCount < 10) {
            bookList[bookCount] = newBook;
            bookCount++;
            cout << "Book added!\n";
        } else {
            cout << "Library is full!\n";
        }
    }

    // نمایش لیست کتاب‌ها
    void showAllBooks() {
        cout << "Book List:\n";
        for (int i = 0; i < bookCount; i++) {
            bookList[i].displayInfo();
        }
    }
};

int main() {
    Library library;

    library.addBook(Book("1984", "George Orwell"));
    library.addBook(Book("The Alchemist", "Paulo Coelho"));

    library.showAllBooks();

    return 0;
}