/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:48:30 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/15 22:10:20 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

#include <cassert>
#define TEST(expr) std::cout << #expr << " = " << (expr) << std::endl;
void testConstructors() {
    std::cout << "\n===== Constructor Tests =====" << std::endl;
    Fixed a; Fixed b(5); Fixed c(3.14f); Fixed d(b); Fixed e = c;

    TEST(a); TEST(b); TEST(c); TEST(d); TEST(e);
}

void testArithmeticOperators() {
    std::cout << "\n===== Arithmetic Operators Tests =====" << std::endl;
    Fixed a(2.5f), b(1.5f);

    TEST(a + b); TEST(a - b); TEST(a * b); TEST(a / b); TEST(a / Fixed(0));
}

void testComparisonOperators() {
    std::cout << "\n===== Comparison Operators Tests =====" << std::endl;
    Fixed a(2.0f), b(3.0f);

    TEST(a < b); TEST(a > b); TEST(a <= b); TEST(a >= b); TEST(a == b); TEST(a != b);
}

void testIncrementDecrement() {
    std::cout << "\n===== Increment/Decrement Tests =====" << std::endl;
    Fixed a(1.0f);

    TEST(++a); TEST(a++); TEST(a); TEST(--a); TEST(a--); TEST(a);
}

void testMinMax() {
    std::cout << "\n===== Min/Max Tests =====" << std::endl;
    Fixed a(5.0f), b(3.0f); const Fixed c(2.5f), d(4.5f);

    TEST(Fixed::min(a, b)); TEST(Fixed::max(a, b)); TEST(Fixed::min(c, d)); TEST(Fixed::max(c, d));
}

void testIO() {
    std::cout << "\n===== I/O Test =====" << std::endl;
    Fixed a(3.14159f);
    std::cout << "Fixed a: " << a << std::endl;
}

void runAllTests() {
    testConstructors();
    testArithmeticOperators();
    testComparisonOperators();
    testIncrementDecrement();
    testMinMax();
    testIO();
}

int	main(void) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	// runAllTests();
}
