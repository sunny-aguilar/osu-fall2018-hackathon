/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     BankingApp class implementation file
*********************************************************************/
#define RESET   "\033[0m"                   // reset color
#define RED     "\033[31m"                  // red 
#define BOLDRED     "\033[1m\033[31m"      // bold red 
#define BOLDGREEN   "\033[1m\033[32m"      // bold green 
#define BOLDYELLOW  "\033[1m\033[33m"      // bold yellow 
#define BOLDBLUE    "\033[1m\033[34m"      // bold blue 
#define BOLDMAGENTA "\033[1m\033[35m"      // bold magenta 
#define BOLDCYAN    "\033[1m\033[36m"      // bold cyan 

#include "BankApp.hpp"
#include "Checkings.hpp"
#include "Savings.hpp"
#include "Transactions.hpp"
#include <iostream>
#include <string>
#include <fstream>                      // filestream operations
#include <regex>                        // regular expression validation
#include <ctime>                        // time function
#include <cstdlib>                      // srand() and rand() functions
#include <vector>                       // vector library
#include <thread>
#include <chrono>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::flush;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

/*********************************************************************
** Description:     intro screen logo function
*********************************************************************/
void BankApp::introScreen() 
{
    cout << RED;
    string message = R"(
    PLEASE WAIT....LOADING BANKING SOFTWARE.....

    ██████╗ ██████╗ ███████╗ ██████╗  ██████╗ ███╗   ██╗
    ██╔═══██╗██╔══██╗██╔════╝██╔════╝ ██╔═══██╗████╗  ██║
    ██║   ██║██████╔╝█████╗  ██║  ███╗██║   ██║██╔██╗ ██║
    ██║   ██║██╔══██╗██╔══╝  ██║   ██║██║   ██║██║╚██╗██║
    ╚██████╔╝██║  ██║███████╗╚██████╔╝╚██████╔╝██║ ╚████║
    ╚═════╝ ╚═╝  ╚═╝╚══════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝

    ███████╗████████╗ █████╗ ████████╗███████╗        (\.---./)
    ██╔════╝╚══██╔══╝██╔══██╗╚══██╔══╝██╔════╝         /.-.-.\
    ███████╗   ██║   ███████║   ██║   █████╗          /| 0_0 |\
    ╚════██║   ██║   ██╔══██║   ██║   ██╔══╝         |_`-(v)-'_|
    ███████║   ██║   ██║  ██║   ██║   ███████╗       \`-._._.-'/
    ╚══════╝   ╚═╝   ╚═╝  ╚═╝   ╚═╝   ╚══════╝ -~-(((.`-\_|_/-'.)))-~' <_

    ██████╗  █████╗ ███╗   ██╗██╗  ██╗              Version 1.0
    ██╔══██╗██╔══██╗████╗  ██║██║ ██╔╝              Created by:
    ██████╔╝███████║██╔██╗ ██║█████╔╝
    ██╔══██╗██╔══██║██║╚██╗██║██╔═██╗               Sandro Aguilar
    ██████╔╝██║  ██║██║ ╚████║██║  ██╗              Kuljot Biring
    ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝              Christian Martinez
    )";

    typeWriting(message, 3);
    cout << RESET <<  endl;
}

