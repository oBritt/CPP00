
#include "Contact.hpp"
#include <iostream>

Contact::Contact(void)
{
	return;
}

Contact::Contact(int ind, std::string first, std::string last, std::string nick, std::string phone, std::string secret) : \
index(ind), firstname(first), lastname(last), nickname(nick), phonenumber(phone), secret(secret){
	return ;
}

Contact::~Contact(void)
{
	// std::cout << "Decontructed" << std::endl;
	return;
}

int	Contact::getInd(void) const {
	return this->index;
}

std::string Contact::getFirst(void) const
{
	return this->firstname;
}

std::string Contact::getLast(void) const
{
	return this->lastname;
}

std::string Contact::getNick(void) const
{
	return this->nickname;
}

std::string Contact::getPhone(void) const
{
	return this->phonenumber;
}

std::string Contact::getSecret(void) const
{
	return this->secret;
}