#include "collection.cpp"
#include "document.cpp"
#include "userInterface.cpp"
#include "userAccounts.cpp"

int main()
{
	srand(time(0));
	userInterface UI;
	UI.loginMenu();
	return 0;
}
