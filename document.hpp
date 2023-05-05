#ifndef _DOCUMENT_HPP_
#define _DOCUMENT_HPP_
#include <string>
#include <vector>
#include <fstream>
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

        vector <string> tags;

        void create_csv_file();
        void write_to_csv(string filename, vector<vector<string> > data);
        void write_csv_output();
        void view_csv();
        bool delete_csv();

    private:
        string name;
        string location;
        string type;
        int last_opened;
};
#endif //_DOCUMENT_HPP_