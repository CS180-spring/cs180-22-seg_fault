#include "userAccounts.hpp"
#include "document.hpp"

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
                cout << username << " and " << password << " account found\n";
                loggedIn = true;
            }
    }

    if(!loggedIn)
    {
        cout << username << " and " << password << " account was NOT found\n";
    }
    infile.close();

} 

//TODO mutliple accounts bug fix
void userAccounts::newAccount() {
    Document temp;
    if(!temp.csv_file_exists("Accounts.csv"))
        temp.create_csv_file("Accounts.csv");
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

void userAccounts::deleteAccount() {
    Document temp;
    if(!temp.csv_file_exists("Accounts.csv")){
        cout << "Error no accounts exist.\n";
        return;
    }

    string username;
    fstream accounts;
    string line;
    vector<string> lines;
    bool deleted = false;
    cout << "Deleting User Account" << endl;
    cout << "Username to delete: ";
    cin >> username;
    accounts.open("Accounts.csv");
    if (!accounts.is_open()) {
        cout << "Error opening file.\n";
        return;
    }
    while (getline(accounts, line)) {
        vector<string> row;
        stringstream ss(line);
        string field;
        while (getline(ss, field, ',')) {
            row.push_back(field);
        }
        if (row[1] == username) {
            cout << "Deleting " << username << ".\n";
            row.clear();
            deleted = true;
        }
        else {
            string keep_row;
            for (int i = 0; i < row.size(); ++i) {
                keep_row += row.at(i);
                keep_row += ',';
            }
            lines.push_back(keep_row);
        }
    }
    if (deleted) {
        ofstream fout;
        fout.open("Accounts.csv");
        if (!fout.is_open()) {
            cout << "Error opening file\n";
            return;
        }
        for (int i = 0; i < lines.size(); i++) {
            fout << lines.at(i) << endl;
        }
        fout.close();
    }
    else {
        cout << "Error deleting " << username << "'s account.\n";
    }
    return;
}
