#include "userAccounts.hpp"
#include "document.hpp"

userAccounts::userAccounts()
{
    loggedIn = false;
}

string userAccounts::getUsername()
{
    return userName;
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
        cout << "\nError no accounts exist.\n";
        return;
    }
    cin.clear();
    cin.ignore(99999, '\n');
    string username, password;
    int inputEncryptionKey;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "Encryption Key: ";
    cin >> inputEncryptionKey;
    if (cin.fail()) // if it's not an int, then invalid key
    { 
        cout << "\nInvalid encryption key, returning to login menu.\n";
        cin.clear();
        cin.ignore(99999, '\n');
        return;
    }

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
            cout << "\nInvalid encryption key, returning to login menu.\n";
            cin.clear();
            cin.ignore(99999, '\n');
            userName = username;
            return;
        }
        
        if (row[1] == username && row[3] == password)
        {
            cout << "\nValid encryption key. Continuing search for \"" << username << "\"" << " account.\n";
            cout << "\"" << username << "\"" << " account was found. Logging in.\n";
            loggedIn = true;
            infile.close();
            userName = username;
            return;
        }
            if (row[1] == username && row[3] == password)
            {
                cout << "Welcome back " << username << endl;
                loggedIn = true;
                userName = username;
            }
    }

    if(!loggedIn)
    {
        cout << username << " account was NOT found.\n";
        // cout << username << " and " << password << " account was NOT found\n";
        cout << "Username or password incorrect\n";
    }
    infile.close();

} 

//TODO mutliple accounts bug fix
void userAccounts::newAccount(int encryptionKey) {
    Document temp;
    if(!temp.csv_file_exists("Accounts.csv"))
    {
        temp.create_csv_file("Accounts.csv", "ADMIN");
        vector<string> encrypt;
        encrypt.push_back("key");
        encrypt.push_back(to_string(encryptionKey));
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

    cout << "\n" << username << " account was created.\n";
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

void userAccounts::deleteAccount() {
    Document temp;
    if(!temp.csv_file_exists("Accounts.csv")){
        cout << "Error no accounts exist.\n";
        return;
    }

    string username, password, security;
    fstream accounts;
    string line;
    vector<string> lines;
    bool deleted = false;
    cout << "Deleting User Account" << endl;
    cout << "Username to delete: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "Security Question: What is the name of your first pet: ";
    cin >> security;
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
        if (row[1] == username && row[3] == password && row[5] == security) {
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

bool userAccounts::check_user(string filename)
{
    ifstream infile;
    infile.open(filename);
    string line;
    while (getline(infile, line)) {
        vector<string> row;
        stringstream ss(line);
        string field;
        while (getline(ss, field, ',')) {
            row.push_back(field);
        }
            if (row[0] == "user" && row[1] == userName)
            {
                infile.close();
                return true;
            }
    }
    infile.close();
    return false;
}