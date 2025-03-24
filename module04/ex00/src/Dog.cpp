/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:21:33 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 20:32:48 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal() { std::cout << "Dog:	has been created!" << std::endl; setType("Dog"); }
Dog::~Dog(void) { std::cout << "Dog:	has been destroyed!" << std::endl; }
Dog::Dog(const Dog &other) : Animal(other) {}

Dog	&Dog::operator=(const Dog &other) {
	if (this != &other) {
		setType(other.getType());
	}
	return *this;
}

void	Dog::makeSound(void) const { std::cout << this->getType() << ":	Woof" << std::endl; }
