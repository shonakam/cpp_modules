/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:51:50 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/14 13:12:33 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string trim(const std::string& str) {
	size_t first = str.find_first_not_of(" \t\v\f\r\n");
	size_t last = str.find_last_not_of(" \t\v\f\r\n");
	return (first == std::string::npos) ? "" : str.substr(first, last - first + 1);
}

int	main() {
	Harl	harl;
	std::string	level;

	while (true) {
		std::cout << "Please enter LEVEL (DEBUG, INFO, WARNING, ERROR):";
		getline(std::cin, level);
		level = trim(level);
		if (std::cin.eof()) {
			std::cout << "EOF detected. Bye..." << std::endl;
			break ;
		}
		harl.complain(level);
	}
}
