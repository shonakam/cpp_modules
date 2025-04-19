/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:44:26 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/19 22:12:12 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

void	testSWAP() {
	int a = 5, b = 10;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
}

void	testMIN() {
	double x = 3.14, y = 2.71;
	std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
}

void	testMAX() {
	std::string str1 = "apple", str2 = "banana";
	std::cout << "max(str1, str2) = " << ::max(str1, str2) << std::endl;

	char char1 = 'z', char2 = 'a';
	std::cout << "max(char1, char2) = " << ::max(char1, char2) << std::endl;
}

int main(void) {

	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	testSWAP();
	testMIN();
	testMAX();
}
