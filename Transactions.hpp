/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     Transaction class specification file
*********************************************************************/
#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

//#include "BankApp.hpp"
#include <iostream>
#include <string>
#include <cmath>

class Transaction {
    private:
        double transactionAMT;
        char AcctType;
        char feeApproval;
        std::string ACCTNUM;
        double SAVBAL;
        double CHKBAL;
        std::string CHKBANNER;
        std::string SAVBANNER;
        std::string DEPOSIT_BANNER;
        std::string WITHDRAWL_BANNER;
        std::string END_BANNER;

    public:
    	//Default Constructor
        Transaction(std::string INPUT_ACCTNUM, double INPUT_SAVBAL, double INPUT_CHKBAL){
        	ACCTNUM = INPUT_ACCTNUM;
        	SAVBAL = INPUT_SAVBAL;
        	CHKBAL = INPUT_CHKBAL;
            CHKBANNER = std::string("... ... ... ... ... ... ... ... ... ... ... ... ...\n") +
                        std::string(":::::::::::::     CHECKING ACCOUNT     ::::::::::::\n") +
                        std::string("... ... ... ... ... ... ... ... ... ... ... ... ...\n");
            SAVBANNER = std::string("... ... ... ... ... ... ... ... ... ... ... ... ...\n") +
                        std::string(":::::::::::::     SAVINGS ACCOUNT     :::::::::::::\n") +
                        std::string("... ... ... ... ... ... ... ... ... ... ... ... ...\n");
            DEPOSIT_BANNER = std::string("... ... ... ... ... ... ... ... ... ... ... ... ...\n") +
                             std::string("::::::::::::::::: DEPOSIT SUMMARY :::::::::::::::::\n") +
                             std::string("... ... ... ... ... ... ... ... ... ... ... ... ...\n");
            WITHDRAWL_BANNER =  std::string("... ... ... ... ... ... ... ... ... ... ... ... ...\n") +
                                std::string(":::::::::::::::: WITHDRAWL SUMMARY ::::::::::::::::\n") +
                                std::string("... ... ... ... ... ... ... ... ... ... ... ... ...\n");
            END_BANNER = std::string("... ... ... ... ... ... ... ... ... ... ... ... ...\n") +
                         std::string("... ... ... ... ... ... ... ... ... ... ... ... ...\n");
        };
        // add additional member functions here
        double Withdrawl(char, double);
        double Deposit(char, double);
};

#endif                              // end of preprocessor directive
