#ifndef _USERACCOUNTS_HPP_
#define _USERACCOUNTS_HPP_

#include "document.hpp"

class userAccounts {

    public:
        userAccounts();
        bool getLogin(int);
        void logout();
        void login();
        void newAccount(int);
        // void changePassword();
        // void deleteAccount();
        
    private:
        Document userDatabase;
        bool loggedIn;
        int storedEncryptionKey;
};

#endif //_USERACCOUNTS_HPP_