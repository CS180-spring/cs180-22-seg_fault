#ifndef _USERACCOUNTS_HPP_
#define _USERACCOUNTS_HPP_

#include "document.hpp"
#include "logging.hpp"

class userAccounts {

    public:
        userAccounts();
        bool getLogin(int);
        void logout();
        void login();
        void newAccount(int);
        void changePassword();
        void deleteAccount();   
        string getUsername();
        bool check_user(string filename);
        
    private:
        Document userDatabase;
        bool loggedIn;
        int storedEncryptionKey;
        string userName;
        logging accountLogs{"accountLogs.txt"};
};

#endif //_USERACCOUNTS_HPP_
