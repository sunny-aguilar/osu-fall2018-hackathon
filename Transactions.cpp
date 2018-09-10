/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     Transaction class implementation file
*********************************************************************/
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
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

double Transaction::Withdrawl(char INPUTAcctType, double INPUTtransactionAMT){
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::string tempAcctHolder;

	//TAKE ABSOLUTE VALUE OF TRANSACTION AMT
	transactionAMT = std::abs(INPUTtransactionAMT);

	AcctType = std::toupper(INPUTAcctType);

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

			//Updating Balances in text file
			inputFile.open(fileName);
			tempAcctHolder = AccountInfo[4][3];

			AccountInfo[4] = tempAcctHolder + std::to_string(CHKBAL);


			//Add Timestamp to file
			auto transactionTime = std::chrono::system_clock::now();
			std::time_t dateTimeStamp = std::chrono::system_clock::to_time_t(transactionTime);

			//Opens file
			inputFile.open("T-" + fileName);

			//Checks if inputFile can be opened
			if(!inputFile){
				outputFile.open("T-" + fileName);
				outputFile << "Withdrawl AMT $" + std::to_string(transactionAMT) + " " + std::to_string(std::ctime(&dateTimeStamp));
				outputFile << "Overdraft Fee $20.00" + " " + std::to_string(std::ctime(&dateTimeStamp));
				outputFile << "CHK Balance $" + std::to_string(CHKBAL) + " " + std::to_string(std::ctime(&dateTimeStamp));
			}
			else{
				inputFile << "Withdrawl AMT $" + std::to_string(transactionAMT) + " " + std::to_string(std::ctime(&dateTimeStamp));
				inputFile << "Overdraft Fee $20.00" + " " + std::to_string(std::ctime(&dateTimeStamp));
				inputFile << "CHK Balance $" + std::to_string(CHKBAL) + " " + std::to_string(std::ctime(&dateTimeStamp));
			}
			//Checks if output file can be opened
			if(!outputFile){
				std::cout << "Error creating file." << std::endl;
			}

			//Closes file stream objects
			outputFile.close();
			inputFile.close();
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
			
			//Updating Balances in text file
			inputFile.open(fileName);
			tempAcctHolder = AccountInfo[4][3];

			AccountInfo[4] = tempAcctHolder + std::to_string(SAVBAL);


			//Add Timestamp to file
			auto transactionTime = std::chrono::system_clock::now();
			std::time_t dateTimeStamp = std::chrono::system_clock::to_time_t(transactionTime);

			//Opens file
			inputFile.open("T-" + fileName);

			//Checks if inputFile can be opened
			if(!inputFile){
				outputFile.open("T-" + fileName);
				outputFile << "Withdrawl AMT $" + std::to_string(transactionAMT) + " " + std::to_string(std::ctime(&dateTimeStamp));
				outputFile << "Overdraft Fee $20.00" + " " + std::to_string(std::ctime(&dateTimeStamp));
				outputFile << "SAV Balance $" + std::to_string(SAVBAL) + " " + std::to_string(std::ctime(&dateTimeStamp));
			}
			else{
				inputFile << "Withdrawl AMT $" + std::to_string(transactionAMT) + " " + std::to_string(std::ctime(&dateTimeStamp));
				inputFile << "Overdraft Fee $20.00" + " " + std::to_string(std::ctime(&dateTimeStamp));
				inputFile << "SAV Balance $" + std::to_string(SAVBAL) + " " + std::to_string(std::ctime(&dateTimeStamp));
			}
			//Checks if output file can be opened
			if(!outputFile){
				std::cout << "Error creating file." << std::endl;
			}

			//Closes file stream objects
			outputFile.close();
			inputFile.close();
	}
	else{
		std::cout << "Account type not recognized" << std::endl;
		std::cout << "Withdrawl Transaction Cancelled" << std::endl;
	}

	return 0;

};

double Transaction::Deposit(char INPUTAcctType, double INPUTtransactionAMT){
	//Defines i/o file stream objects
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::string tempAcctHolder;

	//TAKE ABSOLUTE VALUE OF TRANSACTION AMT
	transactionAMT = std::abs(INPUTtransactionAMT);

	AcctType = std::toupper(INPUTAcctType);
	/*********************************************************************
	** CHECKING ACCOUNT WITHDRAWL
	*********************************************************************/
	if(AcctType == 'C'){
		//DEPOSITS FUNDS INTO ACCT
		CHKBAL = CHKBAL + transactionAMT;
		std::cout << DEPOSIT_BANNER << std::endl;

		CHKBAL = CHKBAL - transactionAMT;
		std::cout << WITHDRAWL_BANNER << std::endl;

		std::cout << CHKBANNER << std::endl;
		std::cout << "WITHDRAWL AMOUNT: $" << transactionAMT << std::endl;
		std::cout << "REMAINING BALANCE: $" << CHKBAL << std::endl;
		std::cout << "Transaction Complete" << std::endl;
		std::cout << END_BANNER << std::endl;


		//Updating Balances in text file
		inputFile.open(fileName);
		tempAcctHolder = AccountInfo[4][3];
		AccountInfo[4] = tempAcctHolder + std::to_string(CHKBAL);

		//Add Timestamp to file
		auto transactionTime = std::chrono::system_clock::now();
		std::time_t dateTimeStamp = std::chrono::system_clock::to_time_t(transactionTime);

		//Opens file
		inputFile.open("T-" + fileName);

		//Checks if inputFile can be opened
		if(!inputFile){
			outputFile.open("T-" + fileName);
			outputFile << "Deposit AMT $" + std::to_string(transactionAMT) + " " + std::to_string(std::ctime(&dateTimeStamp));
			outputFile << "CHK Balance $" + std::to_string(CHKBAL) + " " + std::to_string(std::ctime(&dateTimeStamp));
		}
		else{
			inputFile << "Deposit AMT $" + std::to_string(transactionAMT) + " " + std::to_string(std::ctime(&dateTimeStamp));
			inputFile << "CHK Balance $" + std::to_string(CHKBAL) + " " + std::to_string(std::ctime(&dateTimeStamp));
		}
		//Checks if output file can be opened
		if(!outputFile){
			std::cout << "Error creating file." << std::endl;
		}

		//Closes file stream objects
		outputFile.close();
		inputFile.close();

	}


		//Updating Balances in text file
		inputFile.open(fileName);
		tempAcctHolder = AccountInfo[4][3];
		AccountInfo[4] = tempAcctHolder + std::to_string(SAVBAL);


};

double Transaction::Deposit(char AcctType, double transactionAMT){
	//pull account balance
	//add deposit to account balance
	//update balance
	//save transaction deposit in file
	//Take user back to dashboard


		//Checks if inputFile can be opened
		if(!inputFile){
			outputFile.open("T-" + fileName);
			outputFile << "Deposit AMT $" + std::to_string(transactionAMT) + " " + std::to_string(std::ctime(&dateTimeStamp));
			outputFile << "SAV Balance $" + std::to_string(SAVBAL) + " " + std::to_string(std::ctime(&dateTimeStamp));
		}
		else{
			inputFile << "Deposit AMT $" + std::to_string(transactionAMT) + " " << std::to_string(std::ctime(&dateTimeStamp));
			inputFile << "SAV Balance $" + std::to_string(SAVBAL) + " " + std::to_string(std::ctime(&dateTimeStamp));
		}
		//Checks if output file can be opened
		if(!outputFile){
			std::cout << "Error creating file." << std::endl;
		}


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