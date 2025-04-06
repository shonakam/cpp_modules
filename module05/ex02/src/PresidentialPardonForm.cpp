/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:17:41 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/07 01:54:15 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// == OCCF ==================================================================== 

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("Presidential Pardon Form", PRESIDENTIAL_SIGN, PRESIDENTIAL_EXEC),
	_target("") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm("Presidential Pardon Form", PRESIDENTIAL_SIGN, PRESIDENTIAL_EXEC),
	_target(target) {
	std::cout	<< "PresidentialPardonForm constructor called."
				<< " Target: [" << target << "]" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
	AForm(other),
	_target(other._target) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

// == Member Functions ========================================================

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	this->checkExecutability(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
