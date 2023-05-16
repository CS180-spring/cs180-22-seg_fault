#ifndef _USERINTERFACE_HPP_
#define _USERINTERFACE_HPP_

#include "document.hpp"
#include "userAccounts.hpp"

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
};

#endif //_USERINTERFACE_HPP