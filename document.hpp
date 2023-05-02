#ifndef _DOCUMENT_HPP_
#define _DOCUMENT_HPP_
#include <string>
#include <vector>

class Document {
    public:

        void SetName(std::string temp);
        std::string RetName();

        void SetLoc(std::string temp);
        std::string RetLoc();

        void SetType(std::string temp);
        std::string RetType();

        void AddTag(std::string tag);
        void DelTag(std::string tag);

        std::vector <std::string> tags;

    private:
        std::string name;
        std::string location;
        std::string type;
};
#endif //_DOCUMENT_HPP_