#ifndef _COLLECTION_HPP_
#define _COLLECTION_HPP_

#include "document.hpp"

//THIS CODE IS ALL DEPRACATED, NOT BEING USED WITH THE CURRENT SYSTEM
//ONLY STILL HERE FOR BACKWARDS COMPATIBILITY

class Collection {
    public:
        void SetName(string);
        string RetName();

        void AddDoc(Document*);
        void DelDoc(string);

        void AddTag(string);
        void DelTag(string);

        vector<Document*> returnDocuments();
        vector<string> returnTags();


        vector<Document*> findTaggedDocuments(string);


        int collectionSize();
        void displayContents();

    private:
        vector <Document*> documents;
        vector <string> tags;
        int collection_size;
        string name;


};
#endif //_COLLECTION_HPP_
