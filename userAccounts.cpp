#include "userAccounts.hpp"
#include "document.hpp"

userAccounts::userAccounts()
{
    loggedIn = false;
}
bool userAccounts::getLogin(){
    return loggedIn;
}

void userAccounts::login() {
    Document temp;
    if(!temp.csv_file_exists("Accounts.csv")){
        cout << "Error no accounts exist.\n";
        return;
    }
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream infile;
    infile.open("Accounts.csv");
    string line;
    while (getline(infile, line)) {
        vector<string> row;
        stringstream ss(line);
        string field;
        while (getline(ss, field, ',')) {
            row.push_back(field);
        }
            if (row[1] == username && row[3] == password)
            {
                cout << "Welcome back" << username << endl;
                loggedIn = true;
            }
    }

    if(!loggedIn)
    {
        // cout << username << " and " << password << " account was NOT found\n";
        cout << "Username or password incorrect\n";
    }
    infile.close();

} 

//TODO mutliple accounts bug fix
void userAccounts::newAccount() {
    Document temp;
    if(!temp.csv_file_exists("Accounts.csv"))
        temp.create_csv_file("Accounts.csv");
    string username, password, userInput;
    cout << "New Username: ";
    cin >> username;
    cout << "New Password: ";
    cin >> password;
    cout << "Security Question: What is the name of your first pet?\n";
    cin >> userInput;
    vector<string> data;
    data.push_back("username");
    data.push_back(username);
    data.push_back("password");
    data.push_back(password);
    data.push_back("security");
    data.push_back(userInput);

    ofstream outfile;
    outfile.open("Accounts.csv", ios::app);
    for (int i = 0; i < data.size(); i++) {
            outfile << data[i];
            if (i != data[i].size() - 1) {
                outfile << ",";
            }
        }
        outfile << endl;
    outfile.close();

    cout << "New account created.\n";
}

 void userAccounts::changePassword() {
    Document temp;
    bool accFound = false;
    string username, userInput, newPassword;
    cout << "Change Password" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Security Question: What is the name of your first pet?\n";
    cout<< "Answer: ";
    cin >> userInput;

    ifstream infile;
    infile.open("Accounts.csv");
    string line;
    int counter = 0;
    while (getline(infile, line)) {
        vector<string> row;
        stringstream ss(line);
        string field;
        while (getline(ss, field, ',')) {
            row.push_back(field);
        }
            if (row[1] == username && row[5] == userInput)
            {
                cout << username << " account found\n";
                accFound = true;
                break;
            }
            ++counter;
    }

    if(!accFound)
    {
        cout << "Username or security question incorrect\n";
        return;
    }
    infile.close();

    cout << "New Password: ";
    cin >> newPassword;
    vector<string> data;
    data.push_back("username");
    data.push_back(username);
    data.push_back("password");
    data.push_back(newPassword);
    data.push_back("security");
    data.push_back(userInput);

    ofstream outfile;
    outfile.open("Accounts.csv", ios::app);
    for (int i = 0; i < data.size(); i++) {
            outfile << data[i];
            outfile << ",";
        }
        outfile << endl;
    outfile.close();

    temp.deleteRowInCSV("Accounts.csv", counter);
    cout << "Password changed.\n";
}

// void userAccounts::deleteAccount() {
//     string username;
//     cout << "Delete User Account" << endl;
//     cout << "Username to delete: ";
//     cin >> username;

//     data = userDatabase.read_from_csv();
//     for (int i = 0; i < ; i+1) {
//         if (data[i][0] == username) {
//             data[i] = "";
//             data[0] = "";
//         }
//         userDatabase.write_to_cvs(data);
//     }
// }
