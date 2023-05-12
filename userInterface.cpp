// Terminal user interface
#include "userInterface.hpp"
#include "userAccounts.hpp"
#include "iostream"

// Login Menu
void userInterface::loginMenu() {   
    cout << "WELCOME TO DOCUMENT DATA STORE" << endl;
    char option;
    char userSelect;
    while (option != 'q') {
        std::cout << "\nSelect from the following " << std::endl;
        std::cout << "[1] Login" << std::endl;
        std::cout << "[2] New Account" << std::endl;
        std::cout << "[3] Quit" << std::endl;
        std::cout << "Selection: ";
        cin >> userSelect;
        
        if (userSelect == '1') {
            currentUser.login();
            if(currentUser.getLogin())
                documentMenu();
        } else if (userSelect == '2') {
             currentUser.newAccount();
        } else if (userSelect == '3') {
            option = 'q';
        } else {
            std::cout << "Error: invalid selection." << std::endl;
        }
    }
}
    
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

string getCSVFileName()
{
    string input = "";
    cout << "Input CSV file name: ";
    cin >> input;
    input += ".csv";
    return input;
}

// Document Menu
void userInterface::documentMenu(){
    char option;
    char userSelect;
    Document temp;
    string fileName;

    while(option != 'q') 
    {
            std::cout << "\nDocument Management" << std::endl;
            std::cout << "[1] Create New CSV File" << std::endl;
            std::cout << "[2] Search CSV File" << std::endl;
            std::cout << "[3] Update CSV File" << std::endl;
            std::cout << "[4] View CSV File" << std::endl;
            std::cout << "[5] Delete CSV File" << std::endl;
            std::cout << "[6] Logout" << std::endl;
            std::cout << "Selection: ";
            cin >> userSelect;

            if (userSelect == '1') {
                fileName = getCSVFileName();
                temp.create_csv_file(fileName);
            } else if (userSelect == '2') {
                fileName = getCSVFileName();
                // TODO: insert search CSV file function call here
            } else if (userSelect == '3') {
                fileName = getCSVFileName();
                temp.write_csv_output(fileName);
            } else if (userSelect == '4') {
                fileName = getCSVFileName();
                temp.view_csv(fileName);
            } else if (userSelect == '5') {
                fileName = getCSVFileName();
                temp.delete_csv(fileName);
            } else if (userSelect == '6') {
                option = 'q';
            } else {
                std::cout << "Error: invalid selection." << endl;
            }
    }
}