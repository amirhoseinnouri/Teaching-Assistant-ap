#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int id;

    void input() {
        cout << "enter name and id: ";
        cin >> name >> id;
    }

    void display() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};

void saveStudent() {
    Student s;
    s.input();

    ofstream file("students.txt", ios::app);
    file << s.name << " " << s.id << endl;   // save
    file.close(); // close file 
}

void loadStudents() {
    ifstream file("students.txt"); //open file 
    Student s;
    while (file >> s.name >> s.id) {
        s.display(); //show student 
    }
    file.close(); //close file 
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student\n2. View Students\n3. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) saveStudent();
        else if (choice == 2) loadStudents();
    } while (choice != 3);

    return 0;
}