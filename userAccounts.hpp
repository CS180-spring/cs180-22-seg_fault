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
        void changePassword();
        void deleteAccount();   
        bool getLogin();
        string getUsername();
        bool check_user(string filename);
        
    private:
        Document userDatabase;
        bool loggedIn;
        int storedEncryptionKey;
        string userName;
};

#endif //_USERACCOUNTS_HPP_