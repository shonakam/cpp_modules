/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:49:53 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/14 11:27:33 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/* Initialize membeers */
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}
HumanA::~HumanA(void) {}

void		HumanA::setName(std::string name) { this->_name = name; }
std::string	HumanA::getName(void) const { return this->_name; }
Weapon		&HumanA::getWeapon(void) const { return this->_weapon; }

void	HumanA::attack(void) const {
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
