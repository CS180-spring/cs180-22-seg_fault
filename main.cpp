#include <iostream>
#include "collection.cpp"
#include "document.cpp"
#include "database.cpp"
using namespace std;

int main()
{
	// adding 2 documents into tempCollection, then push tempCollection to database collectionVector
	Database test;
	
	Collection tempCollection;
	std::string tempTag = "work";
	tempCollection.AddTag(tempTag);
	tempTag = "school";
	tempCollection.AddTag(tempTag);
	tempCollection.SetName("COLLECTION");

	Document tempDoc1;
    tempDoc1.AddTag("School");
    tempDoc1.AddTag("Work");
	tempDoc1.SetName("firstDoc");
	tempDoc1.SetLoc("main");
	tempDoc1.SetType("txt");
	tempCollection.AddDoc(&tempDoc1);
	Document tempDoc2;
    tempDoc2.AddTag("School");
	tempDoc2.SetName("secondDocument");
	tempDoc2.SetLoc("folder");
	tempDoc2.SetType("type");
	tempCollection.AddDoc(&tempDoc2);
     string input;
     cout << "Input tag to search: \n";
     cin >> input;
    vector<Document*> temp = tempCollection.findTaggedDocuments(input);
    cout << "Searching for documents with " << input << " tag: \n";
    for(int i = 0; i < temp.size(); ++i){
        cout << temp[i]->RetName() << endl;
    }
    cin.clear();
    cin.ignore(10000, '\n');

	std::string collectionName = "";
	std::cout << "Input collection name: ";
	getline(std::cin, collectionName);
	if (test.searchForCollection(collectionName))
	{
		test.printCollections();
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
		cout << collectionName << " collection was NOT found.\n";
	}
	return 0;
}