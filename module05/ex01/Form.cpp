/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:40:16 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/06 00:58:57 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// == OCCF ====================================================================
Form::Form(void) : _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {
	std::cout << "Form: has been created!" << std::endl;
}

Form::Form(const std::string &name, int signGrade, int execGrade) :
	_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1) throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150) throw Form::GradeTooLowException();
	std::cout << "Form: has been created!" << std::endl;
}

Form::~Form(void) { std::cout << "Form: has been destroyed!" << std::endl; }

Form::Form(const Form &other) :
	_name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	std::cout << "Form: has been copied!" << std::endl;
}

Form	&Form::operator=(const Form &other) {
	if (this != &other) _signed = other._signed;
	std::cout << "Form: has been assigned!" << std::endl;
	return (*this);
}

// == Accessors ===============================================================
const std::string	&Form::getName(void) const { return (_name); }
int					Form::getSignGrade(void) const { return (_signGrade); }
int					Form::getExecGrade(void) const { return (_execGrade); }
bool				Form::getSigned(void) const { return (_signed); }

// == Member Functions ========================================================
void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (_signed) {
		std::cout	<< YELLOW << "[WARN] Form \""
					<< _name << "\" is already signed. Skipping."
					<< RESET << std::endl;
		return ;
	}
	if (bureaucrat.getGrade() > _signGrade) throw Form::GradeTooLowException();
	else _signed = true;
	std::cout << "Form: has been signed!" << std::endl;
}

// == Exceptions ==============================================================
const char	*Form::GradeTooHighException::what(void) const throw() {
	return ("Form: Grade is too high!");
}

const char	*Form::GradeTooLowException::what(void) const throw() {
	return ("Form: Grade is too low!");
}

// == Operator Overloads ======================================================
std::ostream	&operator<<(std::ostream &os, const Form &form) {
	os	<< "Form: " << form.getName()
		<< ", sign grade: " << form.getSignGrade()
		<< ", exec grade: " << form.getExecGrade()
		<< ", signed: " << form.getSigned();
	return (os);
}
