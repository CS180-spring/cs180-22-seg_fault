#include <iostream>
#include "collection.cpp"
#include "document.cpp"
using namespace std;

bool searchForCollection(std::string);
Collection returnCollection(std::string);
bool searchCollectionForDocumentByName(std::string, Collection);

vector<Collection> tempCollectionVector; // temporary for testing
Collection tempCollection; // temporary for testing

int main()
{
	// adding 2 documents into tempCollection, then pushing the collection to tempCollectionVector

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
	tempCollectionVector.push_back(tempCollection);
	 // temporary for testing
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
	string collectionName = "";
	cout << "Input collection name: ";
	getline(cin, collectionName);
	if (searchForCollection(collectionName))
	{
		Collection foundCollection = returnCollection(collectionName);
		cout << foundCollection.RetName() << " collection found.\n";
        cout << "Contents in Collection: \n";
        tempCollection.displayContents(); //displays content of collection
		string documentName = "";
		cout << "\nInput document name: ";
		getline(std::cin, documentName);
		if (searchCollectionForDocumentByName(documentName, foundCollection))
		{
			cout << documentName << " document was found in the " << foundCollection.RetName() << " collection.\n";
		}
		else
		{
			cout << documentName << " document was NOT found in the " << foundCollection.RetName() << " collection.\n";
		}
	}
	else
	{
		cout << collectionName << " collection was NOT found.\n";
	}
	return 0;
}

bool searchForCollection(std::string collectionName)
{
	for (int cnt = 0; cnt < tempCollectionVector.size(); cnt++)
	{
		if (tempCollectionVector[cnt].RetName() == collectionName)
		{
			return true;
		}
	}
	return false;
}

Collection returnCollection(std::string collectionName)
{
	Collection collectionToReturn;
	for (int cnt = 0; cnt < tempCollectionVector.size(); cnt++)
	{
		if (tempCollectionVector[cnt].RetName() == collectionName)
		{
			collectionToReturn = tempCollectionVector[cnt];
			break;
		}
	}
	return collectionToReturn;
}

bool searchCollectionForDocumentByName(std::string documentName, Collection documentCollection)
{
	std::vector<Document*> documentCollectionVector = documentCollection.returnDocuments();
	for (int cnt = 0; cnt < documentCollectionVector.size(); cnt++)
	{
		if (documentCollectionVector[cnt]->RetName() == documentName)
		{
			return true;
		}
	}
	return false;
}