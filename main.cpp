#include "collection.hpp"
#include "document.hpp"
#include "userInterface.hpp"
#include "userAccounts.hpp"

int main()
{
	srand(time(0));
	userInterface UI;
	UI.loginMenu();
	return 0;
}

// bool searchForCollection(std::string);
// Collection returnCollection(std::string);
// bool searchCollectionForDocumentByName(std::string, Collection);

// vector<Collection> tempCollectionVector; // temporary for testing
// Collection tempCollection; // temporary for testing

// bool searchForCollection(std::string collectionName)
// {
// 	for (int cnt = 0; cnt < tempCollectionVector.size(); cnt++)
// 	{
// 		if (tempCollectionVector[cnt].RetName() == collectionName)
// 		{
// 			return true;
// 		}
// 	}
// 	return false;
// }

// Collection returnCollection(std::string collectionName)
// {
// 	Collection collectionToReturn;
// 	for (int cnt = 0; cnt < tempCollectionVector.size(); cnt++)
// 	{
// 		if (tempCollectionVector[cnt].RetName() == collectionName)
// 		{
// 			collectionToReturn = tempCollectionVector[cnt];
// 			break;
// 		}
// 	}
// 	return collectionToReturn;
// }

// bool searchCollectionForDocumentByName(std::string documentName, Collection documentCollection)
// {
// 	std::vector<Document*> documentCollectionVector = documentCollection.returnDocuments();
// 	for (int cnt = 0; cnt < documentCollectionVector.size(); cnt++)
// 	{
// 		if (documentCollectionVector[cnt]->RetName() == documentName)
// 		{
// 			return true;
// 		}
// 	}
// 	return false;
// }