#include <iostream>
using namespace std;

class User {
private:
    string username;
    string email;

public:
    // سازنده
    User() {}  // سازنده پیش‌فرض
    User(string uname, string uemail) : username(uname), email(uemail) {}

    // نمایش اطلاعات کاربر
    void displayInfo() {
        cout << "Username: " << username << ", Email: " << email << endl;
    }
};

class UserManager {
private:
    User userList[10]; // آرایه ثابت برای حداکثر 10 کاربر
    int userCount = 0; // تعداد کاربران فعلی

public:
    // افزودن کاربر جدید
    void addUser(User newUser) {
        if (userCount < 10) {
            userList[userCount] = newUser;
            userCount++;
            cout << "User added!\n";
        } else {
            cout << "User list is full!\n";
        }
    }

    // نمایش کاربران
    void showAllUsers() {
        cout << "User List:\n";
        for (int i = 0; i < userCount; i++) {
            userList[i].displayInfo();
        }
    }
};

int main() {
    UserManager manager;

    manager.addUser(User("Ali", "ali@gmail.com"));
    manager.addUser(User("Sara", "sara@yahoo.com"));

    manager.showAllUsers();

    return 0;
}