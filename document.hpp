#ifndef _DOCUMENT_HPP_
#define _DOCUMENT_HPP_
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <utility>
#include <iostream>
#include <sstream>
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

        pair<string, string> search_csv(string filename, string search);

        vector <string> tags;

    private:
        string name;
        string location;
        string type;
        int last_opened;
};

std::vector <Document*> filter(std::vector<Document*> docs, std::string tag);
std::vector <Document*> Ascending(std::vector<Document*>);
std::vector <Document*> Descending(std::vector<Document*>);

#endif //_DOCUMENT_HPP_