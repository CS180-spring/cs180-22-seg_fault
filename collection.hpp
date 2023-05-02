#ifndef _COLLECTION_HPP_
#define _COLLECTION_HPP_
#include "document.hpp"
using namespace std;
class Collection {
    public:
        void SetName(std::string name);
        std::string RetName();

        void AddDoc(Document* temp);
        void DelDoc(string name);

        void AddTag(string);
        void DelTag(string);

        vector<Document*> returnDocuments();
        vector<std::string> returnTags();


        std::vector<Document*> findTaggedDocuments(std::string tag);


        int collectionSize();
        void displayContents();

        bool searchForDocumentByName(std::string);
        
    private:
        vector <Document*> documents;
        vector <string> tags;
        int collection_size;
        string name;


};
#endif //_COLLECTION_HPP_