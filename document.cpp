#include "document.hpp"

void Document::SetName(string temp) {
    name = temp;
}
string Document::RetName() {
    return name;
}

void Document::SetLoc(string temp) {
    location = temp;
}
string Document::RetLoc() {
    return location;
}

void Document::SetType(string temp) {
    type = temp;
}
string Document::RetType() {
    return type;
}

void Document::AddTag(string tag) {
    tags.push_back(tag);
}

void Document::DelTag(string tag) {
    if (!tags.size()) {
        return;
    }

    for (int i = 0; i < tags.size(); i++) {
        if (tags[i] == tag) {
            tags.erase(tags.begin()+i);
        }
    }
}

bool Document::csv_file_exists(string filename) {
    ifstream infile(filename);
    return infile.good();
}

void Document::create_csv_file(string filename) {
    // filename += ".csv";
    if(csv_file_exists(filename)){
        cout << "Error: " << filename << " already exists.\n";
        return;
    }
    ofstream outfile;
    outfile.open(filename);
    outfile.close();
}

void Document::write_to_csv(string filename, vector<vector<string> > data) {
    ofstream outfile;
    outfile.open(filename, ios::app);
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            outfile << data[i][j];
            if (j != data[i].size() - 1) {
                outfile << ",";
            }
        }
        outfile << endl;
    }
    outfile.close();
}

void Document::write_csv_output(string filename) {
    if(!csv_file_exists(filename)){
        cout << "ERROR: File does not exist" << endl;
        return;
    }

    vector<vector<string> > data;

    while (true) {
        string input;
        vector<string> row;
        cout << "Enter data for a new row (or type 'done' to finish): ";
        getline(cin, input);
        if (input == "done")
            break;
        stringstream ss(input);
        string field;
        while (getline(ss, field, ',')) {
            row.push_back(field);
        }
        data.push_back(row);
    }

    write_to_csv(filename, data);
    cout << "Data written to " << filename << endl;
}

void Document::view_csv(string filename) {
    if(!csv_file_exists(filename)){
        cout << "ERROR: File does not exist" << endl;
        return;
    }

    if (filename == "Accounts.csv")
    {
        cout << "Access denied.\n";
        return;
    }
    int count = 0;
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
        if (count != 0) {
            cout << count << ": ";
        }
        for (int i = 0; i < row.size(); i++) {
            cout << row[i] << "\t";
        }
        cout << endl;
        count++;
    }
    infile.close();
}

void Document::update_csv(string filename){
    int num = 0;
    int count = -1;
    bool flag = 0;
    string insert = "";
    string input;
    if(!csv_file_exists(filename)){
        cout << "ERROR: File does not exist" << endl;
        return;
    }

    if (filename == "Accounts.csv")
    {
        cout << "Access denied.\n";
        return;
    }

    view_csv(filename);
    cout << "Which line would you like to edit? ";
    cin >> num;
    cout << "Would you like to insert or replace? 0 to replace, 1 to insert: ";
    do {
        cin >> insert;
        if (!(insert == "0" || insert == "1")) {
            cout << "Error, invalid input. Please enter 0 to replace or 1 to insert: ";
        }
    } while (!(insert == "0" || insert == "1"));
    if (insert == "0") {
        flag = 0;
    }
    else {
        flag = 1;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter data for a new row (Just press enter in replace mode to delete the line): ";
    getline(cin, input);
    vector<string> temp;
    stringstream ss(input);
    string field;
    while (getline(ss, field, ',')) {
        temp.push_back(field);
    }

    vector<vector<string> > data;
    string line;
    ifstream infile;
    infile.open(filename);
    
    while (getline(infile, line)) {
        vector<string> row;
        stringstream ss(line);
        string field;
        count++;
        while (getline(ss, field, ',')) {
            row.push_back(field);
        }
        if (count == num) {
            if (temp.size()) {
                data.push_back(temp);
                if (flag) {
                    data.push_back(row);
                }
                row.clear();
            }
        }
        else {
            data.push_back(row);
        }
    }

    infile.close();

    if (num < 1 || num >= data.size()) {
        cout << "Error, invalid line selected.\n";
        return;
    }

    std::ofstream ofs;
    ofs.open(filename, ofstream::out | ofstream::trunc);
    ofs.close();

    write_to_csv(filename, data);
    cout << "Data written to " << filename << endl;
    return;
}

bool Document::delete_csv(string filename) {
    if(!csv_file_exists(filename)){
        cout << "ERROR: File does not exist" << endl;
        return true;
    }
    if (remove(filename.c_str()) != 0) 
    {
        cout << "Error deleting file: " << filename << endl;
        return false;
    } 
    else 
    {
        cout << "File successfully deleted: " << filename << endl;
        return true;
    }
}

vector<Document*> filter(vector<Document*> docs, string tag)
{
    vector<Document*> filteredDocs;
    Document* currDoc;
    for(int i = 0; i < docs.size(); ++i)
    {
        currDoc = docs.at(i);
        for(int j = 0; j < currDoc->tags.size(); ++j)
        {
            if(currDoc->tags.at(j) == tag)
            {
                filteredDocs.push_back(currDoc);
                break;
            }
        }
    }
    return filteredDocs;
  
}

 vector <Document*> Ascending(vector<Document*> input) {
   vector<Document*> temp = input;
   sort(temp.begin(), temp.end(), [](Document* &e1, Document* &e2){ return e1->RetName()>e2->RetName(); });
   return temp;
 }


vector <Document*> Descending(vector<Document*> input) {
  vector<Document*> temp = input;
  sort(temp.begin(), temp.end(), [](Document* &e1, Document* &e2){ return e1->RetName()<e2->RetName(); });
  return temp;
}

int Document::GetLastOpened() { return this->last_opened; }

vector <Document*> RecentlyModified (vector<Document*> input)
{
    vector<Document*> temp = input;
    sort(temp.begin(), temp.end(), [](Document* &e1, Document* &e2){ return e1->GetLastOpened()<e2->GetLastOpened(); });
    return temp;
}

vector <Document*> OldestModified (vector<Document*> input)
{
    vector<Document*> temp = input;
    sort(temp.begin(), temp.end(), [](Document* &e1, Document* &e2){ return e1->GetLastOpened()>e2->GetLastOpened(); });
    return temp;
}
  
pair<string, string> Document::search_csv(string filename, string search) {
    if(!csv_file_exists(filename)){
        cout << "ERROR: File does not exist" << endl;
        return make_pair(to_string(-1), to_string(-1));
    }
    int y_key = 0;
    ifstream infile;
    infile.open(filename);
    string line;
    while (getline(infile, line)) {
        y_key++;
        vector<string> row;
        stringstream ss(line);
        string field;
        while (getline(ss, field, ',')) {
            row.push_back(field);
        }
        for (int i = 0; i < row.size(); i++) {
            if (row[i] == search) {
              infile.close();
              cout << "Document found\n";
              return make_pair(to_string(y_key), to_string(i));
            }
        }
        cout << endl;
    }
    cout << "Error, document not found\n";
    infile.close();
    return make_pair(to_string(-1), to_string(-1));
}
  