#ifndef _DOCUMENT_HPP_
#define _DOCUMENT_HPP_
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
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

        bool csv_file_exists(string filename);
        void create_csv_file(string);
        void write_to_csv(string, vector<vector<string> >);
        void write_csv_output(string);
        void view_csv(string);
        bool delete_csv(string);

    private:
        string name;
        string location;
        string type;
        int last_opened;
};

std::vector<Document*> filter(std::vector<Document*> docs, std::string tag);

// std::vector <Document*> Ascending(std::vector<Document*>);
// std::vector <Document*> Descending(std::vector<Document*>);

#endif //_DOCUMENT_HPP_