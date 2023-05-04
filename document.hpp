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

        vector <string> tags;

    private:
        string name;
        string location;
        string type;
        int last_opened;
};

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
#endif //_DOCUMENT_HPP_