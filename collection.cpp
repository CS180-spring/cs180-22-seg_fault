#include "collection.hpp"

void Collection::SetName(string temp) {
    name = temp;
}

string Collection::RetName() {
    return name;
}

void Collection::AddDoc(Document* temp) {
    documents.push_back(temp);
}

void Collection::DelDoc(string documentName)
{
    for (int cnt = 0; cnt < documents.size(); cnt++)
    {
        if (documents[cnt]->RetName() == documentName)
        {
            documents.erase(documents.begin() + cnt);
            cout << documentName << " was removed from the collection.\n";
            return;
        }
    }
    cout << documentName << " was not found in the " << RetName() << " collection.";
}

void Collection::AddTag(string temp) {
    tags.push_back(temp);
}

vector<Document*> Collection::returnDocuments()
{
    return documents;
}

vector<string> Collection::returnTags()
{
    return tags;
}


std::vector<Document*> Collection::findTaggedDocuments(std::string tag)
{
    std::vector<Document*> taggedDocs;
    taggedDocs = this->returnDocuments();
    Document* curr;
    std::vector<Document*> ans;
    for (int i = 0; i < taggedDocs.size(); ++i)
    {
        curr = taggedDocs.at(i);
        for (int j = 0; j < curr->tags.size(); ++j)
        {
            if (curr->tags[j] == tag)
            {
                ans.push_back(curr);
            }
        }
    }
    return ans;
}

int Collection::collectionSize()
{
    return documents.size();
}

void Collection::displayContents()
{
    for(int i = 0; i < documents.size(); ++i)
        cout << documents.at(i)->RetName() << endl;
}

