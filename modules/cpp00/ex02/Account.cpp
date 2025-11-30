#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>


// why : A static data member belongs to the class itself, not to any single object instance.
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp() {
    std::time_t t = std::time(NULL);
    char buf[20];

    std::strftime(buf, 20, "[%Y%m%d_%H%M%S] ", std::localtime(&t));
    std::cout << buf;
}

Account::Account() :
	_accountIndex(0),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
    // private: not used by tests, but defined to satisfy the declaration
}

Account::Account( int initial_deposit ) :
    _accountIndex(Account::_nbAccounts),
    _amount(initial_deposit),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account() {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;

    Account::_nbAccounts -= 1;  // or   --Account::_nbAccounts; optional
}

// static getters
int Account::getNbAccounts() {
	return Account::_nbAccounts;
}
int Account::getTotalAmount() {
	return Account::_totalAmount;
}
int Account::getNbDeposits() {
	return Account::_totalNbDeposits;
}
int Account::getNbWithdrawals() {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts()
              << ";total:" << Account::getTotalAmount()
              << ";deposits:" << Account::getNbDeposits()
              << ";withdrawals:" << Account::getNbWithdrawals()
			  << std::endl;
}

void Account::makeDeposit( int deposit ) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    std::cout << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits
              << std::endl;
}


bool Account::makeWithdrawal( int withdrawal ) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";withdrawal:";
    if (withdrawal > this->_amount) {
        std::cout << "refused" << std::endl;
        return false;
    } else {
        this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
        this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
        std::cout << withdrawal
                  << ";amount:" << this->_amount
                  << ";nb_withdrawals:" << this->_nbWithdrawals
                  << std::endl;
        return true;
    }
}

int Account::checkAmount() const {
    return this->_amount;
}

void Account::displayStatus() const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}

