#include "collection.hpp"
#include "document.hpp"
#include "userInterface.hpp"
#include "userAccounts.hpp"

void encrypt();
void decrypt();

int key = 5;
fstream fin, fout;
char c;

int main()
{
	//encrypt();
	decrypt();
	// userInterface UI;
	// UI.loginMenu();
	
	return 0;
}

void encrypt()
{
	fin.open("Accounts.csv", fstream::in);
	fout.open("Accounts-encrypted.csv", fstream::out);

	while (fin >> noskipws >> c)
	{
		int temp = (c + key);

		fout << (char)temp;
	}

	fin.close();
	fout.close();
}

void decrypt()
{
	fin.open("Accounts-encrypted.csv", fstream::in);
	fout.open("Accounts-decrypted.csv", fstream::out);

	while (fin >> noskipws >> c)
	{
		int temp = (c - key);

		fout << (char)temp;
	}
	fin.close();
	fout.close();
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