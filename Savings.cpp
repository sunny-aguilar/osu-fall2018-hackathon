/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     Savings class implementation file
*********************************************************************/
#include "Savings.hpp"

/*********************************************************************
** Description:     1-arg constructor
*********************************************************************/
Savings::Savings(double deposit)
        : savingsBalance{deposit} {
}

/*********************************************************************
** Description:     setter function for savings balance
*********************************************************************/
void Savings::loadBalance(double amount) {
    savingsBalance = amount;
}

/*********************************************************************
** Description:     getter function for savings balance
*********************************************************************/
double Savings::getSavingsBalance() {
    return savingsBalance;
}
