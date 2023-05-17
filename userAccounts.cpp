#include "userAccounts.hpp"
#include "document.hpp"

userAccounts::userAccounts()
{
    loggedIn = false;
}

bool userAccounts::getLogin(int encryptionKey){
    if (loggedIn)
    {
        storedEncryptionKey = encryptionKey;
        userDatabase.decrypt(encryptionKey);
    }
    return loggedIn;
}

void userAccounts::logout()
{
    loggedIn = false;
    userDatabase.encrypt(storedEncryptionKey);
    userDatabase.delete_csv("Accounts-decrypted.csv");
}

void userAccounts::login() {
    Document temp;
    if(!temp.csv_file_exists("Accounts.csv"))
    {
        cout << "Error no accounts exist.\n";
        return;
    }
    string username, password;
    int inputEncryptionKey;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "Encryption Key: ";
    cin >> inputEncryptionKey;

    ifstream infile;
    infile.open("Accounts.csv");
    string line;
    while (getline(infile, line)) 
    {
        vector<string> row;
        stringstream ss(line);
        string field;
        
        while (getline(ss, field, ',')) 
        {
            row.push_back(field);
        }

        if (row[0] == "key" && stoi(row[1]) != inputEncryptionKey)
        {
            row.clear();
            infile.close();
            cout << "Invalid encryption key, returning to login menu.\n";
            return;
        }
        
        if (row[1] == username && row[3] == password)
        {
            cout << "Valid encryption key. Continuing search for \"" << username << "\"" << " account.\n";
            cout << "\"" << username << "\"" << " account was found. Logging in.\n";
            loggedIn = true;
            infile.close();
            return;
        }
    }

    if(!loggedIn)
    {
        cout << username << " account was NOT found.\n";
    }
    infile.close();

} 

//TODO mutliple accounts bug fix
void userAccounts::newAccount(int encryptionKey) {
    Document temp;
    if(!temp.csv_file_exists("Accounts.csv"))
    {
        temp.create_csv_file("Accounts.csv");
        vector<string> encrypt;
        encrypt.push_back("key");
        encrypt.push_back(to_string(encryptionKey) + ",");
        ofstream outfile;
        outfile.open("Accounts.csv", ios::app);
        for (int i = 0; i < encrypt.size(); i++) {
                outfile << encrypt[i];
                if (i != encrypt[i].size() - 1) {
                    outfile << ",";
                }
            }
            outfile << endl;
        outfile.close();
    }
    string username, password;
    cout << "New Username: ";
    cin >> username;
    cout << "New Password: ";
    cin >> password;
    vector<string> data;
    data.push_back("username");
    data.push_back(username);
    data.push_back("password");
    data.push_back(password);
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

// void userAccounts::changePassword() {
//     string username, password;
//     cout << "Change Password" << endl;
//     cout << "Username: ";
//     cin >> username;
//     cout << "New password: ";
//     cin >> password;

//     data = userDatabase.read_from_csv();
//     for (int i = 0; i < ; i+1) {
//         if (data[i][0] == username) {
//             cout << "Enter new password: ";
//             cin >> password;
//             data[i][1] = password;
//             userDatabase.write_to_cvs(data);
//         }
//     }
// }

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
