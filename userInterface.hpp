#ifndef _USERINTERFACE_HPP_
#define _USERINTERFACE_HPP_

#include "document.hpp"
#include "userAccounts.hpp"
#include "logging.hpp"
#include <string>

using namespace std;

class userInterface 
{
    public:
        userInterface();
        void loginMenu();
        // void accountManagement();
        void documentMenu();
    private:
        userAccounts currentUser;
        int encryptionKey;
        logging userLogs{"userLogs.txt"};
};

#endif //_USERINTERFACE_HPP