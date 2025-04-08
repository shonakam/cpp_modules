/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:42:38 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/08 21:47:27 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <string>

void exec(AForm *form) {
	if (!form) return ;
	static Bureaucrat executor("Executor", 1);
	try {
		executor.signForm(*form);
		form->execute(executor);
	} catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

int main() {
    Intern someRandomIntern;

	std::cout << YELLOW << "=== TEST[1] ===" << RESET << std::endl;
	try { AForm	*form1 = someRandomIntern.makeForm("shrubbery creation", "Home"); exec(form1); delete form1; }
	catch (const std::exception &e) { std::cerr << "Caught exception: " << e.what() << std::endl; }
	std::cout << YELLOW << "=== TEST[2] ===" << RESET << std::endl;
	try { AForm	*form2 = someRandomIntern.makeForm("robotomy request", "Bender"); exec(form2); delete form2; }
	catch (const std::exception &e) { std::cerr << "Caught exception: " << e.what() << std::endl; }
	std::cout << YELLOW << "=== TEST[3] ===" << RESET << std::endl;
	try { AForm	*form3 = someRandomIntern.makeForm("presidential pardon", "Rick"); exec(form3); delete form3; }
	catch (const std::exception &e) { std::cerr << "Caught exception: " << e.what() << std::endl; }
	std::cout << YELLOW << "=== TEST[4] ===" << RESET << std::endl;
	try { AForm	*form4 = someRandomIntern.makeForm("nonexistent form", "Nobody"); exec(form4); delete form4; }
	catch (const std::exception &e) { std::cerr << "Caught exception: " << e.what() << std::endl; }
}
