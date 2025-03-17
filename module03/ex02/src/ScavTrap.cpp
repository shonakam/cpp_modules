/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:28:34 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 03:07:32 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("default")
{
	_hitPoints = 100; _energyPoints = 50; _attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100; _energyPoints = 50; _attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{ std::cout << "ScavTrap " << _name << " has been copied!" << std::endl; }

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other) { ClapTrap::operator=(other); }
	std::cout << "ScavTrap " << _name << " has been assigned!" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap(void)
{ std::cout << "ScavTrap " << _name << " has been destroyed!" << std::endl; }

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{ std::cout << "ScavTrap " << _name << " is dead!" << std::endl; return ; }
	if (this->_energyPoints <= 0)
	{ std::cout << "ScavTrap " << _name << " has no energy" << std::endl; return ; }

	std::cout << "ScavTrap " << _name << " aggressively attacks " << target
			<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void	ScavTrap::guardGate(void)
{ std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl; }
