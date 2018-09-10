/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     View Account class implementation file
*********************************************************************/
#include <iostream>
#include <string>
#include "ViewAccount.hpp"

/*********************************************************************
** Description:     1-arg constructor
*********************************************************************/
//Default Constructor

viewAccount::viewAccount(std::string INPUT_FILENAME){
	std::string line;
	std::string fileName = INPUT_FILENAME;
	std::string tempBAL = "";
	double transactionAMT;
    char AcctType;
    char AcctTypeFile;
    char feeApproval;
    std::vector<std::string> AccountInfo;
    std::string ACCTNUM;
    double SAVBAL;
    double CHKBAL;
    std::string END_BANNER;
    END_BANNER = std::string("... ... ... ... ... ... ... ... ... ... ... ... ...\n") +
	             std::string("... ... ... ... ... ... ... ... ... ... ... ... ...\n");

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

	//BEGIN ACCOUNT INFO OUTPUT
	std::cout << END_BANNER << std::endl;
	std::cout << "ACCOUNT NUMBER: " << ACCTNUM << std::endl;

	//Assigns Balances to Variables
	if(AcctTypeFile == 'C'){
		for(int i=4; i<AccountInfo[4].length(); i++){
			tempBAL = tempBAL + AccountInfo[4][i];
		}
		CHKBAL = std::stod(tempBAL.c_str());
		std::cout << "CHECKING ACCOUNT BALANCE: $" << CHKBAL << std::endl;
	}
	else if(AcctTypeFile == 'S'){
		for(int i=4; i<AccountInfo[4].length(); i++){
			tempBAL = tempBAL + AccountInfo[4][i];
		}
		SAVBAL = std::stod(tempBAL.c_str());
		std::cout << "SAVINGS ACCOUNT BALANCE: $" << SAVBAL << std::endl;
	}
	else{
		std::cout << "Account Type not recognized" << std::endl;
	}

	//Closes file stream objects
	inputFile.close();

	//END ACCOUNT INFO OUTPUT
	std::cout << END_BANNER << std::endl;

};
