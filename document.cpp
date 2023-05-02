#include "document.hpp"

void Document::SetName(std::string temp) {
    name = temp;
}
std::string Document::RetName() {
    return name;
}

void Document::SetLoc(std::string temp) {
    location = temp;
}
std::string Document::RetLoc() {
    return location;
}

void Document::SetType(std::string temp) {
    type = temp;
}
std::string Document::RetType() {
    return type;
}

void Document::AddTag(std::string tag) {
    tags.push_back(tag);
}

void Document::DelTag(std::string tag) {
    if (!tags.size()) {
        return;
    }

    for (int i = 0; i < tags.size(); i++) {
        if (tags[i] == tag) {
            tags.erase(tags.begin()+i);
        }
    }
}