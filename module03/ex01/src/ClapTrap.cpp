/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:31:44 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 02:47:10 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{ std::cout << "ClapTrap " << _name << " has been created!" << std::endl; }

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{ std::cout << "ClapTrap " << _name << " has been created!" << std::endl; }

ClapTrap::~ClapTrap() { std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap &other):
_name(other._name), _hitPoints(other._hitPoints), 
_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{ std::cout << GREEN << "[call]" << RESET << ": copy constructor" << std::endl; }

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other) return (*this);
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << GREEN << "[call]" << RESET << ": overload assigned op" << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{ std::cout << "ClapTrap " << _name << " is already at 0 HP and cannot take more damage!" << std::endl; return ; }
	if (this->_energyPoints <= 0)
	{ std::cout << "ClapTrap " << _name << " is already at 0 energy and cannot attack!" << std::endl; return ; }

	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already destroyed and cannot take more damage!" << std::endl;
		return;
	}
	_hitPoints -= amount;
	if (_hitPoints < 0) _hitPoints = 0;
	std::cout << "ClapTrap " << _name << " takes " << amount
		<< " points of damage! Remaining HP: " << _hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{ std::cout << "ClapTrap " << _name << " is out of HP and cannot repair itself!" << std::endl; return ; }
	if (this->_energyPoints <= 0)
	{ std::cout << "ClapTrap " << _name << " is out of energy and cannot repair itself!" << std::endl; return ; }

	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
		<< " hit points! New HP: " << _hitPoints << std::endl;
}
