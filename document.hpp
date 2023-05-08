#ifndef _DOCUMENT_HPP_
#define _DOCUMENT_HPP_
#include <string>
#include <vector>
#include <algorithm>
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

        int GetLastOpened();

        void test(int time) 
        {
            this->last_opened = time;
        };

    private:
        string name;
        string location;
        string type;
        int last_opened;
};

std::vector<Document*> filter(std::vector<Document*> docs, std::string tag);

std::vector <Document*> Ascending(std::vector<Document*>);
std::vector <Document*> Descending(std::vector<Document*>);

std::vector <Document*> RecentlyModified (std::vector<Document*> input);
std::vector <Document*> OldestModified (std::vector<Document*> input);

#endif //_DOCUMENT_HPP_