/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:42:38 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/05 19:54:44 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

void	occf(void) {
	Bureaucrat	b1 = Bureaucrat("Alice", 1);
	Bureaucrat	b2 = Bureaucrat("Bob", 150);
	Bureaucrat	b3 = Bureaucrat(b1);
	Bureaucrat	b4 = b2;

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	std::cout << b4 << std::endl;
}

void initRandom(void) { std::srand(std::time(0)); }

static int getRandomGrade(void) {
	return (GRADE_MAX + std::rand() % (GRADE_MIN - GRADE_MAX + 1));
}

void	fuzzing(bool isIncrement = true) {
	Bureaucrat	b = Bureaucrat("Alice", getRandomGrade());
	int			ok = 0;
	int			lim = std::min(GRADE_MIN * 2, 300);
	std::cout << b << std::endl;

	try {
		if (isIncrement) for (; ok < lim; ok++) b.incrementGrade();
		else for (; ok < lim; ok++) b.decrementGrade();
	} catch (std::exception &e) {
		std::string msg = isIncrement ? "[ERR] Bureaucrat incremented " : "[ERR] Bureaucrat decremented ";
		std::cerr << RED << msg
			<< "[" << (ok + 1) << "]"
			<< " times: " << e.what()
			<< RESET << std::endl;
	}
}

void	testInitError(void) {
	try {
		Bureaucrat b1("TooHigh", GRADE_MAX - 1);
		std::cerr << RED << "[NG] No exception for grade 0!" << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout	<< GREEN
					<< "[OK] Caught exception for grade "
					<< (GRADE_MAX - 1) << ": "
					<< e.what() << RESET << std::endl;
	}
	try {
		Bureaucrat b2("TooLow", GRADE_MIN + 1);
		std::cerr	<< RED 
					<< "[NG] No exception for grade 200!" << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout	<< GREEN 
					<< "[OK] Caught exception for grade "
					<< (GRADE_MIN + 1) << ": "
					<< e.what() << RESET << std::endl;
	}
}


int	main(void) {
	initRandom();
	std::cout << "TEST[1]	== OCCF ==" << std::endl;
	occf();
	std::cout << "==	END	==" << std::endl << std::endl;

	std::cout << "TEST[2]	== increment ==" << std::endl;
	fuzzing();
	std::cout << "==	END	==" << std::endl << std::endl;
	
	std::cout << "TEST[3]	== decrement ==" << std::endl;
	fuzzing(false);
	std::cout << "==	END	==" << std::endl << std::endl;

	std::cout << "TEST[4]	== err_init ==" << std::endl;
	testInitError();
	std::cout << "==	END	==" << std::endl << std::endl;
}
