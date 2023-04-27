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