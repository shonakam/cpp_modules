/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:31:27 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/13 17:25:51 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <cctype>
#include <cfloat>

// == OCCF ====================================================================

Conversion::Conversion(void) {
	std::cout << "Default constructor called" << std::endl;
}

Conversion::Conversion(const Conversion &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Conversion::~Conversion(void) {
	std::cout << "Destructor called" << std::endl;
}

Conversion	&Conversion::operator=(const Conversion &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) { }
	return (*this);
}

// == Member Functions ========================================================

bool	_isPseudoLiteral(const std::string &literal) {
	return	(
		literal == "nan" || literal == "nanf"
		|| literal == "+inf" || literal == "+inff"
		|| literal == "-inf" || literal == "-inff"
		|| literal == "inf" || literal == "inff"
	);
}

bool	Conversion::_isChar(const std::string &literal) {
	return (
		literal.length() == 3
		&& literal[0] == '\''
		&& literal[2] == '\''
		&& std::isprint(literal[1])
	);
}

bool	Conversion::_isInt(const std::string &literal) {
	std::istringstream	iss(literal);
	long				value = 0;
	char				c;

	// Check for leading/trailing whitespace
	// Check for overflow/underflow
	if (!(iss >> value) || (iss >> c)) return (false);
	if (value > std::numeric_limits<int>::max()
		|| value < std::numeric_limits<int>::min()) return (false);
	return (true);
}

bool	Conversion::_isFloat(const std::string &literal) {
	if (literal.empty() || literal[literal.size() - 1] != 'f') return (false);
	std::string			withoutF = literal.substr(0, literal.size() - 1);
	std::istringstream	iss(withoutF);
	double				dValue = 0;
	char				c;

	if (!(iss >> dValue) || (iss >> c)) return (false);
	if (dValue != 0.0
		&& (dValue > std::numeric_limits<float>::max()
		|| dValue < std::numeric_limits<float>::min()))
		return (false);
	return (true);
}

bool	Conversion::_isDouble(const std::string &literal) {
	std::istringstream iss(literal);
	double			value = 0;
	char			c;

	if (!(iss >> value)) return (false);
	if (iss >> c) return (false);
	if (value != 0.0
		&& (value > std::numeric_limits<double>::max()
		|| value < std::numeric_limits<double>::min()))
		return (false);
	return (true);
}

void	Conversion::convert(const std::string &literal) {
	if (_isChar(literal)) {
		std::cout << std::fixed << std::setprecision(1);

		std::cout << "char: '" << literal[1] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[1]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[1]) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(literal[1]) << std::endl;
		return ;
	}

	if (_isInt(literal)) {
		int		iValue = std::atoi(literal.c_str());
		std::cout << std::fixed << std::setprecision(1);

		std::cout << "char: ";
		if (iValue < 0 || iValue > 127) std::cout << "impossible" << std::endl;
		else if (std::isprint(iValue)) std::cout << "'" << static_cast<char>(iValue) << "'" << std::endl;
		else std::cout << "Non displayable" << std::endl;

		std::cout << "int: " << iValue << std::endl;
		std::cout << "float: " << static_cast<float>(iValue) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(iValue) << std::endl;
		return ;
	}

	if (_isFloat(literal)) {
		float		fValue = std::atof(literal.c_str());
		std::cout << std::fixed << std::setprecision(1);

		std::cout << "char: ";
		if (fValue < 0 || fValue > 127) std::cout << "impossible" << std::endl;
		else if (std::isprint(static_cast<int>(fValue)))
			std::cout << "'" << static_cast<char>(fValue) << "'" << std::endl;
		else std::cout << "Non displayable" << std::endl;

		std::cout << "int: ";
		if (fValue < std::numeric_limits<int>::min() || fValue > std::numeric_limits<int>::max())
			std::cout << "impossible" << std::endl;
		else std::cout << static_cast<int>(fValue) << std::endl;

		std::cout << "float: " << fValue << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(fValue) << std::endl;
		return ;
	}

	if (_isDouble(literal)) {
		double		dValue = std::atof(literal.c_str());
		std::cout << std::fixed << std::setprecision(1);

		std::cout << "char: ";
		if (dValue < 0 || dValue > 127) std::cout << "impossible" << std::endl;
		else if (std::isprint(static_cast<int>(dValue)))
			std::cout << "'" << static_cast<char>(dValue) << "'" << std::endl;
		else std::cout << "Non displayable" << std::endl;

		std::cout << "int: ";
		if (dValue < std::numeric_limits<int>::min() || dValue > std::numeric_limits<int>::max())
			std::cout << "impossible" << std::endl;
		else std::cout << static_cast<int>(dValue) << std::endl;

		std::cout << "float: " << static_cast<float>(dValue) << "f" << std::endl;
		std::cout << "double: " << dValue << std::endl;
		return ;
	}

	if (_isPseudoLiteral(literal)) {
		std::cout << std::fixed << std::setprecision(1);

		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;

		// Handle special cases for float and double
		if (literal == "nanf" || literal == "nan") {
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		} else if (literal == "+inf" || literal == "+inff"
			|| literal == "inf" || literal == "inff") {
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		} else if (literal == "-inff" || literal == "-inf") {
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		return ;
	}
	std::cout	<< YELLOW << "[WARN]" << RESET
				<< ": Invalid literal" << std::endl;
}
