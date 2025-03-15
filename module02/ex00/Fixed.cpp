/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:28:07 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/14 13:55:52 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) {
	std::cout << GREEN << "[call]" << RESET;
	std::cout << ": default constructor" << std::endl;
}

Fixed::~Fixed() {
	std::cout << GREEN << "[call]" << RESET;
	std::cout << ": destructor" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << GREEN << "[call]" << RESET;
	std::cout << ": copy constructor" << std::endl;

	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other) {
	std::cout << GREEN << "[call]" << RESET;
	std::cout << ": copy assignment operator" << std::endl;

	if (this != &other) this->_fixed = other.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const {
	std::cout << GREEN << "[call]" << RESET;
	std::cout << ": getRawBits member function" << std::endl;

	return this->_fixed;
}

void	Fixed::setRawBits(const int raw) {
	std::cout << GREEN << "[call]" << RESET;
	std::cout << ": setRawBits member function" << std::endl;
	this->_fixed = raw;
}

