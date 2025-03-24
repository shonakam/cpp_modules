/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:51:05 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/25 00:02:30 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/AMateria.hpp"

AMateria::AMateria(void): _type("") { std::cout << "AMateria:	has been created!" << std::endl; }
AMateria::~AMateria(void) { std::cout << "AMateria:	has been destroyed!" << std::endl; }

AMateria::AMateria(const AMateria &other): _type(other.getType()) { return ; }
AMateria	&AMateria::operator=(const AMateria &other) {
	if (this != &other) {
		_type = other.getType();
	}
	return *this;
}

AMateria::AMateria(const std::string &type): _type(type) { return ; }
std::string	const	&AMateria::getType(void) const { return _type; }

void	AMateria::use(ICharacter &target) {
	std::cout << "* uses some " << _type << " on " << target.getName() << " *" << std::endl;
}
