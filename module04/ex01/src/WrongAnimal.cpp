/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:21:36 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 17:54:42 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("") { std::cout << "WrongAnimal:	has been created!" << std::endl; }
WrongAnimal::~WrongAnimal(void) { std::cout << "WrongAnimal:	has been destroyed!" << std::endl; }
WrongAnimal::WrongAnimal(const WrongAnimal &other): _type(other.getType()) { return ; }
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other) { 
	if (this != &other) {
		_type = other.getType();
	}
	return *this;
}

void		WrongAnimal::makeSound(void) const { std::cout << "WrongAnimal:	???" << std::endl; }
std::string	WrongAnimal::getType(void) const { return _type; }
void		WrongAnimal::setType(const std::string &type) { _type = type; }
