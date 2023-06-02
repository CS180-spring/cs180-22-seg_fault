#include "collection.cpp"
#include "document.cpp"
#include "userInterface.cpp"
#include "userAccounts.cpp"
#include "logging.cpp"

int main()
{
	userInterface UI;
	UI.loginMenu();
	//logging datastoreLogs("temp.txt");
	//datastoreLogs.newLog("hello");

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