/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     Transaction class implementation file
*********************************************************************/
#include <iostream>
#include <string>
#include <cmath>
#include "Transactions.hpp"

/*********************************************************************
** Description:     1-arg constructor
*********************************************************************/
double Transaction::Withdrawl(char AcctType, double transactionAMT){
	//pull account balance
	//check if balance > than withdrawl amount
		//offer overdraft charge option
	//update balances
	//save transaction withdrawl in file
		//save overdraft charge in different line
	//Take user back to dashboard

//ONLY FOR CHECKING ACCOUNT RIGHT NOW

	//TAKE ABSOLUTE VALUE OF TRANSACTION AMT
	transactionAMT = std::abs(transactionAMT);

	//IF ACCT BALANCE < THAN WITHDRAWL AMOUNT
	if(transactionAMT > CHKBAL){
		std::cout << "Insufficient Funds" << std::endl;
		std::cout << "Accept overdraft fee of $20.00 USD?  (Y/N)" << std::endl;
		std::cin >> feeApproval;
		feeApproval = std::toupper(feeApproval);

		//USER APPROVES OVERDRAFT FEE
		if(feeApproval == 'Y'){
			transactionAMT = transactionAMT + 20.00;
			CHKBAL = CHKBAL - transactionAMT;
			std::cout << WITHDRAWL_BANNER << std::endl;
			std::cout << CHKBANNER << std::endl;
			std::cout << "WITHDRAWL AMOUNT: $" << transactionAMT - 20 << std::endl;
			std::cout << "OVERDRAFT FEE: $20.00" << std::endl;
			std::cout << "REMAINING BALANCE: $" << CHKBAL << std::endl;
			std::cout << "Transaction Complete" << std::endl;
			std::cout << END_BANNER << std::endl;
		}

		//USER REJECTS OVERDRAFT FEE
		if(feeApproval == 'N'){
			std::cout << "Transaction Cancelled" << std::endl;
			//Take user back to dashaboard
		}
	}
	//ACCT HAS SUFFICIENT FUNDS
	else{
		CHKBAL = CHKBAL - transactionAMT;
		std::cout << WITHDRAWL_BANNER << std::endl;
		std::cout << CHKBANNER << std::endl;
		std::cout << "WITHDRAWL AMOUNT: $" << transactionAMT << std::endl;
		std::cout << "REMAINING BALANCE: $" << CHKBAL << std::endl;
		std::cout << "Transaction Complete" << std::endl;
		std::cout << END_BANNER << std::endl;
	}

	return 0;

};

double Transaction::Deposit(char AcctType, double transactionAMT){
	//pull account balance
	//add deposit to account balance
	//update balance
	//save transaction deposit in file
	//Take user back to dashboard

//ONLY FOR CHECKING ACCOUNT RIGHT NOW

	//TAKE ABSOLUTE VALUE OF TRANSACTION AMT
	transactionAMT = std::abs(transactionAMT);

	//DEPOSITS FUNDS INTO ACCT
	CHKBAL = CHKBAL + transactionAMT;
	std::cout << DEPOSIT_BANNER << std::endl;
	std::cout << CHKBANNER << std::endl;
	std::cout << "DEPOSIT AMOUNT: $" << transactionAMT << std::endl;
	std::cout << "REMAINING BALANCE: $" << CHKBAL << std::endl;
	std::cout << "Transaction Complete" << std::endl;
	std::cout << END_BANNER << std::endl;

	return 0;
};