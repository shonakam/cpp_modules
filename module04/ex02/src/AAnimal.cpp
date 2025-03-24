/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:07:09 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 22:32:26 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void): _type("") { std::cout << "AAnimal:	has been created!" << std::endl; }
AAnimal::~AAnimal(void) { std::cout << "Animal:	has been destroyed!" << std::endl; }
AAnimal::AAnimal(const AAnimal &other): _type(other.getType()) { return ; }
AAnimal	&AAnimal::operator=(const AAnimal &other) { 
	if (this != &other) {
		_type = other.getType();
	}
	return *this;
}

// void		AAnimal::makeSound(void) const { std::cout << "Animal:	makes a sound" << std::endl; }
void		AAnimal::setType(const std::string &type) { _type = type; }
std::string	AAnimal::getType(void) const { return _type; }
