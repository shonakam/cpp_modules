/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:30:11 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/12 05:10:43 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) { return ; }
PhoneBook::~PhoneBook(void) { return ; }

void	PhoneBook::shiftContact(Contact contacts[], const Contact& newContact) {
	for (int i = 0; i < MAX_CONTACTS - 1; i++) {
		contacts[i] = contacts[i + 1];
	}
	contacts[7] = newContact;
}

void	PhoneBook::printList(void) const {
	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "|\n";
	std::cout << "--------------------------------------------\n";
	for (int i = 0; i < MAX_CONTACTS; i++) {
		if (!_contacts[i].isEmpty()) {
			std::cout << std::setw(10) << i + 1 << "|"
					<< std::setw(10) << strShorten(_contacts[i].getFirstName()) << "|"
					<< std::setw(10) << strShorten(_contacts[i].getLastName()) << "|"
					<< std::setw(10) << strShorten(_contacts[i].getNickname()) << "|\n";
		}
	}
}

void	PhoneBook::printDetails() const {
	std::string	input;

	while (true) {
		std::cout << "Enter index (1-8) to view details: ";
		std::getline(std::cin, input);
		checkEOF(std::cin);

		int index = std::atoi(trim(input).c_str());
		if (index >= 1 && index <= 8) {
			index--;
			if (!_contacts[index].isEmpty()) {
				std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
				std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
				std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
				std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
				std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
			} else {
				std::cout << RED << "No contact found at index " << index + 1 << ".\n" << RESET;
			}
			return ;
		} else {
			std::cout << YELLOW << "Invalid input. Please enter a number between 1 and 8.\n" << RESET;
		}
	}
}

/* 
* An empty string does not interrupt processing,
* but trims both before and after it.
*/
std::string	PhoneBook::getInformation(const std::string& prompt) {
	std::string	input;

	std::cout << prompt;
	while (true) {
		std::getline(std::cin, input);
		checkEOF(std::cin);
		input = trim(input);
		if (input.empty()) {
			std::cout << ERR_EMPTY_INPUT << prompt;
			continue;
		}
		if (prompt == "Enter phone number: ") {
			bool valid = true;
			for (size_t i = 0; i < input.size(); i++) {
				if (!std::isdigit(input[i])) {
					valid = false;
					break;
				}
			}
			if (!valid) {
				std::cout << ERR_INVALID_PHONE << prompt;
				continue;
			}
		}
		return input;
	}
}


void	PhoneBook::add() {
	Contact	contact;

	contact.setAll(
		getInformation("Enter first name: "),
		getInformation("Enter last name: "),
		getInformation("Enter nickname: "),
		getInformation("Enter phone number: "),
		getInformation("Enter darkest secret: ")
	);
	for (int i = 0; i < MAX_CONTACTS; i++) {
		if (_contacts[i].isEmpty()) {
			_contacts[i] = contact;
			return ;
		}
	}
	shiftContact(_contacts, contact);
}

// void PhoneBook::addTest(
// 	const std::string& firstName,
// 	const std::string& lastName,
// 	const std::string& nickname,
// 	const std::string& phoneNumber,
// 	const std::string& darkestSecret)
// {
// 	Contact contact;
// 	contact.setAll(firstName, lastName, nickname, phoneNumber, darkestSecret);
// 	for (int i = 0; i < MAX_CONTACTS; i++) {
// 		if (_contacts[i].isEmpty()) {
// 			_contacts[i] = contact;
// 			return ;
// 		}
// 	}
// 	shiftContact(_contacts, contact);
// }

void	PhoneBook::search() const {
	std::string	input;
	if (_contacts[0].isEmpty()) {
		std::cout << "Phonebook is empty. Add contacts first.\n";
		return ;
	}
	printList();
	printDetails();
}
