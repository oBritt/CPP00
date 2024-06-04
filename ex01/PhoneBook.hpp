/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:59:06 by obrittne          #+#    #+#             */
/*   Updated: 2024/05/27 19:00:06 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>

class PhoneBook{
private:
	int	len;
	Contact contacts[8];
	int	stop;

	void search(void);
	std::string modify(std::string str) const;
	void add(void);
	bool is_allowed(std::string str) const;

public:
	PhoneBook(void);
	~PhoneBook(void);
	void loop(void);

};


#endif