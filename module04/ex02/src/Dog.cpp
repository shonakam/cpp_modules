/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:21:33 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 22:40:44 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): AAnimal(), _brain(new Brain()) {
	std::cout << "Dog:	has been created!" << std::endl; setType("Dog");
}

Dog::~Dog(void) {
	delete _brain;
	std::cout << "Dog:	has been destroyed!" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other) {
	_brain = new Brain(*other._brain);
}

Dog	&Dog::operator=(const Dog &other) {
	if (this != &other) {
		AAnimal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

void		Dog::makeSound(void) const { std::cout << this->getType() << ":	Woof" << std::endl; }
std::string	Dog::getIdeas(void) const { return _brain->getIdeas(); }
std::string	Dog::getIdeaById(int index) const { return _brain->getIdeaById(index); }
void		Dog::setIdeaById(const std::string &idea, int index) { _brain->setIdeaById(idea, index); }
