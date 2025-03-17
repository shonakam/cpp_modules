/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:30:12 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 02:58:28 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static std::string	setColor(const std::string &name) { return (GREEN + name + RESET); }
static void printLine(void) { std::cout << "--------------------------------" << std::endl; }

static void testBasicActions(ScavTrap &scav)
{
	printLine();
	std::cout << setColor("== Basic Functionality Test ==") << std::endl;
	scav.attack(setColor("enemy"));
	scav.takeDamage(10);
	scav.beRepaired(5);
	scav.guardGate();
}

static void testEnergyDrain(ScavTrap &scav)
{
	printLine();
	std::cout << setColor("== Energy Drain Test ==") << std::endl;
	for (int i = 0; i < 50; i++) { scav.attack(setColor("enemy")); }
	scav.beRepaired(5);
}

static void testHPZero(ScavTrap &scav)
{
	printLine();
	std::cout << setColor("== HP Drain Test ==") << std::endl;
	scav.takeDamage(200);
	scav.attack(setColor("enemy"));
	scav.beRepaired(5);
}

static void testCopyAndAssignment(void)
{
	printLine();
	std::cout << setColor("== Copy & Assignment Test ==") << std::endl;
	ScavTrap scav1(setColor("Scav1"));
	ScavTrap scavCopy(scav1);
	scavCopy.attack(setColor("enemy"));

	ScavTrap scav2(setColor("Scav2"));
	scav2 = scav1;
	scav2.guardGate();
}

static void testHeap(void)
{
    printLine();
    std::cout << setColor("== Heap Memory Test ==") << std::endl;
    ScavTrap* heapScav = new ScavTrap(setColor("HeapScav"));

    testBasicActions(*heapScav);
    testEnergyDrain(*heapScav);
    testHPZero(*heapScav);

    delete heapScav;
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
	ScavTrap scav(setColor("Scav"));

	testBasicActions(scav);
	testEnergyDrain(scav);
	testHPZero(scav);
	testCopyAndAssignment();
	testHeap(); 

	std::cout << "\n=== Destroying Objects ===" << std::endl;
}


