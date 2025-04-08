/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:47:11 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/08 21:26:19 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// == OCCF ====================================================================
Intern::Intern(void) {
	std::cout << "Intern: has been created!" << std::endl;
}

Intern::Intern(const Intern &other) {
	(void)other;
	std::cout << "Intern: has been copied!" << std::endl;
}

Intern::~Intern(void) {
	std::cout << "Intern: has been destroyed!" << std::endl;
}

Intern	&Intern::operator=(const Intern &other) {
	(void)other;
	std::cout << "Intern: has been assigned!" << std::endl;
	return (*this);
}

// == Member Functions ========================================================

AForm	*Intern::createShrubbery(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createRobotomy(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresidential(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

// This function creates a form based on the given name and target.
// Static helper functions to create each type of form
AForm	*Intern::makeForm(const std::string &formName, const std::string &target) {
	typedef AForm *(*FormCreator)(const std::string &);

	FormCreator	creators[3] = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	const std::string	names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; ++i) {
		if (formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}
	throw FormNotFoundException();
}

// == Exceptions ==============================================================

const char *Intern::FormNotFoundException::what(void) const throw() {
	return ("Intern: Form not found.");
}
