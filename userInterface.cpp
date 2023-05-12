// Terminal user interface

#include "userInterface.hpp"
//#include "userAccounts.hpp"
#include "iostream"

// Main Menu
void userInterface::mainMenu() {
    std::cout << "Document Data Store" << std::endl;
    
    char userSelect;
    
    while ((userSelect != 'n') || (userSelect != 'N')) {
        loginMenu();
        std::cout << "Continue (y/n)?: ";
        cin >> userSelect;
    }
}

// Login Menu
// void userInterface::loginMenu() {   
//     char option;
//     char userSelect;
//     while (option != 'q') {
//         std::cout << "Select from the following " << std::endl;
//         std::cout << "[1] Login" << std::endl;
//         std::cout << "[2] Account Management" << std::endl;
//         std::cout << "[3] Quit" << std::endl;
//         std::cout << "Selection: ";
//         cin >> userSelect;
        
//         if (userSelect == '1') {
//             loggedIn = currentUser.login();
//             if (loggedIn == true) {
//                 documentMenu();
//             }
//         } else if (userSelect == '2') {
//             accountManagement();
//         } else if (userSelect == '3') {
//             option = 'q'
//         } else {
//             std::cout << "Error: invalid selection." std::endl;
//         }
//     }
// }
    
// Account Management Menu
// void userInterface::accountManagement() {
//     char option;
//     char userSelect;

//     while(option != 'q') {
//         if (loggedIn == false) {
//             loggedIn = currentUser.login();
//         }

//         if (loggedIn == true) {
//             std::cout << "Account Management" << std::endl;
//             std::cout << "[1] Create New Account" << std::endl;
//             std::cout << "[2] Change Password" << std::endl;
//             std::cout << "[3] Delete Account" << std::endl;
//             std::cout << "[4] Return to Previous Menu" << std::endl;
//             std::cout << "Selection: ";
//             cin >> userSelect;

//             if (userSelect == '1') {
//                 currentUser.newAccount();
//             } else if (userSelect == '2') {
//                 currentUser.changePassword();
//             } else if (userSelect == '3') {
//                 currentUser.deleteAccount();
//             } else if (userSelect == '3') {
//                 option = 'q';
//             } else {
//                 std::cout << "Error: invalid selection." std::endl;
//             }
//         }
//     }
// }

// Document Menu
void documentMenu()
{
    char option;
    char userSelect;

    while(option != 'q') {
        // if (loggedIn == false) {
        //     loggedIn = currentUser.login();
        // }

        //if (loggedIn == true) {
            std::cout << "Document Management" << std::endl;
            std::cout << "[1] Create New" << std::endl;
            std::cout << "[2] Search" << std::endl;
            std::cout << "[3] Update" << std::endl;
            std::cout << "[4] View" << std::endl;
            std::cout << "[5] Delete" << std::endl;
            std::cout << "[6] Return to Previous Menu" << std::endl;
            std::cout << "Selection: ";
            cin >> userSelect;

            if (userSelect == '1') {
                //currentDatabase.new();
            } else if (userSelect == '2') {
                //currentDatabase.search();
            } else if (userSelect == '3') {
                //currentDatabase.update();
            } else if (userSelect == '4') {
                //currentDatabase.view();
            } else if (userSelect == '5') {
                //currentDatabase.delete();
            } else if (userSelect == '6') {
                option = 'q';
            } else {
                std::cout << "Error: invalid selection." << std::endl;
            }
        //}
    }
}