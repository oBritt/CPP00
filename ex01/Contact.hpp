
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact{

private:
	int			index;
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string secret;

public:
	Contact(void);
	Contact(int ind, std::string first, std::string last, std::string nick, std::string phone, std::string secret);
	~Contact(void);
	int	getInd(void) const;
	std::string getFirst(void) const;
	std::string getLast(void) const;
	std::string getNick(void) const ;
	std::string getPhone(void) const ;
	std::string getSecret(void) const ;
};


#endif