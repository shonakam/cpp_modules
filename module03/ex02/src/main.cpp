/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:30:12 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/22 17:19:50 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static std::string	setColor(const std::string &name) { return (GREEN + name + RESET); }

void test(FragTrap &frag)
{
	std::cout << "=== Running Functional Tests ===" << std::endl;

	frag.attack(setColor("Enemy"));
	frag.takeDamage(30);
	frag.beRepaired(20);
	frag.highFivesGuys();

	std::cout << "=== Energy Drain Test ===" << std::endl;
	for (int i = 0; i < 100; i++) { frag.attack(setColor("Target")); }
	frag.beRepaired(10);

	std::cout << "=== HP Drain Test ===" << std::endl;
	frag.takeDamage(200);
	frag.attack(setColor("Enemy"));
	frag.beRepaired(5);
}

// void	testConstructorDestructorHeap(void)
// {
// 	std::cout << "\n=== Testing Heap Constructor & Destructor ===" << std::endl;
// 	FragTrap* heapFrag = new FragTrap(setColor("Heap"));
// 	test(*heapFrag);
// 	delete heapFrag;
// }

void	testConstructorDestructorStack()
{
	std::cout << "\n=== Testing Stack Constructor & Destructor ===" << std::endl;
	FragTrap stackFrag(setColor("Stack"));
	test(stackFrag);
}

/*
* == Inheritance ==
* Constructor	: Parent -> Child
* Destructor	: Child -> Pearent
* Virtual Prefix
* 	- Virtual Destructor	: delete Parent class pointer
* 	- Virtual Function		: call Child class function with Pearent class pointer
*  - memo: if not use "new", do not need virtual.
*/
int main(void)
{
	std::cout << "=== Creating ScavTrap ===" << std::endl;
	testConstructorDestructorStack();
	// testConstructorDestructorHeap();
	std::cout << "\n=== Destroying Objects ===" << std::endl;
}


