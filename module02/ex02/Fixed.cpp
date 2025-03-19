/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:28:07 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 14:31:02 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void	Fixed::_calledLog(const std::string &target) {
	std::cout << GREEN << "[call]" << RESET << target << std::endl;
}

Fixed::Fixed() : _fixed(0) { _calledLog(": default constructor"); }

Fixed::Fixed(const Fixed &other) : _fixed(other._fixed) { _calledLog(": copy constructor"); }

Fixed	&Fixed::operator=(const Fixed &other) {
	_calledLog(": copy assignment operator");
	if (this != &other) this->_fixed = other.getRawBits();
	return *this;
}

Fixed::Fixed(const int intValue) {
	_calledLog(": Int constructor");
	_fixed = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	_calledLog(": Float constructor");
	_fixed = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::~Fixed() { _calledLog(": destructor"); }

int		Fixed::getRawBits(void) const { return this->_fixed; }
void	Fixed::setRawBits(const int raw) { this->_fixed = raw; }

float	Fixed::toFloat(void) const { return (float)_fixed / (1 << _fractionalBits); }
int		Fixed::toInt(void) const { return _fixed >> _fractionalBits; }

/* OVERLOADS: comparison operators */
bool	Fixed::operator>(const Fixed &other) const { return this->_fixed > other.getRawBits(); }
bool	Fixed::operator<(const Fixed &other) const { return this->_fixed < other.getRawBits(); }
bool	Fixed::operator>=(const Fixed &other) const { return this->_fixed >= other.getRawBits(); }
bool	Fixed::operator<=(const Fixed &other) const { return this->_fixed <= other.getRawBits(); }
bool	Fixed::operator==(const Fixed &other) const { return this->_fixed == other.getRawBits(); }
bool	Fixed::operator!=(const Fixed &other) const { return this->_fixed != other.getRawBits(); }

/* OVERLOADS: arithmetic operators */
Fixed	Fixed::operator+(const Fixed &other) const { return Fixed(toFloat() + other.toFloat()); }
Fixed	Fixed::operator-(const Fixed &other) const { return Fixed(toFloat() - other.toFloat()); }
Fixed	Fixed::operator*(const Fixed &other) const { return Fixed(this->toFloat() * other.toFloat()); }
// https://en.wikipedia.org/wiki/IEEE_754#Exception_handling
Fixed	Fixed::operator/(const Fixed &other) const {
	if (other.getRawBits() != 0) return Fixed(this->toFloat() / other.toFloat());
	std::cerr << RED << "[ERROR]" << RESET << "division by zero. returning 0 instead." << std::endl;
	return Fixed(0);
}

/* OVERLOADS: increment and decrement operators */
Fixed		&Fixed::operator++(void) { return (this->_fixed += 1, *this); }
Fixed		&Fixed::operator--(void) { return (this->_fixed -= 1, *this); }
Fixed		Fixed::operator++(int) { const Fixed tmp(*this); return (this->_fixed += 1, tmp); }
Fixed		Fixed::operator--(int) { const Fixed tmp(*this); return (this->_fixed -= 1, tmp); }

Fixed		&Fixed::min(Fixed &u, Fixed &v) { return (u < v) ? u : v; }
Fixed		&Fixed::max(Fixed &u, Fixed &v) { return (u > v) ? u : v; }
const Fixed	&Fixed::min(const Fixed &u, const Fixed &v) { return (u < v) ? u : v; }
const Fixed	&Fixed::max(const Fixed &u, const Fixed &v) { return (u > v) ? u : v; }

/* OVERLOAD I/O */
std::ostream	&operator<<(std::ostream &os, const Fixed &fixed) { return os << fixed.toFloat(); }
