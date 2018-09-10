/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     Transaction class specification file
*********************************************************************/
#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

//#include "BankApp.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

class Transaction {
    private:
        double transactionAMT;
        char AcctType;
        char AcctTypeFile;
        char feeApproval;
        std::vector<std::string> AccountInfo;
        std::string fileName;
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
        Transaction(std::string);
        // add additional member functions here
        double Withdrawl(char, double);
        double Deposit(char, double);
};

#endif                              // end of preprocessor directive
