// Terminal user interface
#include "userInterface.hpp"
#include "userAccounts.hpp"
#include "logging.hpp"

//THIS CLASS IS ONLY RESPONSIBLE FOR USER INTERFACE. IT WITH THE USERACCOUNT AND DOCUMENT CLASSES
//IT IS ONLY RESPONSIBLE FOR PRINTING MESSAGES AND CALLING OTHER FUNCTIONS

userInterface::userInterface()
{
    encryptionKey = 1 + (rand() % 100); // generate random encryption/decryption key from 1-100
}

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
        cout << "[4] Delete Account" << endl;
        cout << "[5] Quit" << endl;
        cout << "Selection: ";
        cin >> userSelect;
        
        if (userSelect == '1') {
            currentUser.login();
            if(currentUser.getLogin(encryptionKey))
                documentMenu();
        } else if (userSelect == '2') {
             currentUser.newAccount(encryptionKey);
        } else if (userSelect == '3') {
            currentUser.changePassword();
        } else if (userSelect == '4') {
            currentUser.deleteAccount();
        } else if (userSelect == '5') {
            option = 'q';
        } else {
            cout << "Error: invalid selection." << endl;
        }
    }
}

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
            cout << "[6] Edit CSV File" << endl;
            cout << "[7] Logout" << endl;
            cout << "Selection: ";
            cin >> userSelect;

            if (userSelect == '1') {
                fileName = getCSVFileName();
                temp.create_csv_file(fileName,currentUser.getUsername());
                userLogs.newLog("New CSV file created: " + fileName);
            } else if (userSelect == '2') {
                fileName = getCSVFileName();
                if(!currentUser.check_user(fileName)){
                    cout << "Error: You do not have access to this file!\n";
                    continue;
                }

                string searchQuery = "";
                cout << "Input value to search in " << fileName << ": ";
                cin.ignore();
                getline(cin, searchQuery);
                pair<string, string> foundSearchQueryCoordinates;
                foundSearchQueryCoordinates = temp.search_csv(fileName, searchQuery);
                if (foundSearchQueryCoordinates.first != "-1" && foundSearchQueryCoordinates.second != "-1")
                {
                    cout << "\n" << searchQuery << " was found at " << "[" << foundSearchQueryCoordinates.first << ", " << foundSearchQueryCoordinates.second << "] in " + fileName << ".\n";
                }
            } else if (userSelect == '3') {
                fileName = getCSVFileName();
                if(!currentUser.check_user(fileName)){
                    cout << "Error: You do not have access to this file!\n";
                    continue;
                }
                temp.write_csv_output(fileName);
                userLogs.newLog("CSV file updated: " + fileName);
            } else if (userSelect == '4') {
                fileName = getCSVFileName();
                if(!currentUser.check_user(fileName)){
                    cout << "Error: You do not have access to this file!\n";
                    continue;
                }
                temp.view_csv(fileName);
                userLogs.newLog("CSV file viewed: " + fileName);
            } else if (userSelect == '5') {
                fileName = getCSVFileName();
                if(!currentUser.check_user(fileName)){
                    cout << "Error: You do not have access to this file!\n";
                    continue;
                }
                temp.delete_csv(fileName);
                userLogs.newLog("CSV file deleted: " + fileName);
            } else if (userSelect == '6') {
                fileName = getCSVFileName();
                if(!currentUser.check_user(fileName)){
                    cout << "Error: You do not have access to this file!\n";
                    continue;
                }
                temp.update_csv(fileName);
            } else if (userSelect == '7') {
                option = 'q';
                currentUser.logout();
            } else {
                cout << "Error: invalid selection." << endl;
            }
    }
}
