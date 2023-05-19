// Terminal user interface
#include "userInterface.hpp"
#include "userAccounts.hpp"

// Login Menu
void userInterface::loginMenu() {   
    cout << "WELCOME TO DOCUMENT DATA STORE" << endl;
    char option;
    char userSelect;
    while (option != 'q') {
        cout << "\nSelect from the following " << endl;
        cout << "[1] Login" << endl;
        cout << "[2] New Account" << endl;
        cout << "[3] Change Password" << endl;
        cout << "[4] Quit" << endl;
        cout << "Selection: ";
        cin >> userSelect;
        
        if (userSelect == '1') {
            currentUser.login();
            if(currentUser.getLogin())
                documentMenu();
        } else if (userSelect == '2') {
             currentUser.newAccount();
        } else if (userSelect == '3') {
            currentUser.changePassword();
        } else if (userSelect == '4') {
            option = 'q';
        } else {
            cout << "Error: invalid selection." << endl;
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
//             cout << "Account Management" << endl;
//             cout << "[1] Create New Account" << endl;
//             cout << "[2] Change Password" << endl;
//             cout << "[3] Delete Account" << endl;
//             cout << "[4] Return to Previous Menu" << endl;
//             cout << "Selection: ";
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
//                 cout << "Error: invalid selection." endl;
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
            cout << "\nDocument Management" << endl;
            cout << "[1] Create New CSV File" << endl;
            cout << "[2] Search CSV File" << endl;
            cout << "[3] Add Data to CSV File" << endl;
            cout << "[4] View CSV File" << endl;
            cout << "[5] Delete CSV File" << endl;
            cout << "[6] Update CSV File" << endl;
            cout << "[7] Logout" << endl;
            cout << "Selection: ";
            cin >> userSelect;

            if (userSelect == '1') {
                fileName = getCSVFileName();
                temp.create_csv_file(fileName);
            } else if (userSelect == '2') {
                fileName = getCSVFileName();
                string searchQuery = "";
                cout << "Input value to search in " << fileName << ": ";
                cin.ignore();
                getline(cin, searchQuery);
                temp.search_csv(fileName, searchQuery);
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
                fileName = getCSVFileName();
                temp.update_csv(fileName);
                // TODO: insert updating CSV file function call here
            } else if (userSelect == '7') {
                option = 'q';
            } else {
                cout << "Error: invalid selection." << endl;
            }
    }
}