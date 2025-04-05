/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:42:38 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/06 00:55:10 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>
#include <ctime>
#define REQUIRED_SIGN 50
#define REQUIRED_EXEC 30

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

////////////////////////////////////////////////////////////////////////////////////

void	occfForm(void) {
	Form f1("OriginalForm", REQUIRED_SIGN, REQUIRED_EXEC);
	Form f2(f1);
	Form f3 = f1;
	f1 = f3;

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;
}

void	signFormTest(void) {
	Form		f("OriginalForm", REQUIRED_SIGN, REQUIRED_EXEC);
	Bureaucrat	b("Alice", GRADE_MIN);
	int			attempts = 0;
	std::string	lastMsg;

	std::cout << b << std::endl;
	std::cout << f << std::endl;

	while (!f.getSigned()) {
		try {
			f.beSigned(b);
			std::cout	<< b << " signed "
						<< f << std::endl;
		} catch (std::exception &e) {
			attempts++;
			// std::cout	<< b << " couldn't sign "
			// 			<< f << " because " << e.what() << std::endl;
			lastMsg = e.what();
			b.incrementGrade();
		}
	}
	std::cout	<< GREEN
				<< "[OK] Form signed after "
				<< attempts << " attempts!"
				<< RESET << std::endl;
	std::cout	<< BLUE
				<< "[INFO] Last error message: "
				<< lastMsg << RESET << std::endl;
}

void	doubleSign(void) {
	Form		f("OriginalForm", REQUIRED_SIGN, REQUIRED_EXEC);
	Bureaucrat	b("Alice", GRADE_MAX);

	f.beSigned(b);
	std::cout << f << std::endl;
	f.beSigned(b);
	std::cout << f << std::endl;
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

	std::cout << "TEST[5] == OCCF Form ==" << std::endl;
	occfForm();
	std::cout << "==	END	==" << std::endl << std::endl;

	std::cout << "TEST[6] == Form Signing ==" << std::endl;
	signFormTest();
	std::cout << "==	END	==" << std::endl << std::endl;

	std::cout << "TEST[7] == Double Signing ==" << std::endl;
	doubleSign();
	std::cout << "==	END	==" << std::endl << std::endl;
}
