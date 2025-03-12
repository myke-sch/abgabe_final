//
// Created by mikas on 11.03.2025.
//

#ifndef ABGABE_FINAL_USERTABLE_H
#define ABGABE_FINAL_USERTABLE_H

#include "WebAccount.h"
#include <unordered_map>
#include <iostream>
#include "string"

using namespace std;

class UserTable {

private:
    hash<string> hashVal;
    unordered_multimap<size_t, WebAccount> userMap;

    WebAccount* find(string username, string password) {

        size_t hashedPassword = hashVal(password);  // Hash the input password

        auto range = userMap.equal_range(hashedPassword);

        if (range.first == range.second) {
            return nullptr;
        }

        for (auto it = range.first; it != range.second; ++it) {
            if (it->second.getUsername() == username) {
                return &(it->second);
            }
        }
        return nullptr;
    }

public:

    UserTable() {}
    virtual ~UserTable() {};



    int addUser(string username, string password) {
        WebAccount w(username);
        if (find(username,password) == nullptr) {
            userMap.insert({hashVal(password), w});
            return 1;
        } else return 0;
    }

    int login(string username, string password) {
        WebAccount *w = find(username,password);
        if (w != nullptr) {
            w->setLoggedIn(true);
            return 1;
        }
        return 0;
    }

    int logout(string username, string password) {
        WebAccount *w = find(username,password);
        if (w != nullptr) {
            w->setLoggedIn(false);
            return 1;
        }
        return 0;
    }

    int deleteWebAccount(string username, string password) {
        WebAccount *w = find(username,password);
        if (w != nullptr) {
            delete w;
            return 1;
        }
        return 0;
    }

    void showActiveUsers() {
        for(auto it = userMap.begin(); it != userMap.end(); it++) {
            if (it->second.isLoggedIn() == true) {
                cout << it->second.getUsername() << "\n";
            }
        }
    }






};


#endif //ABGABE_FINAL_USERTABLE_H
