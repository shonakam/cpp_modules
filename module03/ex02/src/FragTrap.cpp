/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:17:14 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 03:39:28 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
	_hitPoints = 100; _energyPoints = 100; _attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{ std::cout << "FragTrap " << _name << " has been copied!" << std::endl; }

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other) { ClapTrap::operator=(other); }
	std::cout << "FragTrap " << _name << " has been assigned!" << std::endl;
	return *this;
}

FragTrap::~FragTrap(void)
{ std::cout << "FragTrap " << _name << " has been destroyed!" << std::endl; }

void	FragTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0) { std::cout << "FragTrap " << _name << " is already destroyed and cannot attack!" << std::endl; return; }
	if (_energyPoints <= 0) { std::cout << "FragTrap " << _name << " has no energy left and cannot attack!" << std::endl; return; }
	_energyPoints--;
	std::cout << "FragTrap " << _name << " powerfully attacks " << target
			<< ", dealing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{ std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl; }
