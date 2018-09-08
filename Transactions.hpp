/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     Transaction class specification file
*********************************************************************/
#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include "BankApp.hpp"

class Transaction {
    private:
        double transactionAMT;

    public:
    	//Default Constructor
        Transaction();
        // add additional member functions here
        double Withdrawl(double);
        double Deposit(double);
};

#endif                              // end of preprocessor directive
