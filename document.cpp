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

std::vector<Document*> Document::filter(std::vector<Document*> docs, std::string tag)
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