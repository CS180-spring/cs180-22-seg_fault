#include "collection.cpp"
#include "document.cpp"
#include "userInterface.cpp"
#include "userAccounts.cpp"

//OUR MAIN PROGRAM LOOP

int main()
{
	srand(time(0));
	userInterface UI;
	UI.loginMenu();
	return 0;
}
