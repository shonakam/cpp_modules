/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:49:53 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/14 11:28:36 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}
HumanB::~HumanB(void) {}

void		HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon; }
void		HumanB::setName(std::string name) { this->_name = name; }
Weapon		*HumanB::getWeapon(void) const { return this->_weapon; }
std::string	HumanB::getName(void) const { return this->_name; }

void HumanB::attack() const {
	if (_weapon) {
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	} else {
		std::cout << _name << " has no weapon to attack with!" << std::endl;
	}
}
