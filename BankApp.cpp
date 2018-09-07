/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     BankingApp class implementation file
*********************************************************************/
#include "BankApp.hpp"
#include "Checkings.hpp"
#include "Savings.hpp"
#include <iostream>
#include <regex>                        // regular expression validation
#include <ctime>                        // time function
#include <cstdlib>                      // srand() and rand() functions
using std::string;
using std::cout;
using std::cin;
using std::endl;

void BankApp::introScreen() 
{
    std::cout << R"(
    ██████╗ ██████╗ ███████╗ ██████╗  ██████╗ ███╗   ██╗
    ██╔═══██╗██╔══██╗██╔════╝██╔════╝ ██╔═══██╗████╗  ██║
    ██║   ██║██████╔╝█████╗  ██║  ███╗██║   ██║██╔██╗ ██║
    ██║   ██║██╔══██╗██╔══╝  ██║   ██║██║   ██║██║╚██╗██║
    ╚██████╔╝██║  ██║███████╗╚██████╔╝╚██████╔╝██║ ╚████║
    ╚═════╝ ╚═╝  ╚═╝╚══════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝

    ███████╗████████╗ █████╗ ████████╗███████╗
    ██╔════╝╚══██╔══╝██╔══██╗╚══██╔══╝██╔════╝
    ███████╗   ██║   ███████║   ██║   █████╗
    ╚════██║   ██║   ██╔══██║   ██║   ██╔══╝    
    ███████║   ██║   ██║  ██║   ██║   ███████╗
    ╚══════╝   ╚═╝   ╚═╝  ╚═╝   ╚═╝   ╚══════╝

    ██████╗  █████╗ ███╗   ██╗██╗  ██╗        Version 1.0
    ██╔══██╗██╔══██╗████╗  ██║██║ ██╔╝        Created by:
    ██████╔╝███████║██╔██╗ ██║█████╔╝                          
    ██╔══██╗██╔══██║██║╚██╗██║██╔═██╗         Sandro Aguilar     
    ██████╔╝██║  ██║██║ ╚████║██║  ██╗        Kuljot Biring
    ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝        Christian Martinez
)" << '\n';
}

void mainFunction()
    {
        char selection {};

        do
        {
            // Display menu
            std::cout << "L - Log into account" << std::endl;
            std::cout << "A - Open an account" << std::endl;
            std::cout << "Q - Quit Program" << std::endl;
            std::cout << "\nEnter your choice: ";

            std::cin >> selection;

            // use toupper function to make all letters capital
            selection = toupper(selection);

            // switch selection choices from menu
            switch (selection)
            {
                case 'L':
                {
                    //bank.logIn();
                }
                    break;

                case 'A':
                {
                    //bank.createAccount();
                }
                    break;

                case 'Q':
                {
                    std::cout << "Goodbye" << std::endl;
                }
                    break;

                default:
                {
                    std::cout << "Unknown selection, please try again" << std::endl;
                }
            }

        }while(selection != 'q' && selection != 'Q');
    }

void BankApp::menuTwo() {
    char selection = ' ';

    do {
        // Display menu
        std::cout << "V - View your Account" << std::endl;
        std::cout << "M - Make A Deposit" << std::endl;
        std::cout << "W - Withdraw" << std::endl;
        std::cout << "T - Transfer Funds" << std::endl;
        std::cout << "S - View Transactions" << std::endl;
        std::cout << "U - Update Account Details" << std::endl;
        std::cout << "C - Close Account" << std::endl;
        std::cout << "Q - Exit Menu" << std::endl;
        std::cout << "\nEnter your choice: ";

        std::cin >> selection;

        // use toupper function to make all letters capital
        selection = toupper(selection);

        // switch selection choices from menu
        switch (selection) {
            case 'V': {

            }
            break;

            case 'M':
            {

            }
            break;

            case 'W':
            {

            }
            break;

            case 'T':
            {

            }
            break;

            case 'S':
            {

            }
            break;

            case 'U':
            {

            }
            break;

            case 'C':
            {

            }
            break;

            case 'Q':
            {

            }
            break;

            default:
            {
                         std::cout << "Unknown selection, please try again" << std::endl;
            }
        }

    } while (selection != 'q' && selection != 'Q');
}



void BankApp::createAccount() {
    // have user create a username
    string userName;
    cout << "Enter a username between 4 and 10 alphanumeric characters: ";
    getline(cin, userName);

    // username validation using regex
    std::regex usernamePattern("[a-zA-Z0-9]{4,10}");    // regex object and pattern to search
    std::smatch m;

    while (!std::regex_match(userName, m, usernamePattern)) {      // validate username
        cout << "Error! Enter a username between 5 and 10 alphanumeric characters and no spacing: ";
        cin >> userName;
    }

    // have user create a 4 digit password/pin
    string pin;
    cout << "Enter a 4 digit pin (0-9): ";
    cin >> pin;

    // pin validation using regex
    std::regex pinPattern("[0-9]{4}");
    while (!std::regex_match(pin, m, pinPattern)) {      // validate username
        cout << "Error! Enter a pin 4 characters long and no spacing: ";
        cin >> pin;
    }

    // have user select they type of account (checking/savings)
    char accountType = ' ';
    cout << "Would you like to open a checking or savings account? Enter c or s: ";
    cin >> accountType;
    while (accountType != 'c' && accountType != 's') {
        cout << "Please enter c for checking or s for savings: ";
        cin >> accountType;
    }

    // ask user for a initial deposit amount
    double initialDeposit {0};
    cout << "How much would you like to deposit into tyour account? ";
    cin >> initialDeposit;
    while (initialDeposit < 0) {
        cout << "Please enter an amount of zero or greater: ";
        cin >> initialDeposit;
    }

    // set up account object with initial deposit and store in account array
    if(accountType == 'c') {
        Checkings c(initialDeposit);
        checkingAccounts.push_back(c);
    }
    else if (accountType == 's') {
        Savings s(initialDeposit);
        savingsAccounts.push_back(s);
    }

    // generate account number and save as a variable
    string acctNumber = accountNumberGenerator();

}

string BankApp::accountNumberGenerator() {
    unsigned seed = time(0);
    srand(seed);
}

void BankApp::logIn() {
    
}

