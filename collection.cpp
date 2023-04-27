#include "collection.hpp"

void Collection::SetName(std::string temp) {
    name = temp;
}

std::string Collection::RetName() {
    return name;
}

void Collection::AddDoc(Document* temp) {
    documents.push_back(temp);
}

void Collection::AddTag(std::string temp) {
    tags.push_back(temp);
}

std::vector<Document*> Collection::returnDocuments()
{
    return documents;
}

std::vector<std::string> Collection::returnTags()
{
    return tags;
}

bool Collection::searchForDocumentByName(std::string documentName)
{
	for (int cnt = 0; cnt < documents.size(); cnt++)
	{
		if (documents[cnt]->RetName() == documentName)
		{
			return true;
		}
	}
	return false;
}

