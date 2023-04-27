#ifndef _DATABASE_HPP_
#define _DATABASE_HPP_

#include "collection.hpp"
#include "document.hpp"

class Database
{
    public:
        void addCollection(Collection*);
        void removeCollection(std::string);
        bool searchForCollection(std::string);
        Collection* returnCollection(std::string);
    private:
        std::vector<Collection*> collectionVector;
};

#endif