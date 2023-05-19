#ifndef _USERACCOUNTS_HPP_
#define _USERACCOUNTS_HPP_

#include "document.hpp"

class userAccounts {

    public:
        userAccounts();
        void login();
        void newAccount();
        void changePassword();
        // void deleteAccount();
        bool getLogin();
        
    private:
        Document userDatabase;
        bool loggedIn;
};
#endif //_USERACCOUNTS_HPP_