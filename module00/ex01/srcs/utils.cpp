/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:11:17 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/12 04:28:21 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string trim(const std::string& str) {
	size_t first = str.find_first_not_of(" \t\v\f\r\n");
	size_t last = str.find_last_not_of(" \t\v\f\r\n");
	return (first == std::string::npos) ? "" : str.substr(first, last - first + 1);
}

std::string strShorten(const std::string &str, unsigned int from) {
	return (str.length() > from + 1) ? str.substr(0, from) + "." : str;
}

void	checkEOF(std::istream& in) {
	if (in.eof()) {
		std::cout << "\nEOF detected. Bye...\n";
		exit(0);
	}
}
