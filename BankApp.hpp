/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     BankingApp class specification file
*********************************************************************/
#ifndef BANKAPP_HPP
#define BANKAPP_HPP
#include "Checkings.hpp"
#include "Savings.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;

class BankApp {
    private:
        // hold checkings and savings accounts
        vector<Checkings> checkingAccounts;
        vector<Savings> savingsAccounts;

        // variables to hold user account info
        string accountNumber;
        string username;
        string pin;
        string fileName;

    public:
        void introScreen();
        void mainMenu();
        void subMenu();
        string accountNumberGenerator();
        void createAccount();
        void logIn();
        void loadUserData(const vector<string> &vect);
        void setAccountNumber(string accountNumber);
        void setUsername(string username);
        void setPin(string pin);
        void setFileName(string file);
        void setCheckings(Checkings setAmount);
        void setSavings(Savings setAmount);
        string getAccountNumber();
        string getUsername();
        string getPin();
        string getFileName();
        double getCheckings();
        double getSavings();
        void typeWriting(const string&, unsigned int timePerChar);
        vector<string> extractAccounts(vector<string> vect, char type);
        string parseBalance(string accountAmount);
        void closeAccount(string fileName);
        void viewUserData();
        void updateAccount();
};

#endif                              // end of preprocessor directive
