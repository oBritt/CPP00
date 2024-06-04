
#include <iostream>
#include "Account.hpp"
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int deposit): _amount(deposit), _nbDeposits(0), _nbWithdrawals(0){
	this->_accountIndex = getNbAccounts();
	_nbAccounts++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<";";
	std::cout << "amount:" << deposit << ";created" << std::endl;
	return;
};

Account::~Account()
{
	_displayTimestamp();
	_totalAmount -= this->_amount;
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";closed" << std::endl;
	return ;
}

int Account::getNbAccounts(void){
	return _nbAccounts;
}

int Account::getTotalAmount(void){
	return _totalAmount;
}

int Account::getNbDeposits(void){
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void){
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:"
	<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    int year = now->tm_year + 1900;
    int month = now->tm_mon + 1;
    int day = now->tm_mday;
    int hour = now->tm_hour;
    int minute = now->tm_min;
    int second = now->tm_sec;

    std::cout << "["
              << year
              << (month < 10 ? "0" : "") << month
              << (day < 10 ? "0" : "") << day << "_"
              << (hour < 10 ? "0" : "") << hour
              << (minute < 10 ? "0" : "") << minute
              << (second < 10 ? "0" : "") << second << "] ";

    return ;
}

int	Account::checkAmount(void) const{
	return this->_amount;
}

void Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:"
	<< this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
	<< ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	bool ans;
	ans = (withdrawal <= checkAmount()) ? true : false;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawals:";
	if (ans)
	{
		std::cout << withdrawal;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	else{
		std::cout << "refused" << std::endl;
	}
	return (ans);
}