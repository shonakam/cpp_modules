/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:40:49 by shonakam          #+#    #+#             */
/*   Updated: 2025/05/10 14:02:42 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "easyfind.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#define END 42

void testSuccess(std::list<int>& lst) {
	try {
		std::list<int>::iterator it = easyfind(lst, END - 1);
		std::cout << GREEN << "[Success] Found: " << *it << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout << RED << "[Success] Error: " << e.what() << RESET << std::endl;
	}
}

void testFailure(std::list<int>& lst) {
	try {
		std::list<int>::iterator it = easyfind(lst, END);
		std::cout << GREEN << "[Failure] Found: " << *it << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout << RED << "[Failure] Error: " << e.what() << RESET << std::endl;
	}
}

// used container -> list
// https://cplusplus.com/reference/stl/
int main() {
	std::list<int> lst;

	for (int i = 0; i < END; ++i) {
		lst.push_back(i);
	}
	testSuccess(lst);
	testFailure(lst);
}
