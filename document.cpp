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

std::vector<Document*> filter(std::vector<Document*> docs, std::string tag)
{
    std::vector<Document*> filteredDocs;
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
    
// std::vector <Document*> Ascending(std::vector<Document*> input) {
//   std::vector<Document*> temp = input;
//   std::sort(temp.begin(), temp.end(), [](Document* &e1, Document* &e2){ return e1->RetName()>e2->RetName(); });
//   return temp;
// }

// std::vector <Document*> Descending(std::vector<Document*> input) {
//   std::vector<Document*> temp = input;
//   std::sort(temp.begin(), temp.end(), [](Document* &e1, Document* &e2){ return e1->RetName()<e2->RetName(); });
//   return temp;
// }