/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:10:29 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 20:32:29 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal() { std::cout << "Cat:	has been created!" << std::endl; setType("Cat"); }
Cat::~Cat(void) { std::cout << "Cat:	has been destroyed!" << std::endl; }
Cat::Cat(const Cat &other) : Animal(other) {}

Cat	&Cat::operator=(const Cat &other) {
	if (this != &other) {
		setType(other.getType());
	}
	return *this;
}

void	Cat::makeSound(void) const { std::cout << this->getType() << ":	Meow" << std::endl; }
