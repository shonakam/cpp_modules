/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:44:26 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/26 22:03:36 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

void	testSWAP() {
	int a = 5, b = 10;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	ft::swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
}

void	testMIN() {
	double x = 3.14, y = 2.71;
	std::cout << "min(x, y) = " << ft::min(x, y) << std::endl;
}

void	testMAX() {
	std::string str1 = "apple", str2 = "banana";
	std::cout << "max(str1, str2) = " << ft::max(str1, str2) << std::endl;

	char char1 = 'z', char2 = 'a';
	std::cout << "max(char1, char2) = " << ft::max(char1, char2) << std::endl;
}

int main(void) {

	{
		int a = 2;
		int b = 3;

		ft::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ft::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ft::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		ft::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ft::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ft::max( c, d ) << std::endl;
	}
	testSWAP();
	testMIN();
	testMAX();
}
