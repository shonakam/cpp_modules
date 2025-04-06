/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:42:38 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/07 02:41:37 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <sstream>
#include <fstream> // for /dev/null

void	testSuccessfulExecution(void) {
	std::cout << GREEN << "\n=== [o] SUCCESS TESTS ===\n" << RESET;

	Bureaucrat highRanker("Alice", 1);

	std::cout << BLUE << "\n### ShrubberyCreationForm Test ###\n" << RESET;
	ShrubberyCreationForm shrub("garden");
	highRanker.signForm(shrub);
	highRanker.executeForm(shrub);

	std::cout << BLUE << "\n### RobotomyRequestForm Test ###\n" << RESET;
	RobotomyRequestForm robo("bender");
	highRanker.signForm(robo);
	highRanker.executeForm(robo);

	std::cout << BLUE << "\n### PresidentialPardonForm Test ###\n" << RESET;
	PresidentialPardonForm pardon("Ford Prefect");
	highRanker.signForm(pardon);
	highRanker.executeForm(pardon);
}

void	testFailedExecution(void) {
	std::cout << RED << "\n=== [x] FAILURE TESTS ===\n" << RESET;

	Bureaucrat lowRanker("Bob", 150);

	std::cout << BLUE << "\n### ShrubberyCreationForm Test ###\n" << RESET;
	ShrubberyCreationForm shrub("desert");
	lowRanker.signForm(shrub);
	lowRanker.executeForm(shrub);

	std::cout << BLUE << "\n### RobotomyRequestForm Test ###\n" << RESET;
	RobotomyRequestForm robo("marvin");
	lowRanker.signForm(robo);
	lowRanker.executeForm(robo);
	
	std::cout << BLUE << "\n### PresidentialPardonForm Test ###\n" << RESET;
	PresidentialPardonForm pardon("Arthur Dent");
	lowRanker.signForm(pardon);
	lowRanker.executeForm(pardon);
}

void	testRobotomyStatistical(void) {
	std::cout << BLUE << "\n### RobotomyStatistical Test ###\n" << RESET;

	Bureaucrat highRanker("Charlie", 1);
	unsigned int success = 0;
	unsigned int failure = 0;
	unsigned int attempts = 1000;
	
	// MUTE std::cout!!
	std::streambuf	*originalCout = std::cout.rdbuf();
	std::ofstream	devnull("/dev/null");
	std::cout.rdbuf(devnull.rdbuf());
	for (unsigned int i = 0; i < attempts; ++i) {
		RobotomyRequestForm robo("robot");
		highRanker.signForm(robo);

		std::stringstream	buffer;
		std::streambuf		*prev = std::cout.rdbuf();
		std::cout.rdbuf(buffer.rdbuf());

		robo.execute(highRanker);
		std::cout.rdbuf(prev);
		std::string output = buffer.str();
		if (output.find("successfully") != std::string::npos) success++;
		else if (output.find("failed") != std::string::npos) failure++; 
		else std::cerr << YELLOW << "[!] Unrecognized output:\n" << output << RESET << std::endl;
	}
	std::cout.rdbuf(originalCout);
	std::cout << GREEN << "Success: " << RESET << success << std::endl;
	std::cout << RED   << "Failure: " << RESET << failure << std::endl;
	std::cout << YELLOW << "Success Rate: " << RESET
	          << (success * 100 / attempts) << "%" << std::endl;
}

int main() {
	testSuccessfulExecution();
	std::cout << GREEN << "==      END     ==\n" << RESET << std::endl;
	testFailedExecution();
	std::cout << RED << "==      END     ==\n" << RESET << std::endl;
	testRobotomyStatistical();
	std::cout << BLUE << "==      END     ==\n" << RESET << std::endl;
}