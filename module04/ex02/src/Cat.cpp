/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:10:29 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 22:37:41 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): AAnimal(), _brain(new Brain()) {
	std::cout << "Cat:	has been created!" << std::endl; setType("Cat");
}

Cat::~Cat(void) {
	delete _brain;
	std::cout << "Cat:	has been destroyed!" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other) { 
	_brain = new Brain(*other._brain);
}

Cat	&Cat::operator=(const Cat &other) {
	if (this != &other) {
		AAnimal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

void		Cat::makeSound(void) const { std::cout << this->getType() << ":	Meow" << std::endl; }
std::string	Cat::getIdeas(void) const { return _brain->getIdeas(); }
std::string	Cat::getIdeaById(int index) const { return _brain->getIdeaById(index); }
void		Cat::setIdeaById(const std::string &idea, int index) { _brain->setIdeaById(idea, index); }
