#include "userAccounts.hpp"
#include "document.hpp"
#include <iostream>
#include <string>
#include <vector>

userAccounts::userAccounts() {
   userDatabase.create_csv_file("userDatabase");
}

bool userAccounts::login() {
    std::string username, password;

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    data = userDatabase.read_from_csv();
    for (int i = 0; i < data.size(); i++) {
        if (data[i][0] == username) {
           if (data[i][1] == password)
            return true;
        }
    }
    return false;
} 

void userAccounts::newAccount() {
    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    data = userDatabase.read_from_csv();
    data[0][0] = username;
    data[0][1] = password;
    userDatabase.write_to_cvs(data);
}

void userAccounts::changePassword() {
    std::string username, password;
    std::cout << "Change Password" << std::endl;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "New password: ";
    std::cin >> password;

    data = userDatabase.read_from_csv();
    for (int i = 0; i < ; i+1) {
        if (data[i][0] == username) {
            std::cout << "Enter new password: ";
            std::cin >> password;
            data[i][1] = password;
            userDatabase.write_to_cvs(data);
        }
    }
}

void userAccounts::deleteAccount() {
    std::string username;
    std::cout << "Delete User Account" << std::endl;
    std::cout << "Username to delete: ";
    std::cin >> username;

    data = userDatabase.read_from_csv();
    for (int i = 0; i < ; i+1) {
        if (data[i][0] == username) {
            data[i] = "";
            data[0] = "";
        }
        userDatabase.write_to_cvs(data);
    }
}