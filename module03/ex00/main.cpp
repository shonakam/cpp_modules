/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:30:12 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 02:49:53 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static std::string	setColor(const std::string &name) { return (GREEN + name + RESET); }
static void			printLine(void) { std::cout << "--------------------------------" << std::endl; }

static void			test(ClapTrap &clap)
{
	clap.attack(setColor("Charlie"));
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.takeDamage(10);
	clap.attack(setColor("David"));
	clap.beRepaired(5);
}

static void			mineuchi(ClapTrap &clap) { clap.takeDamage(9); }
static void			repair(ClapTrap &clap) { for(int i = 0; i < 12; i++) clap.beRepaired(3); }
static void			kill(ClapTrap &clap) { for(int i = 0; i < 12; i++) clap.takeDamage(3); }
static void			zeroHpMove(ClapTrap &clap) { clap.attack(setColor("enemy")); clap.takeDamage(10); clap.beRepaired(200); }

int	main(void)
{
	ClapTrap clap1(setColor("Alice"));
	ClapTrap clap2(setColor("Bob"));
	ClapTrap *heapClap = new ClapTrap(setColor("Heap"));
	
	printLine();
	test(clap1);
	printLine();
	test(clap2);
	printLine();

	ClapTrap clap3 = clap1;
	clap2 = clap1;

	printLine();
	test(clap2);
	printLine();
	test(clap3);

	printLine();
	mineuchi(*heapClap);
	repair(*heapClap);
	kill(*heapClap);
	zeroHpMove(*heapClap);
	delete heapClap;
}
