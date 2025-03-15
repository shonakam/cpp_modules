/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:28:07 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/15 15:01:12 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) {
	std::cout << GREEN << "[call]" << RESET;
	std::cout << ": default constructor" << std::endl;
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

Fixed::Fixed(const int intValue) {
	std::cout << GREEN << "[call]" << RESET;
	std::cout << ": Int constructor" << std::endl;

	_fixed = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	std::cout << GREEN << "[call]" << RESET;
	std::cout << ": Float constructor" << std::endl;

	_fixed = roundf(floatValue * (0b1 << _fractionalBits));
}

Fixed::~Fixed() {
	std::cout << GREEN << "[call]" << RESET;
	std::cout << ": destructor" << std::endl;
}

int		Fixed::getRawBits(void) const { return this->_fixed; }
void	Fixed::setRawBits(const int raw) { this->_fixed = raw; }

float	Fixed::toFloat(void) const { return (float)_fixed / (1 << _fractionalBits); }
int		Fixed::toInt(void) const { return _fixed >> _fractionalBits; }

/* OVERLOAD */
std::ostream	&operator<<(std::ostream &os, const Fixed &fixed) {
	return os << fixed.toFloat();
}
