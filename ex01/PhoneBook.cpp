
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void): len(0){
	return ;
}

PhoneBook::~PhoneBook(void){
	//std::cout << "deconstractor" << std::endl;
	return ;
}

void PhoneBook::loop(void)
{
	std::string input;
	stop = 0;
	while (!stop)
	{
		std::cout << "Allowed commands are: 'ADD' 'SEARCH' and 'EXIT' " << std::endl << std::endl;
		std::cout << "   ->";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			stop = 1;
			break;
		}
		if (input == "ADD")
			this->add();
		else if (input == "SEARCH")
			this->search();
		else if (input == "EXIT")
			break;
		else
			std::cout << std::endl << std::endl;
	}
	return;
}

std::string PhoneBook::modify(std::string str) const{
	std::string stri = "";
	if (str.size() > 10)
	{
		stri = str.substr(0, 10);
		stri[9] = '.';
		return (stri);
	}
	else if (str.size() == 10)
		return (str);
	else
	{
		for (int i = 0; i < 10 - (int)str.size(); i++){
			stri += " ";
		}
		stri += str;
		return (stri);
	}
}

bool PhoneBook::is_allowed(std::string str) const
{
	if (str.size() == 0)
		return false;
	for (int i = 0; i < (int)str.size(); i++)
		if (!isdigit(str[i]))
			return false;
	return true;
}

void PhoneBook::add(void){
	std::string first_name = "";
	std::string last_name = "";
	std::string nickname = "";
	std::string phonenumber = "";
	std::string secret = "";

	while ( (first_name == ""))
	{
		std::cout << "Input your first name: ";
		std::getline(std::cin, first_name);
		if (std::cin.eof())
		{
			stop= 1;
			return ;
		}
	}
	while (last_name == "")
	{
		std::cout << "Input your last name: ";
		std::getline(std::cin, last_name);
		if (std::cin.eof())
		{
			stop= 1;
			return ;
		}
	}
	while (nickname == "")
	{
		std::cout << "Input your nickname: ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
		{
			stop= 1;
			return ;
		}
	}
	while (true)
	{
		std::cout << "Input your phone number: +";
		std::getline(std::cin, phonenumber);
		if (std::cin.eof())
		{
			stop= 1;
			return ;
		}
		if (this->is_allowed(phonenumber))
			break ;
		std::cout << std::endl << "Only digits are allowed" << std::endl;
	}
	while (secret == "")
	{
		std::cout << "Input your secret: ";
		std::getline(std::cin, secret);
		if (std::cin.eof())
		{
			stop= 1;
			return ;
		}
	}
	if (this->len != 8)
	{
		this->contacts[this->len].~Contact();
		new (&(this->contacts[this->len])) Contact(this->len + 1, first_name, last_name, nickname, secret, phonenumber);
		this->len++;
	}
	else
	{
		this->contacts[0].~Contact();
		for (int i = 1; i < 8; i++)
			this->contacts[i - 1] = this->contacts[i];
		new (&this->contacts[7]) Contact(this->contacts[6].getInd() == 8 ? 1 : this->contacts[6].getInd() + 1 \
		, first_name, last_name, nickname, secret, phonenumber);
	}
}

void PhoneBook::search(void){
	if (this->len != 0)
		{
		std::cout << std::string(45, '-') << std::endl;
		std::cout << '|' << this->modify("index") << '|' << this->modify("first name") << "|" << this->modify("last name") << "|" << this->modify("nickname") << "|" << std::endl;
		int	ind = 0;
		std::cout << std::string(45, '-') << std::endl;
		while (ind < this->len)
		{
			if (this->contacts[ind].getInd() == 1)
				break ;
			ind++;
		}
		for (int i = ind; i < this->len; i++)
		{
			std::cout << '|' << this->modify(std::to_string(this->contacts[i].getInd())) << '|' << this->modify(this->contacts[i].getFirst()) << \
				"|" << this->modify(this->contacts[i].getLast()) << "|" << this->modify(this->contacts[i].getNick()) << "|" << std::endl;
			std::cout << std::string(45, '-') << std::endl;
		}
		for (int i = 0; i < ind; i++)
		{
			std::cout << '|' << this->modify(std::to_string(this->contacts[i].getInd())) << '|' << this->modify(this->contacts[i].getFirst()) << \
				"|" << this->modify(this->contacts[i].getLast()) << "|" << this->modify(this->contacts[i].getNick()) << "|" << std::endl;
			std::cout << std::string(45, '-') << std::endl;
		}
		while (true)
		{
			std::string str = "";
			while (str == "")
			{
				std::cout << "Input index you want get information about :";
				std::getline(std::cin, str);
				if (std::cin.eof())
				{
					stop = 1;
					break ;
				}
			}
			if (this->is_allowed(str))
			{
				int ind = stoi(str);
				if (ind >= 1 && ind <= this->len)
				{
					for (int i = 0; i < this->len; i++)
					{
						if (contacts[i].getInd() == ind)
						{
							std::cout << "Information about index " << ind << std::endl;
							std::cout << "First name: " << contacts[i].getFirst() << std::endl;
							std::cout << "Last name: " << contacts[i].getLast() << std::endl;
							std::cout << "Nick name: " << contacts[i].getNick() << std::endl;
							std::cout << "Phone: " << contacts[i].getPhone() << std::endl;
							std::cout << "Secret: " << contacts[i].getSecret() << std::endl;
							std::cout << std::endl << std::endl;
							break;
						}
					}
					break;
				}
			}
			std::cout << std::endl << "Wrong index" << std::endl;
		}
	}
	else
		std::cout << "Nothing to display" << std::endl;
	return ;
}
