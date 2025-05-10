/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:34:31 by shonakam          #+#    #+#             */
/*   Updated: 2025/05/10 15:49:05 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

void	testLargeRange() {
	int					max = 10000;
	std::vector<int>	v;
	Span				sp(max * 2);

	for (int i = -max; i < max; ++i) { v.push_back(i); }
	sp.addRange(v.begin(), v.end());

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // 1
	std::cout << "Longest span : " << sp.longestSpan() << std::endl;  // 19999
}

void	testSame() {
	Span	sp(5);

	for (int i = 0; i < 5; ++i) sp.addNumber(42);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // 0
	std::cout << "Longest span : " << sp.longestSpan() << std::endl;  // 0
}

void testException() {
	unsigned int max = 3;
	Span	sp(max);

	sp.addNumber(1);
	try {
		sp.shortestSpan();
	} catch (std::exception& e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	try {
		sp.longestSpan();
	} catch (std::exception& e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	sp.addNumber(2);
	sp.addNumber(3);

	try {
		sp.addNumber(4);
	} catch (std::exception& e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
}

void testZero() {
	try {
		Span sp(0);
		sp.addNumber(1);
	} catch (std::exception& e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
}

void	testHandler(void) {
	std::cout << "=== TEST HANDLER ===" << std::endl;
	testLargeRange();
	testSame();
	testException();
	testZero();
}

// used container -> vector
int main()
{
	// Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	testHandler();
	return 0;
}