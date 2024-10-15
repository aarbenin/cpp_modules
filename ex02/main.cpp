#include <iostream>
#include "Account.hpp"

int main()
{
    Account acc(100);
    acc.makeDeposit(50);
    acc.makeWithdrawal(70);
    acc.makeWithdrawal(150);
    acc.makeDeposit(50);
    acc.makeWithdrawal(70);
    acc.displayStatus();
}