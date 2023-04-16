#ifndef _DOCUMENT_HPP_
#define _DOCUMENT_HPP_
#include <string>
#include <vector>

class Document {
    public:

        void SetName(std::string temp) {
            name = temp;
        }
        std::string RetName() {
            return name;
        }

        void SetLoc(std::string temp) {
            location = temp;
        }
        std::string RetLoc() {
            return location;
        }

        void SetType(std::string temp) {
            type = temp;
        }
        std::string RetType() {
            return type;
        }

        void AddTag(std::string tag) {
            tags.push_back(tag);
        }

        void DelTag(std::string tag) {
            if (!tags.size()) {
                return;
            }

            for (int i = 0; i < tags.size(); i++) {
                if (tags[i] == tag) {
                    tags.erase(tags.begin()+i);
                }
            }
        }

        std::vector <std::string> tags;

    private:
        std::string name;
        std::string location;
        std::string type;
};
#endif //_DOCUMENT_HPP_