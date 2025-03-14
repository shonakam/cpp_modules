/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:15:59 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/12 13:39:27 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << std::endl;
	std::cout << "Memory Address of str      : " << &str << std::endl;
	std::cout << "Memory Address in stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory Address in stringREF: " << &stringREF << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "Value of str      : " << str << std::endl;
	std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value referenced by stringREF: " << stringREF << std::endl;
	std::cout << std::endl;
}