/*********************************************************************
** Description:     main menu function
*********************************************************************/
void BankApp::mainMenu()
    {
        char selection {};

        do
        {
            // Display banner and menu with raw strings
            cout << BOLDYELLOW;
    std::cout << R"(

 　        ▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬▬▬▬ MENU OPTIONS ▬▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬

                                    L - Log into account
                                    A - Open an account
                                    Q - Quit Program
                                    Enter your choice: ☜


            )" << '\n';
    cout << RESET << endl;

           
            // ask user for selection input
            cin.get(selection);
            cin.ignore();

            // use toupper function to make all letters capital
            selection = toupper(selection);

            // switch selection choices from menu
            switch (selection)
            {
                case 'L':
                {
                    logIn();
                }
                    break;

                case 'A':
                {
                    createAccount();
                }
                    break;

                case 'Q':
                {
                    cout << BOLDGREEN;
                    cout << "Goodbye" << endl;
                    cout << R"(
                        _._._                        _._._
                       _|   |_                      _|   |_
                        | ... |_._._._._._._._._._._| ... |
                        | ||| |  o  OSU  BANK    o  | ||| |
                        | """ |  """    """    """  | """ |
                   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())
                  (())) |     |---------------------|     | (()))
                 (())())| """ |  """    """    """  | """ |(())())
                 (()))()|[-|-]|  :::   .-"-.   :::  |[-|-]|(()))()
                 ()))(()|     | |~|~|  |_|_|  |~|~| |     |()))(()
                    ||  |_____|_|_|_|__|_|_|__|_|_|_|_____|  ||
                ~ ~^^ @@@@@@@@@@@@@@/=======\@@@@@@@@@@@@@@ ^^~ ~
                    ^~^~                                ~^~^
                    )" << '\n';

                    cout << "Please come again!" << endl;
                    cout << RESET;
                }
                    break;

                default:
                {
                    cout << BOLDRED;
                    cout << "Unknown selection, please try again!!" << endl;
                    cout << RESET;
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
        // Display banner
        cout << BOLDMAGENTA;
        cout << R"(

 　        ▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬▬▬▬ MENU OPTIONS ▬▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬

                                    V - View your Account
                                    M - Make A Deposit
                                    W - Withdraw
                                    T - Transfer Funds
                                    S - View Transactions
                                    U - Update Account Details
                                    C - Close Account
                                    Q - Exit Menu
                                    Enter your choice: ☜


            )" << '\n';
        cout << RESET << endl;

        cin >> selection;
        cin.ignore();

        // use toupper function to make all letters capital
        selection = toupper(selection);

        // switch selection choices from menu
        switch (selection) 
        {
            case 'V': 
            {
                viewUserData();
            }
            break;

            case 'M':
            {
                //makeDeposit();
            }
            break;

            case 'W':
            {   
                Transaction T1(filename);
                double withdrawlAMT;
                std::string ACTTYPE;

                cout << "Enter C for Checkings, S for Savings" << endl;
                cin << ACTTYPE;

                cout << "Enter withdrawl amount" << endl;
                cin >> withdrawlAMT;

                T1.Withdrawl(ACTYPE, withdrawlAMT);
            }
            break;

            case 'T':
            {
                //transferFunds();
            }
            break;

            case 'S':
            {
                viewAccount V1(filename);
            }
            break;

            case 'U':
            {
                updateAccount();
            }
            break;

            case 'C':
            {
                closeAccount(fileName);
            }
            break;

            case 'Q':
            {
                //mainMenu();
            }
            break;

            default:
            {
                cout << BOLDRED;
                cout << "Unknown selection, please try again!!" << endl;
                cout << RESET;
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
    cout << "Create a username between 4 and 10 alphanumeric characters: ";
    getline(cin, userName);

    // username validation using regex
    std::regex usernamePattern("[a-zA-Z0-9]{4,10}");    // regex object and pattern to search
    std::smatch m;

    while (!std::regex_match(userName, m, usernamePattern)) {      // validate username
        cout << "\nError! Create a username between 4 and 10 alphanumeric characters and no spacing: ";
        cin >> userName;
    }

    // have user create a 4 digit password/pin
    string pin;
    cout << "Create a 4 digit pin (0-9): ";
    cin >> pin;

    // pin validation using regex
    std::regex pinPattern("[0-9]{4}");
    while (!std::regex_match(pin, m, pinPattern)) {      // validate username
        cout << "Error! Create a pin 4 characters long and no spacing: ";
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

    // set fileName
    setFileName(userName + "-" + acctNumber + ".txt");

    // open file to write
    outputFile.open(getFileName());

    // write to file
    outputFile << acctNumber << "\n" << pin << "\n" << userName;
    outputFile << "\nType:" << accountType;
    outputFile << "\n" << "*" << accountType << "01-" << initialDeposit;

    cout << "Account was successfully created\n\n\n";

    outputFile.close();                 // close file

    // take user to sub menu
    subMenu();
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
    string user;
    string accountNumber;
    string pin;
    vector<string> userData;

    do {
        // show login banner
        cout << BOLDCYAN;
        cout << R"(

 　        ▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬ ACCOUNT LOGIN ▬▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬

            )" << '\n';
        cout << RESET;

        // ask user for login info
        cout << RED;
        cout << "Enter your username: ";
        cout << RESET << endl;
        cin >> user;
        cout << BOLDBLUE;
        cout << "Enter your account number: ";
        cout << RESET << endl;
        cin >> accountNumber;
        cin.ignore();   // ignore \n character
        cout << BOLDYELLOW;
        cout << "Enter your 4 digit pin: ";
        cout << RESET << endl;
        getline(cin, pin);

        // create filename from user entered data
        std::ifstream inputFile;

        // set fileName private variable
        inputFile.open(user + "-" + accountNumber + ".txt");

        // check if filename exists
        if (inputFile) {
            cout << BOLDMAGENTA;
            cout << "Validating user...";
            cout << RESET << endl;

            // store user file data in array
            // user data stored in vector
            string fileData;
            while(inputFile >> fileData)
                userData.push_back(fileData);


            // check pin # stored in file to user entered pin
            if (pin == userData[1]) {
                cout << BOLDGREEN; 
                cout << "\nLogin successful\n\n";
                cout << RESET << endl;

                // set fileName private variable
                setFileName(user + "-" + accountNumber + ".txt");

                // load user data into BankApp
                // pass vector w/user data into function to load it
                loadUserData(userData);

                // take user to sub menu
                subMenu();
            }
        }
        else {
            cout << BOLDRED;
            cout << "This user account was not found\n"
                 << "Would you like to try again?\n";
            cout << RESET;
            cin >> go;
            cin.ignore();

            if(toupper(go) != 'Y') {
                cout << BOLDGREEN;
                cout << "Have a great day!\n\n\n";
                cout << RESET;

                // take user to sub menu
                mainMenu();
            }
        }

    } while (toupper(go) == 'Y');
}

/*********************************************************************
** Description:     loads user data into bank app from vector
**                  userData coming from login function
*********************************************************************/
void BankApp::loadUserData(const vector<string> &vect) {
    // set account number in private variable
    setAccountNumber(vect[0]);

    // set username in private variable
    setUsername(vect[2]);

    // set pin in private variable
    setPin(vect[1]);

    // determine how many checkings accounts in file
    vector<string> onlyChecking = extractAccounts(vect, 'c');

    // parse vector and push into checkings object array
    for (int i = 0; i < onlyChecking.size(); i++) {
        // convert checkings balance string to double
        double checkingsAmount = std::stoi(parseBalance(onlyChecking[i]));

        // set checkings account object
        Checkings checkingAccount(checkingsAmount);   // create object
        setCheckings(checkingAccount);                // push object into vector
    }


    // determine how many savings accounts in file
    vector<string> onlySavings = extractAccounts(vect, 's');

    // parse vector and push into checkings object array
    for (int i = 0; i < onlyChecking.size(); i++) {
        // convert savings balance string to double
        double savingsAmount = std::stoi(parseBalance(onlySavings[i]));

        // set savings account object
        Savings savingsAccount(savingsAmount);         // create savings object
        setSavings(savingsAccount);                    // push object into vector
    }
}

/*********************************************************************
** Description:     setter function for account number
*********************************************************************/
void BankApp::setAccountNumber(string accountNumber) {
    this->accountNumber = accountNumber;
}

/*********************************************************************
** Description:     setter function for username variable
*********************************************************************/
void BankApp::setUsername(string username) {
    this->username = username;
}

/*********************************************************************
** Description:     setter function for pin variable
*********************************************************************/
void BankApp::setPin(string pin) {
    this->pin = pin;
}

/*********************************************************************
** Description:     setter function for filename variable
*********************************************************************/
void BankApp::setFileName(string file) {
    this->fileName = file;
}

/*********************************************************************
** Description:     setter function for checkings account variable
*********************************************************************/
void BankApp::setCheckings(Checkings setAmount ) {
    checkingAccounts.push_back(setAmount);
}

/*********************************************************************
** Description:     setter function for savings account variable
*********************************************************************/
void BankApp::setSavings(Savings setAmount ) {
    savingsAccounts.push_back(setAmount);
}

/*********************************************************************
** Description:     getter function for accountNumber variable
*********************************************************************/
string BankApp::getAccountNumber() {
    return accountNumber;
}

/*********************************************************************
** Description:     getter function for username variable
*********************************************************************/
string BankApp::getUsername() {
    return username;
}

/*********************************************************************
** Description:     getter function for pin variable
*********************************************************************/
string BankApp::getPin() {
    return pin;
}

/*********************************************************************
** Description:     getter function for filename variable
*********************************************************************/
string BankApp::getFileName() {
    return fileName;
}

/*********************************************************************
** Description:     getter function for checkings account vector
**                  elements
*********************************************************************/
double BankApp::getCheckings() {
    return checkingAccounts[4].getCheckingsBalance();
}

/*********************************************************************
** Description:     getter function for savings account vector
**                  elements
*********************************************************************/
double BankApp::getSavings() {
    return savingsAccounts[4].getSavingsBalance();
}

/**********************************************************************************
** Function prints each character in a string with a delay to create a typewriter
** The first parameter request the string to be displayed and the second parameter
** is the number of milliseconds each character takes to print
**********************************************************************************/
void BankApp::typeWriting(const string  &message, unsigned int timePerChar)
{
    // range based for loop for each character in the string
    for (const char x: message)
    {
        // use flush to empty buffer after printing character
        cout << x << flush;

        // thread to sleep for specified milliseconds to create delay.
        sleep_for(milliseconds(timePerChar));
    }
}

/*********************************************************************
** Description:   get total types of accounts c/s
*********************************************************************/
vector<string> BankApp::extractAccounts(vector<string> vect, char type) {
    vector<string> accountsExtracted;

    for (int i = 0; i < vect.size(); i++) {
        if (vect[i][0] == '*' && vect[i][1] == type)
            accountsExtracted.push_back(vect[i]);
    }

    return accountsExtracted;
}

/*********************************************************************
** Description:     parse balance amounts form file by removing the
**                  first four characters x##-
*********************************************************************/
string BankApp::parseBalance(string accountAmount) {
    auto temp = accountAmount;
    temp.erase(0,4);

    return temp;
}

/*********************************************************************
** Description:     delete customer account by deleting file
*********************************************************************/
void BankApp::closeAccount(string fileName) {
    cout << "Filename: " << fileName << endl;
    char confirm{'n'};
    cout << "We are sad to see you go. "
            "Are you sure you want to close your account? ";

    cin >> confirm;
    cin.ignore();


    if (remove(fileName.c_str()) != 0)
        cout << "Error closing account. Please contact customer service.";
    else {
        cout << "Account successfully closed";
        mainMenu();
    }
}

/*********************************************************************
** Description:     delete customer account by deleting file
*********************************************************************/
void BankApp::viewUserData() {
    // Display banner and menu with raw strings
    cout << BOLDYELLOW;
    std::cout << R"(

 　        ▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬▬▬▬ USER INFO ▬▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬
            )" << '\n';
    cout << RESET << endl;

    cout << "           Account Number: " << getAccountNumber() << endl;
    cout << "           Your username: " << getUsername() << endl;
    cout << "           Your PIN #: " << getPin() << endl;
}

