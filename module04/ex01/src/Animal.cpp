/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:07:09 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 18:00:17 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("") { std::cout << "Animal:	has been created!" << std::endl; }
Animal::~Animal(void) { std::cout << "Animal:	has been destroyed!" << std::endl; }
Animal::Animal(const Animal &other): _type(other.getType()) { return ; }
Animal	&Animal::operator=(const Animal &other) { 
	if (this != &other) {
		_type = other.getType();
	}
	return *this;
}

void		Animal::makeSound(void) const { std::cout << "Animal:	makes a sound" << std::endl; }
void		Animal::setType(const std::string &type) { _type = type; }
std::string	Animal::getType(void) const { return _type; }
