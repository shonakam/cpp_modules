/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:48:05 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/07 02:10:03 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// == OCCF ==================================================================== 

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(GRADE_MIN) {
	std::cout << "Bureaucrat: has been created!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade):
	_name(name), _grade(grade) {
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
	else if (grade > 150) throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat: has been created!" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat: has been destroyed!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):
	_name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat: has been copied!" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) _grade = other._grade;
	std::cout << "Bureaucrat: has been assigned!" << std::endl;
	return (*this);
}

// == Accessors ===============================================================

const std::string	&Bureaucrat::getName(void) const { return (_name); }
int					Bureaucrat::getGrade(void) const { return (_grade); }

// == Member Functions ========================================================

void	Bureaucrat::incrementGrade(void) {
	if (_grade == GRADE_MAX) throw Bureaucrat::GradeTooHighException();
	--_grade;
}

void	Bureaucrat::decrementGrade(void) {
	if (_grade == GRADE_MIN) throw Bureaucrat::GradeTooLowException();
	++_grade;
}

void	Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout	<< *this << " signed " << form << std::endl;
	} catch (std::exception &e) {
		std::cout	<< *this << " couldn't sign "
					<< form << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form) const {
	try {
		form.execute(*this);
		std::cout	<< *this << " executed " << form << std::endl;
	} catch (std::exception &e) {
		std::cout	<< *this << " couldn't execute "
					<< form << " because " << e.what() << std::endl;
	}
}

// == Exceptions ==============================================================
// https://cplusplus.com/reference/exception/exception/
// https://cplusplus.com/reference/exception/exception/what/

const char	*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high!");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low!");
}

// == Operator Overloading ====================================================

std::ostream  &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
