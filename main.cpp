/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     OSU banking app
*********************************************************************/
#include "BankApp.hpp"
#include "Checkings.hpp"
#include "Savings.hpp"
#include "Transactions.hpp"
#include "ViewAccount.hpp"
#include <iostream>

int main() {
    BankApp bank;                               // create bank object
    bank.introScreen();                         // show intro screen
    bank.mainMenu();

    return 0;
}