/*********************************************************************
** Description:     update the user's account (username and pin)
*********************************************************************/
void BankApp::updateAccount() {
    char go{'N'};
    int selection{0};

    cout << "Let's update your account." << endl;
    do {
        cout << "1. Change your username\n";
        cout << "2. Change your pin number\n\n";
        cout << "Enter Selction: ";
        cin >> selection;
        cin.ignore();

        switch (selection) {
            case 1: {
                // have user create username
                string newUserName;
                cout << "Create a new username between 4 and 10 alphanumeric characters: ";
                getline(cin, newUserName);
                // username validation using regex
                std::regex usernamePattern("[a-zA-Z0-9]{4,10}");
                std::smatch m;

                while (!std::regex_match(newUserName, m , usernamePattern)) {
                    cout << "\nError! Create a username between 4 and 10 alphanumeric characters and no spacing: ";
                    cin >> newUserName;
                }
                setUsername(newUserName);

                break;
            }
            case 2: {
                // have user create a new 4 digit pin
                string newPIN;
                cout << "Create a 4 digit pin (0-9): ";
                cin >> newPIN;

                // pin validation using regex
                std::regex pinPattern("[0-9]{4}");
                std::smatch n;
                while (!std::regex_match(newPIN, n, pinPattern)) {
                    cout << "Error! Create a pin 4 characters lond and no spacing: ";
                    cin >> newPIN;
                }
                break;
            }
            default:
                cout << "Please select 1 or 2, try again" << endl;
        }

        cout << "Would you like to update your info again? y/n " << endl;
        cin.get(go);

        // if user is done updating their info, go to submenu
        if (toupper(go) != 'Y')
            subMenu();

    } while (toupper(go) == 'Y');
}