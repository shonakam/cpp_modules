/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:40:16 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/07 00:31:22 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// == OCCF ====================================================================
AForm::AForm(void) : _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {
	std::cout << "Form: has been created!" << std::endl;
}

AForm::AForm(const std::string &name, int signGrade, int execGrade) :
	_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1) throw AForm::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150) throw AForm::GradeTooLowException();
	std::cout << "Form: has been created!" << std::endl;
}

AForm::~AForm(void) { std::cout << "Form: has been destroyed!" << std::endl; }

AForm::AForm(const AForm &other) :
	_name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	std::cout << "Form: has been copied!" << std::endl;
}

AForm	&AForm::operator=(const AForm &other) {
	if (this != &other) _signed = other._signed;
	std::cout << "Form: has been assigned!" << std::endl;
	return (*this);
}

// == Accessors ===============================================================
const std::string	&AForm::getName(void) const { return (_name); }
int					AForm::getSignGrade(void) const { return (_signGrade); }
int					AForm::getExecGrade(void) const { return (_execGrade); }
bool				AForm::getSigned(void) const { return (_signed); }

// == Member Functions ========================================================
void	AForm::checkExecutability(const Bureaucrat &executor) const {
	if (!_signed) throw AForm::FormNotSignedException();
	if (executor.getGrade() > _execGrade) throw AForm::GradeTooLowException();
}

void	AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (_signed) {
		std::cout	<< YELLOW << "[WARN] Form \""
					<< _name << "\" is already signed. Skipping."
					<< RESET << std::endl;
		return ;
	}
	if (bureaucrat.getGrade() > _signGrade) throw AForm::GradeTooLowException();
	else _signed = true;
	std::cout << "Form: has been signed!" << std::endl;
}

// == Exceptions ==============================================================
const char	*AForm::GradeTooHighException::what(void) const throw() {
	return ("Form: Grade is too high!");
}

const char	*AForm::GradeTooLowException::what(void) const throw() {
	return ("Form: Grade is too low!");
}

const char	*AForm::FormNotSignedException::what(void) const throw() {
	return ("Form: Form is not signed!");
}

// == Operator Overloads ======================================================
std::ostream	&operator<<(std::ostream &os, const AForm &form) {
	os	<< "Form: " << form.getName()
		<< ", sign grade: " << form.getSignGrade()
		<< ", exec grade: " << form.getExecGrade()
		<< ", signed: " << form.getSigned();
	return (os);
}
