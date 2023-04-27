#include <iostream>
#include "collection.cpp"
#include "document.cpp"
#include "database.cpp"

bool searchCollectionForDocumentByName(std::string, Collection);

int main()
{
	// adding 2 documents into tempCollection, then push tempCollection to database collectionVector
	Database test;
	Collection tempCollection;
	tempCollection.SetName("COLLECTION");
	Document tempDoc1;
	tempDoc1.SetName("firstDoc");
	tempDoc1.SetLoc("main");
	tempDoc1.SetType("txt");
	tempCollection.AddDoc(&tempDoc1);
	Document tempDoc2;
	tempDoc2.SetName("secondDocument");
	tempDoc2.SetLoc("folder");
	tempDoc2.SetType("type");
	tempCollection.AddDoc(&tempDoc2);
	test.addCollection(&tempCollection);
	//

	std::string collectionName = "";
	std::cout << "Input collection name: ";
	getline(std::cin, collectionName);
	if (test.searchForCollection(collectionName))
	{
		Collection* foundCollection = test.returnCollection(collectionName);
		std::cout << foundCollection->RetName() << " collection found.\n";
		std::string documentName = "";
		std::cout << "\nInput document name: ";
		getline(std::cin, documentName);
		if (foundCollection->searchForDocumentByName(documentName))
		{
			std::cout << documentName << " document was found in the " << foundCollection->RetName() << " collection.\n";
		}
		else
		{
			std::cout << documentName << " document was NOT found in the " << foundCollection->RetName() << " collection.\n";
		}
	}
	else
	{
		std::cout << collectionName << " collection was NOT found.\n";
	}
	return 0;
}