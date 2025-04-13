/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:15:34 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/13 17:31:56 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Conversion.hpp"


static void	run(const std::string &literal, int caseNum) {
	std::cout << std::endl;
	std::cout	<< "============= " 
			 	<< "TEST[" << caseNum << "]"
				<< " =============" << std::endl;

	std::cout << "Input: " << literal << std::endl;
	Conversion::convert(literal);

	std::cout << "=============== END ===============" << std::endl;
}

static void	test(void) {
	int i = 0;
	
	// CAHR
	run("'0'", i++);
	run("'*'", i++);
	run("'AA'", i++); // "impossible"

	// INT
	run("0", i++);
	run("-42", i++);
	run("+42", i++);
	run("12345678901234567890", i++); // "impossible"
	
	// FLOAT
	run("+42.42f", i++);
	run("0f", i++);
	run("+0f", i++);
	run("-0f", i++);
	run("0.0f", i++);
	run("+0.0f", i++);
	run("-0.0f", i++);
	run("1e38f", i++);
	run("1e-39f", i++); // "impossible"
	
	// DOUBLE
	run("42.42", i++);
	run("1e38", i++);
	run("1e-45", i++);
	run("0.0", i++);
	run("+0.0", i++);
	run("-0.0", i++);
	run("1.0e+308", i++);
	run("1.0e-307", i++);
	run("1.0e+309", i++); // "maybe impossible"
		
	// PSEUDO LITERALS
	run("nan", i++);
	run("nanf", i++);
	run("+inf", i++);
	run("+inff", i++);
	run("-inf", i++);
	run("-inff", i++);
	run("inf", i++);
	run("inff", i++);
	run("nonumericstring", i++);  //"impossible"
}

// Note: double can handle up to about 310 decimal digits, but the precision starts to degrade
// after around 15-16 significant digits. Any number larger than that may lead to inaccuracies.
int main(int ac, const char **av) {
	bool debug = true;

	if (debug) { return (test(), EXIT_SUCCESS); }
	if (ac != 2) return std::cerr << "Invalid argument" << std::endl, 1;
	Conversion::convert(av[1]);
}
