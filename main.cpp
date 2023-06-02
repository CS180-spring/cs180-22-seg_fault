#include "collection.hpp"
#include "document.hpp"
#include "userInterface.hpp"
#include "userAccounts.hpp"

//OUR MAIN PROGRAM LOOP

int main()
{
	srand(time(0));
	userInterface UI;
	UI.loginMenu();

	return 0;
}
