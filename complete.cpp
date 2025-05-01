#include <iostream>
#include <fstream> // new for file 
#include <string>
using namespace std;

void addStudent() {
    ofstream file("complete.txt", ios::app);
    string name;
    int id;

    cout << "enter name: ";
    cin >> name;
    cout << "enter id: ";
    cin >> id;

    file << name << " " << id << endl;
    file.close();
}
void viewStudents() {
    ifstream file("complete.txt");
    string name;
    int id;
    while (file >> name >> id) {
        cout << "name: " << name << ", id: " << id << endl;
    }
    file.close();
}
void deleteStudent() {
    ifstream file("complete.txt");
    ofstream temp("temp.txt");
    int id, deleteId;
    string name;

    cout << "enter id to delete: ";
    cin >> deleteId;

    while (file >> name >> id) {
        if (id != deleteId)
            temp << name << " " << id << endl;
    }
    file.close();
    temp.close();
    remove("complete.txt");
    rename("temp.txt", "complete.txt");
}

void editStudent() {
    ifstream file("complete.txt");
    ofstream temp("temp.txt");
    int id, editId, newId;
    string name, newName;
    cout << "Enter ID to edit: ";
    cin >> editId;
    while (file >> name >> id) {
        if (id == editId) {
            cout << "enter new name and new ID: ";
            cin >> newName >> newId;
            temp << newName << " " << newId << endl;
        } else {
            temp << name << " " << id << endl;
        }
    }
    file.close();
    temp.close();
    remove("complete.txt");
    rename("temp.txt", "complete.txt");
}

int main() {
    int choice;
    do {
        cout << "\n1. Add\n2. View\n3. Delete\n4. Edit\n5. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: deleteStudent(); break;
            case 4: editStudent(); break;
        }
    } while (choice != 5);

    return 0;
}
