/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     Checkings class implementation file
*********************************************************************/
#include "Checkings.hpp"

/*********************************************************************
** Description:     1-arg constructor
*********************************************************************/
Checkings::Checkings(double deposit)
        : checkingsBalance{deposit} {
}

/*********************************************************************
** Description:     setter function for checkings balance
*********************************************************************/
void Checkings::loadBalance(double amount) {
    checkingsBalance = amount;
}

/*********************************************************************
** Description:     getter function for checkings balance
*********************************************************************/
double Checkings::getCheckingsBalance() {
    return checkingsBalance;
}