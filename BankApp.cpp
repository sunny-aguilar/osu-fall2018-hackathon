/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     BankingApp class implementation file
*********************************************************************/
#include "BankApp.hpp"
#include "Checkings.hpp"
#include "Savings.hpp"
#include <iostream>
#include <fstream>                      // filestream operations
#include <regex>                        // regular expression validation
#include <ctime>                        // time function
#include <cstdlib>                      // srand() and rand() functions
#include <vector>                       // vector library
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

/*********************************************************************
** Description:     intro screen logo function
*********************************************************************/
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

/*********************************************************************
** Description:     main menu function
*********************************************************************/
void BankApp::mainMenu()
    {
        char selection {};

        do
        {
            // Display banner
            cout << "... ... ... ... ... ... ... ... ... ... ... ... ...\n"
                    ":::::::::::: WELCOME TO OSU STATE BANK ::::::::::::\n"
                    "... ... ... ... ... ... ... ... ... ... ... ... ...\n";

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
                    //logIn();
                }
                    break;

                case 'A':
                {
                    //createAccount();
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

/*********************************************************************
** Description:     sub-menu function
*********************************************************************/
void BankApp::subMenu() {
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
        switch (selection) 
        {
            case 'V': 
            {
                //loadUserData();
            }
            break;

            case 'M':
            {
                //makeDeposit();
            }
            break;

            case 'W':
            {
                //withdrawFunds();
            }
            break;

            case 'T':
            {
                //transferFunds();
            }
            break;

            case 'S':
            {
                //viewTransactions();
            }
            break;

            case 'U':
            {
                //updateAccount();
            }
            break;

            case 'C':
            {
                //closeAccount();
            }
            break;

            case 'Q':
            {
                //mainMenu();
            }
            break;

            default:
            {
                std::cout << "Unknown selection, please try again" << std::endl;
            }
        }

    } while (selection != 'q' && selection != 'Q');
}

/*********************************************************************
** Description:     create account function
*********************************************************************/
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

    // append username to account number and write to file
    std::ofstream outputFile;
    outputFile.open(userName + "-" + acctNumber + ".txt");
    outputFile << acctNumber << "\n" << pin << "\n" << userName;
    outputFile << "\nType:" << accountType;
    outputFile << "\n" << accountType << "01-" << initialDeposit;

    cout << "Account was successfully created\n";

    outputFile.close();                 // close file
}

/*********************************************************************
** Description:     generate account number function
*********************************************************************/
string BankApp::accountNumberGenerator() {
    unsigned seed = time(0);
    srand(seed);
    string accountNum = "OSU-";
    string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i<13; i++) {
        accountNum += alphanum[rand() % 36];
    }
    std::cout << accountNum << std::endl;   // show account on screen
    return accountNum;
}

/*********************************************************************
** Description:     login function
*********************************************************************/
void BankApp::logIn() {                     // log in to account
    // set up variables
    char go = 'n';
    string userName;
    string accountNumber;
    string pin;
    vector<string> userData;

    do {
        // ask user for login info
        cout << "Enter your username: ";
        cin >> userName;
        cout << "Enter your account number: ";
        cin >> accountNumber;
        cout << "Enter your 4 digit pin: ";
        cin >> pin;

        // create filename from user entered data
        std::ifstream inputFile;
        inputFile.open(userName + "-" + accountNumber + ".txt");

        // check if filename exists
        if (inputFile) {
            cout << "Validating user...";

            // store user file data in array
            // user data stored in vector
            string fileData;
            while(inputFile >> fileData)
                userData.push_back(fileData);


            // check pin # stored in file to user entered pin
            if (pin == userData[1]) {
                cout << "\nLogin successful";
            }

            // load user data into BankApp
            // pass vector w/user data into function to load it
            loadUserData(userData);
        }
        else {
            cout << "This user account was not found\n"
                 << "Would you like to try again?\n";
            cin >> go;
            if(toupper(go) != 'Y') {
                cout << "Have a great day!\n\n\n";

                // return user to main menu
                mainMenu();
            }
        }

    } while (toupper(go) == 'Y');
}

/*********************************************************************
** Description:     loads user data into bank app
*********************************************************************/
void BankApp::loadUserData(const vector<string> &vect) {
    // set account number in private variable
    setAccountNumber(vect[0]);
    // set username in private variable
    setUsername(vect[2]);
    // set checkings and savings objects
}

string BankApp::setAccountNumber(string accountNumber) {
    this->accountNumber = accountNumber;
    return accountNumber;
}

string BankApp::setUsername(string username) {
    this->username = username;
}
