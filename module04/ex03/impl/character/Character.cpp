/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:13:31 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/25 00:24:19 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): _name(""), _tmpSlotIndex(0) {
	for (int i = 0; i < 4; i++) _materias[i] = NULL;
	for (int i = 0; i < 100; i++) _tmpSlot[i] = NULL;
}

Character::Character(const std::string &name): _name(name), _tmpSlotIndex(0) {
	for (int i = 0; i < 4; i++) _materias[i] = NULL;
	for (int i = 0; i < 100; i++) _tmpSlot[i] = NULL;
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) if (_materias[i]) delete _materias[i];
	for (int i = 0; i < 100; i++) if (_tmpSlot[i]) delete _tmpSlot[i];
}

Character::Character(const Character &other): _tmpSlotIndex() {
	*this = other;
}

Character	&Character::operator=(const Character &other) {
	if (this != &other) {
		_name = other.getName();
		for (int i = 0; i < 4; i++) {
			if (_materias[i]) delete _materias[i];
			_materias[i] = other._materias[i]->clone();
		}
		for (int i = 0; i < 100; i++) {
			if (_tmpSlot[i]) delete _tmpSlot[i];
			_tmpSlot[i] = other._tmpSlot[i]->clone();
		}
	}
	return *this;
}

std::string const	&Character::getName(void) const { return _name; }

void	Character::equip(AMateria *m) {
	if (!m || _tmpSlotIndex == 99) {
		std::cout << RED << "Character:	Invalid materia or no more slot to equip" << RESET << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (!_materias[i]) {
			_materias[i] = m;
			return ;
		}
	}
	std::cout << YELLOW << "Character:	No more slot to equip" << RESET << std::endl;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || !_materias[idx]) return ;
	_tmpSlot[_tmpSlotIndex++] = _materias[idx];
	_materias[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= 4 || !_materias[idx]) return ;
	_materias[idx]->use(target);
}


