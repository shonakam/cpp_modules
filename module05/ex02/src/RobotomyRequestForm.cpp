/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:17:57 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/07 01:53:48 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

// == OCCF ====================================================================
RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("Robotomy Request Form", ROBOTOMY_SIGN, ROBOTOMY_EXEC),
	_target("") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm("Robotomy Request Form", ROBOTOMY_SIGN, ROBOTOMY_EXEC),
	_target(target) {
	std::cout	<< "RobotomyRequestForm constructor called."
				<< " Target: [" << target << "]" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
	AForm(other),
	_target(other._target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// == Member Functions ========================================================

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	this->checkExecutability(executor);
	static bool	seeded = false;

	if (!seeded) { std::srand(std::time(0)); seeded = true; }
	std::cout << "Bzzzz... drilling noises..." << std::endl;
	if (std::rand() % 2) std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else std::cout << this->_target << " has failed to be robotomized." << std::endl;
}
