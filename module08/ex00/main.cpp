/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:40:49 by shonakam          #+#    #+#             */
/*   Updated: 2025/05/04 12:29:12 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#define END 42

void testSuccess(std::vector<int>& vec) {
	try {
		std::vector<int>::iterator it = easyfind(vec, END - 1);
		std::cout << GREEN << "[Success] Found: " << *it << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout << RED << "[Success] Error: " << e.what() << RESET << std::endl;
	}
}


void testFailure(std::vector<int>& vec) {
	try {
		std::vector<int>::iterator it = easyfind(vec, END);
		std::cout << GREEN << "[Failure] Found: " << *it << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout << RED << "[Failure] Error: " << e.what() << RESET << std::endl;
	}
}

int main() {
	std::vector<int> vec;

	for (int i = 0; i < END; ++i) {
		vec.push_back(i);
	}
	testSuccess(vec);
	testFailure(vec);
}
