/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:17:38 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/07 02:13:06 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

// == OCCF ====================================================================
ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("Shrubbery Creation Form", SHRUBBERY_SIGN, SHRUBBERY_EXEC),
	_target("") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm("Shrubbery Creation Form", SHRUBBERY_SIGN, SHRUBBERY_EXEC),
	_target(target) {
	std::cout	<< "ShrubberyCreationForm constructor called."
				<< " Target: [" << target << "]" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm(other),
	_target(other._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// == Member Functions ========================================================

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	this->checkExecutability(executor);
	std::string		filename = this->_target + "_shrubbery";
	std::ofstream	ofs(filename.c_str());
	if (!ofs) {
		std::cerr << "Error: could not open file " << filename << std::endl;
		return ;
	}
	ofs	<< "     #     " << std::endl
		<< "    ###    " << std::endl
		<< "   #####   " << std::endl
		<< "  #######  " << std::endl
		<< " ######### " << std::endl
		<< "###########" << std::endl
		<< "     H     " << std::endl
		<< "     H     " << std::endl;
	ofs.close();
	std::cout	<< "Shrubbery creation form executed successfully."
				<< " Shrubbery created in file: [" << filename << "]" << std::endl;
}
