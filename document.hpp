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
#include <limits>

using namespace std;

class Document {
    public:
        //THESE FUNCTIONS ARE ALL DEPRECATED FROM PREVIOUS VERSIONS OF OUR PROGRAMS
        vector<string> tags;
  
        void SetName(string);
        string RetName();

        void SetLoc(string);
        string RetLoc();

        void SetType(string);
        string RetType();

        void AddTag(string);
        void DelTag(string);

        
    
        pair<string, string> search_csv(string, string);
    
        int GetLastOpened();
  
        bool csv_file_exists(string);
        void create_csv_file(string, string);
        void write_to_csv(string, vector<vector<string>>);
        void write_csv_output(string);
        void view_csv(string);
        void update_csv(string);
        bool delete_csv(string);
        void deleteRowInCSV(const string& filename, int rowNumber);

        void encrypt(int);
        void decrypt(int);

    private:
        string name;
        string location;
        string type;
        int last_opened;
};

vector<Document*> filter(vector<Document*>, string);

vector<Document*> Ascending(vector<Document*>);
vector<Document*> Descending(vector<Document*>);

vector<Document*> RecentlyModified (vector<Document*>);
vector<Document*> OldestModified (vector<Document*>);

#endif //_DOCUMENT_HPP_
