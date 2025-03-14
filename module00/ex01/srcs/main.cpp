/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:06:00 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/12 05:31:31 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

// #include <fstream>
// #include <sstream>

// void loadTest(PhoneBook& phoneBook, const std::string& filename) {
// 	std::ifstream file(filename);
// 	if (!file) {
// 		std::cerr << "Error: Could not open test data file: " << filename << std::endl;
// 		return;
// 	}

// 	std::string line;
// 	while (std::getline(file, line)) {
// 		std::stringstream ss(line);
// 		std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

// 		if (std::getline(ss, firstName, ',') &&
// 			std::getline(ss, lastName, ',') &&
// 			std::getline(ss, nickname, ',') &&
// 			std::getline(ss, phoneNumber, ',') &&
// 			std::getline(ss, darkestSecret, ',')) {
// 			phoneBook.addTest(firstName, lastName, nickname, phoneNumber, darkestSecret);
// 		}
// 	}
// 	file.close();
// 	std::cout << "Test data loaded from " << filename << std::endl;
// }

int	main(void) {
	PhoneBook	phoneBook;
	std::string	command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		checkEOF(std::cin);
		command = trim(command);

		if (command == "ADD") {
			phoneBook.add();
		} else if (command == "SEARCH") {
			phoneBook.search();
		} else if (command == "EXIT") {
			std::cout << "Goodbye!" << std::endl;
			break ;
		} else {
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
		}
	}
}
