#ifndef _DOCUMENT_HPP_
#define _DOCUMENT_HPP_
#include <string>
#include <vector>
using namespace std;

class Document {
    public:

        void SetName(string temp);
        string RetName();

        void SetLoc(string temp);
        string RetLoc();

        void SetType(string temp);
        string RetType();

        void AddTag(string tag);
        void DelTag(string tag);

        std::vector<Document*> filter(std::vector<Document*> docs, std::string tag)

        vector <string> tags;

    private:
        string name;
        string location;
        string type;
        int last_opened;
};


#endif //_DOCUMENT_HPP_