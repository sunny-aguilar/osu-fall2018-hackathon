/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     BankingApp class implementation file
*********************************************************************/
#include <iostream>
#include "BankApp.hpp"

void BankApp::introScreen() {
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

        ██████╗  █████╗ ███╗   ██╗██╗  ██╗
        ██╔══██╗██╔══██╗████╗  ██║██║ ██╔╝
        ██████╔╝███████║██╔██╗ ██║█████╔╝
        ██╔══██╗██╔══██║██║╚██╗██║██╔═██╗
        ██████╔╝██║  ██║██║ ╚████║██║  ██╗
        ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝
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
                    bank.logIn();
                }
                    break;

                case 'A':
                {
                    bank.createAccount();
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
