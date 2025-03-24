/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:54:12 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 18:05:28 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) { std::cout << "WrongCat:	has been created!" << std::endl; setType("WrongCat"); }
WrongCat::~WrongCat(void) { std::cout << "WrongCat:	has been destroyed!" << std::endl; }
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) { setType(other.getType()); }
WrongCat	&WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		setType(other.getType());
	}
	return *this;
}

void	WrongCat::makeSound(void) const { std::cout << this->getType() << ":	Meow" << std::endl; }
