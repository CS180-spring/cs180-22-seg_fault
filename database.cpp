#include <iostream>
#include "database.hpp"

void Database::addCollection(Collection* newCollection)
{
    collectionVector.push_back(newCollection);

}

void Database::removeCollection(std::string collectionName)
{
    for (int cnt = 0; cnt < collectionVector.size(); cnt++)
    {
        if (collectionVector[cnt]->RetName() == collectionName)
        {
            collectionVector.erase(collectionVector.begin() + cnt);
            return;
        }
    }
}

bool Database::searchForCollection(std::string collectionName)
{
	for (int cnt = 0; cnt < collectionVector.size(); cnt++)
	{
		if (collectionVector[cnt]->RetName() == collectionName)
		{
			return true;
		}
	}
	return false;
}

Collection* Database::returnCollection(std::string collectionName)
{
	Collection* collectionToReturn;
	for (int cnt = 0; cnt < collectionVector.size(); cnt++)
	{
		if (collectionVector[cnt]->RetName() == collectionName)
		{
			collectionToReturn = collectionVector[cnt];
			break;
		}
	}
	return collectionToReturn;
}

void Database::printCollections()
{
    std::cout << "\nPrinting collections in the database.\n";
    for (int i = 0; i < collectionVector.size(); i++)
    {
        std::string tags = "{Tags: ";
        std::vector<std::string> collectionTags = collectionVector[i]->returnTags();
        for (int j = 0; j < collectionTags.size(); j++)
        {
            if (j + 1 == collectionTags.size())
            {
                tags += collectionTags[j] + "}\n";
            }
            else
            {
                tags += collectionTags[j] + ", ";
            }
        }
        std::cout << "Collection " << i + 1 << ": {Name: " << collectionVector[i]->RetName() << "}, " + tags;
    }
}