#include "Account.hpp"

#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";created" << std::endl;
}
Account::~Account()
{
    _nbAccounts--;
    _totalAmount -= _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
              << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int previous_amount = _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << previous_amount
              << ";deposit:" << deposit << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int previous_amount = _amount;

    if (withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
                  << ";p_amount:" << previous_amount << ";withdrawal:refused"
                  << std::endl;
        return false;
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << previous_amount
              << ";withdrawal:" << withdrawal << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;

    return true;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}
void Account::_displayTimestamp()
{
    time_t now = time(0);
    tm    *ltm = localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year << std::setfill('0') << std::setw(2)
              << 1 + ltm->tm_mon << std::setw(2) << ltm->tm_mday << "_"
              << std::setw(2) << ltm->tm_hour << std::setw(2) << ltm->tm_min
              << std::setw(2) << ltm->tm_sec << "] ";
}
int Account::getNbAccounts()
{
    return Account::_nbAccounts;
}
int Account::getTotalAmount()
{
    return Account::_totalAmount;
}
int Account::getNbDeposits()
{
    return Account::_totalNbDeposits;
}
int Account::getNbWithdrawals()
{
    return Account::_totalNbWithdrawals;
}
void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
