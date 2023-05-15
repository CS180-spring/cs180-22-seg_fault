#ifndef _USERINTERFACE_HPP_
#define _USERINTERFACE_HPP_

#include "document.hpp"
#include "userAccounts.hpp"

using namespace std;

class userInterface {

    public:
        void loginMenu();
        // void accountManagement();
        void documentMenu();
    private:
        userAccounts currentUser;
        // bool loggedIn;
        //database currentDatabase;
        
};
#endif //_USERINTERFACE_HPP