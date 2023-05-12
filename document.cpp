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
    
std::vector <Document*> Ascending(std::vector<Document*> input) {
  std::vector<Document*> temp = input;
  std::sort(temp.begin(), temp.end(), [](Document* &e1, Document* &e2){ return e1->RetName()>e2->RetName(); });
  return temp;
}

std::vector <Document*> Descending(std::vector<Document*> input) {
  std::vector<Document*> temp = input;
  std::sort(temp.begin(), temp.end(), [](Document* &e1, Document* &e2){ return e1->RetName()<e2->RetName(); });
  return temp;
}

pair<string, string> Document::search_csv(string filename, string search) {
    /*if(!csv_file_exists(filename)){
        std::cout << "ERROR: File does not exist" << endl;
        return make_pair(to_string(-1), to_string(-1));
    }*/
    int y_key = 0;
    ifstream infile;
    infile.open(filename);
    string line;
    while (getline(infile, line)) {
        y_key++;
        vector<string> row;
        stringstream ss(line);
        string field;
        while (std::getline(ss, field, ',')) {
            row.push_back(field);
        }
        for (int i = 0; i < row.size(); i++) {
            if (row[i] == search) {
              infile.close();
              std::cout << "Document found\n";
              return make_pair(to_string(y_key), to_string(i));
            }
        }
        std::cout << endl;
    }
    std::cout << "Error, document not found\n";
    infile.close();
    return make_pair(to_string(-1), to_string(-1));
}