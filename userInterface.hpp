#ifndef _USERINTERFACE_HPP_
#define _USERINTERFACE_HPP_
#include "document.hpp"
#include "userAccounts.hpp"

using namespace std;

class userInterface {

    public:
        void mainMenu();
        void loginMenu();
        void accountMangement();
        void documentMenu();
        
    private:
        userAccount currentUser;
        database currentDatbase;
        bool loggedIn;
};
#endif //_USERINTERFACE_HPP_