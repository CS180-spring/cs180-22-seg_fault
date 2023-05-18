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
        for (int i = 0; i < row.size(); i++) {
            cout << row[i] << "\t";
        }
        cout << endl;
    }
    infile.close();
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

bool returnRowContents(string fileName, string searchQuery)
{
    string response = "";
    cout << "Print out contents of row where \"" << searchQuery << "\" was found in \"" << fileName << "\"? Enter (Y/N): ";
    transform(response.begin(), response.end(), response.begin(), ::tolower);
    getline(cin, response);
    while (response != "y" && response != "n")
    {
        cout << "\nError, \"" << response << "\" was invalid.\n";
        cout << "Print out contents of row where \"" << searchQuery << "\" was found in \"" << fileName << "\"? Enter (Y/N): ";
        getline(cin, response);
        transform(response.begin(), response.end(), response.begin(), ::tolower);
    }
    if (response == "y")
    {
        return true;
    }
    else
    {
        return false;
    }
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
              bool returnRowContentsOfQuery = returnRowContents(filename, search);
              if (returnRowContentsOfQuery)
              {
                for (i = 0; i < row.size(); i++)
                {
                    if (i + 1 == row.size())
                    {
                        cout << row[i];
                    }
                    else
                    {
                        cout << row[i] << ",";
                    }
                }
                cout << "\n";
              }
              return make_pair(to_string(y_key), to_string(i));
            }
        }
        cout << endl;
    }
    cout << "Error, document not found\n";
    infile.close();
    return make_pair(to_string(-1), to_string(-1));
}