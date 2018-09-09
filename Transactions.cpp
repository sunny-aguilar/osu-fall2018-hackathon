/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     Transaction class implementation file
*********************************************************************/
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 
#include "Transactions.hpp"

/*********************************************************************
** Description:     1-arg constructor
*********************************************************************/
Transaction::Transaction(std::string  INPUT_FILENAME){
	std::string line;
	std::string fileName = INPUT_FILENAME;
	std::vector<std::string> AccountInfo;
	std::string tempBAL;

	//Defines i/o file stream objects
	std::ifstream inputFile;
	std::ofstream outputFile;
	fileName = fileName + ".txt";

	//Opens file
	inputFile.open(fileName);

	//Checks if inputFile can be opened
	if(!inputFile){
		std::cout << "Could not access file" << std::endl;
	}
	else{
		/*Iterates through each line in inputFile
		  Reads each line of inputFile*/
		while (std::getline(inputFile, line)){
			//Adds elements to Vector
			AccountInfo.push_back(line);
		}
	}
 
	//Assigns Account Info from file
	ACCTNUM = AccountInfo[0];
	AcctTypeFile = std::toupper(AccountInfo[3][5]);

	//Assigns Balances to Variables
	if(AcctType == 'C'){
		for(int i=4; i<AccountInfo[4].length(); i++){
			tempBAL = tempBAL + std::to_string(AccountInfo[4][i]);
		}
		CHKBAL = std::stod(tempBAL.c_str());
	}
	else if(AcctType == 'S'){
		for(int i=4; i<AccountInfo[4].length(); i++){
			tempBAL = tempBAL + std::to_string(AccountInfo[4][i]);
		}
		SAVBAL = std::stod(tempBAL.c_str());
	}
	else{
		std::cout << "Account Type not recognized" << std::endl;
	}

	//Closes file stream objects
	inputFile.close();

	//Banners for output
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

double Transaction::Withdrawl(char AcctType, double transactionAMT){
	//TAKE ABSOLUTE VALUE OF TRANSACTION AMT
	transactionAMT = std::abs(transactionAMT);

	AcctType = std::toupper(AcctType);

	if(AcctType == 'C'){
		/*********************************************************************
		** CHECKING ACCOUNT WITHDRAWL
		*********************************************************************/
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
	}
	else if(AcctType == 'S'){
		/*********************************************************************
		** SAVINGS ACCOUNT WITHDRAWL
		*********************************************************************/
			//IF ACCT BALANCE < THAN WITHDRAWL AMOUNT
			if(transactionAMT > SAVBAL){
				std::cout << "Insufficient Funds" << std::endl;
				std::cout << "Accept overdraft fee of $20.00 USD?  (Y/N)" << std::endl;
				std::cin >> feeApproval;
				feeApproval = std::toupper(feeApproval);

				//USER APPROVES OVERDRAFT FEE
				if(feeApproval == 'Y'){
					transactionAMT = transactionAMT + 20.00;
					SAVBAL = SAVBAL - transactionAMT;
					std::cout << WITHDRAWL_BANNER << std::endl;
					std::cout << SAVBANNER << std::endl;
					std::cout << "WITHDRAWL AMOUNT: $" << transactionAMT - 20 << std::endl;
					std::cout << "OVERDRAFT FEE: $20.00" << std::endl;
					std::cout << "REMAINING BALANCE: $" << SAVBAL << std::endl;
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
				SAVBAL = SAVBAL - transactionAMT;
				std::cout << WITHDRAWL_BANNER << std::endl;
				std::cout << SAVBANNER << std::endl;
				std::cout << "WITHDRAWL AMOUNT: $" << transactionAMT << std::endl;
				std::cout << "REMAINING BALANCE: $" << SAVBAL << std::endl;
				std::cout << "Transaction Complete" << std::endl;
				std::cout << END_BANNER << std::endl;
			}
	}
	else{
		std::cout << "Account type not recognized" << std::endl;
		std::cout << "Withdrawl Transaction Cancelled" << std::endl;
	}

	return 0;

};

double Transaction::Deposit(char, double transactionAMT){
	//TAKE ABSOLUTE VALUE OF TRANSACTION AMT
	transactionAMT = std::abs(transactionAMT);

	AcctType = std::toupper(AcctType);
	/*********************************************************************
	** CHECKING ACCOUNT WITHDRAWL
	*********************************************************************/
	if(AcctType == 'C'){
		//DEPOSITS FUNDS INTO ACCT
		CHKBAL = CHKBAL + transactionAMT;
		std::cout << DEPOSIT_BANNER << std::endl;
		std::cout << CHKBANNER << std::endl;
		std::cout << "DEPOSIT AMOUNT: $" << transactionAMT << std::endl;
		std::cout << "REMAINING BALANCE: $" << CHKBAL << std::endl;
		std::cout << "Transaction Complete" << std::endl;
		std::cout << END_BANNER << std::endl;
	}
	/*********************************************************************
	** SAVINGS ACCOUNT WITHDRAWL
	*********************************************************************/
	else if(AcctType == 'S'){
		//DEPOSITS FUNDS INTO ACCT
		SAVBAL = SAVBAL + transactionAMT;
		std::cout << DEPOSIT_BANNER << std::endl;
		std::cout << SAVBANNER << std::endl;
		std::cout << "DEPOSIT AMOUNT: $" << transactionAMT << std::endl;
		std::cout << "REMAINING BALANCE: $" << SAVBAL << std::endl;
		std::cout << "Transaction Complete" << std::endl;
		std::cout << END_BANNER << std::endl;
	}
	else{
		std::cout << "Account type not recognized" << std::endl;
		std::cout << "Withdrawl Transaction Cancelled" << std::endl;
	}

	return 0;
};