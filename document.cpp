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