#ifndef _COLLECTION_HPP_
#define _COLLECTION_HPP_
#include "document.hpp"
class Collection {

    public:
        void SetName(std::string name);
        std::string RetName();

        void AddDoc(Document* temp);
        void DelDoc(std::string name);

        void AddTag(std::string);
        void DelTag(std::string);

        std::vector<Document*> returnDocuments();
        std::vector<std::string> returnTags();


        std::vector<Document*> findTaggedDocuments(std::string tag);


        int collectionSize();
        void displayContents();

    private:
        std::vector <Document*> documents;
        std::vector <std::string> tags;
        std::string name;


};
#endif //_COLLECTION_HPP_