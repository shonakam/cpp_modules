/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:23:55 by shonakam          #+#    #+#             */
/*   Updated: 2025/05/10 22:17:59 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

void testDifferentType() {
	MutantStack<std::string> smstack;
	smstack.push("hello");
	smstack.push("world");
	smstack.push("42");
	smstack.push("Tokyo");
	smstack.push("!!");

	for (MutantStack<std::string>::iterator it = smstack.begin(); it != smstack.end(); ++it) {
		std::cout << *it << std::endl;
	}
}

void testConstIterator() {
	MutantStack<int> mstack;
	for (int i = 0; i < 10; ++i) { mstack.push(i); }
	const MutantStack<int> cmstack = mstack;
	MutantStack<int>::const_iterator cit = cmstack.begin();
	MutantStack<int>::const_iterator cite = cmstack.end();

	while (cit != cite) {
		std::cout << *cit << std::endl;
		++cit;
	}
}

void testEmptyStack() {
	MutantStack<double> dmstack;
	if (dmstack.begin() == dmstack.end()) {
		std::cout << "Empty stack has matching begin and end." << std::endl;
	}
}


void testHandler() {
	std::cout << "======== TEST ========" << std::endl;
	testConstIterator();
	testDifferentType();
	testEmptyStack();
}


/*
 * [5] -> [5, 17] -> [5] -> [5, 3] -> [5, 3, 5] -> [5, 3, 5, 737] -> [5, 3, 5, 737, 0]
 * cout -> 17, 1, 5, 3, 5, 737, 0
 */
int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	// testHandler();
	return 0;
}
