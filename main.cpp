#include <iostream>
#include "document.cpp"

bool searchDocumentByName(std::string, std::vector<Document>);

int main()
{
	std::string input = "";
	std::cout << "Input document name: ";
	getline(std::cin, input);
	std::vector<Document> storedDocuments;
	if (searchDocumentByName(input, storedDocuments))
	{
		std::cout << "document name found in storedDocuments vector\n";
	}
	else
	{
		std::cout << "document name NOT found in storedDocuments vector\n";
	}
}

bool searchDocumentByName(std::string input, std::vector<Document> storedDocuments)
{
	for (int cnt = 0; cnt < storedDocuments.size(); cnt++)
	{
		if (storedDocuments[cnt].RetName() == input)
		{
			return true;
		}
	}
	return false;
}