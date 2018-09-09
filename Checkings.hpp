/*********************************************************************
** Author:          Sandro Aguilar, Kuljot Biring and Christian Martinez
** Date:            September 6, 2018
** Description:     Checkings class specification file
*********************************************************************/
#ifndef CHECKINGS_HPP
#define CHECKINGS_HPP

class Checkings {
    private:
        double checkingsBalance;

    public:
        Checkings(double deposit);  //1-arg constructor
        void loadBalance(double amount);
        double getCheckingsBalance();
};

#endif                              // end of preprocessor directive
