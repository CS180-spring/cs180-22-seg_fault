#ifndef _DOCUMENT_HPP_
#define _DOCUMENT_HPP_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <cstdio>

using namespace std;

class Document {
    public:
        vector <string> tags;
  
        void SetName(string temp);
        string RetName();

        void SetLoc(string temp);
        string RetLoc();

        void SetType(string temp);
        string RetType();

        void AddTag(string tag);
        void DelTag(string tag);

        pair<string, string> search_csv(string filename, string search);
  
        int GetLastOpened();
  
        bool csv_file_exists(string filename);
        void create_csv_file(string);
        void write_to_csv(string, vector<vector<string> >);
        void write_csv_output(string);
        void view_csv(string);
        void update_csv(string);
        bool delete_csv(string);
        void deleteRowInCSV(const string& filename, int rowNumber);

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