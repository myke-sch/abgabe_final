//
// Created by mikas on 11.03.2025.
//

#ifndef ABGABE_FINAL_WEBACCOUNT_H
#define ABGABE_FINAL_WEBACCOUNT_H

#include "string"

class WebAccount {
private:
    std::string username;
    bool loggedIn;

public:

    WebAccount(const std::string& u) : username(u) {
        loggedIn = false;
    }
    virtual ~WebAccount();

    std::string getUsername() const {
        return username;
    }

    bool isLoggedIn() const {
        return loggedIn;
    }

    void setLoggedIn(bool status) {
        loggedIn = status;
    }

};


#endif //ABGABE_FINAL_WEBACCOUNT_H
