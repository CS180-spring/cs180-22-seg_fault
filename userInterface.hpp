#ifndef _USERINTERFACE_HPP_
#define _USERINTERFACE_HPP_

#include "document.hpp"
#include "userAccounts.hpp"
#include "logging.hpp"
#include <string>

using namespace std;

class userInterface {

    public:
        void loginMenu();
        // void accountManagement();
        void documentMenu();
    private:
        userAccounts currentUser;
        logging userLogs{"userLogs.txt"};
        // bool loggedIn;
        //database currentDatabase;
        
};
#endif //_USERINTERFACE_HPP