//
// Created by mikas on 11.03.2025.
//

#include "UserTable.h"
#include "WebAccount.h"
#include <unordered_map>
#include <map>

void showMenu() {
    cout << "\n====== User Management Menu ======" << endl;
    cout << " 1 = Create new web account" << endl;
    cout << "2 = Login" << endl;
    cout << "3 = Logout" << endl;
    cout << "4 = Delete web account" << endl;
    cout << "5 = Show active users" << endl;
    cout << " 0 = Exit program" << endl;
}

int main() {

    UserTable uT;
    int choice;
    string username, password;


    while (true) {
        showMenu();
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter Username: ";
                getline(cin, username);
                cout << "Enter password: ";
                getline(cin, password);

                if (uT.addUser(username, password) == 1) {
                    cout << "User added successfully!" << endl;
                } else {
                    cout << "User already exists!" << endl;
                }
                break;

            case 2:
                cout << "Enter Username: ";
                getline(cin, username);
                cout << "Enter password: ";
                getline(cin, password);

                if (uT.login(username, password) == 1) {
                    cout << "Logged in successfully!" << endl;
                } else {
                    cout << "Login failed!" << endl;
                }
                break;

            case 3:
                cout << "Enter Username: ";
                getline(cin, username);
                cout << "Enter password: ";
                getline(cin, password);

                if (uT.logout(username, password) == 1) {
                    cout << "Logged out successfully!" << endl;
                } else {
                    cout << "Logout failed!" << endl;
                }
                break;

            case 4:
                cout << "Enter Username: ";
                getline(cin, username);
                cout << "Enter password: ";
                getline(cin, password);

                if (uT.deleteWebAccount(username, password) == 1) {
                    cout << "Deleted account successfully!" << endl;
                } else {
                    cout << "Deleted failed!" << endl;
                }
                break;

            case 5:
                cout << "All active users: " << "\n";
                uT.showActiveUsers();
                break;

            case 0:
                cout << "Exiting the program" << "\n";
                exit(0);

            default:
                cout << "Wrong input, Try again!" << "\n";
        }

    }

}

