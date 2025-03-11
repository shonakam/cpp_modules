/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:52:10 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/12 04:19:11 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void) {}
Contact::~Contact(void) {}

void	Contact::setAll(
	std::string firstName,
	std::string lastName,
	std::string nickname,
	std::string phoneNumber,
	std::string darkestSecret
) {
	_firstName = firstName;
	_lastName = lastName;
	_nickname = nickname;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName() const { return _firstName; }
std::string	Contact::getLastName() const { return _lastName; }
std::string	Contact::getNickname() const { return _nickname; }
std::string	Contact::getPhoneNumber() const { return _phoneNumber; }
std::string	Contact::getDarkestSecret() const { return _darkestSecret; }

bool	Contact::isEmpty() const { return _firstName.empty(); }

