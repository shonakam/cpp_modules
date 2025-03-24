/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:00:49 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 17:47:04 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static std::string	setColor(const std::string &name) { return (YELLOW + name + RESET); }

void	testAbnormal(void) {
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* kitty = new WrongCat();

	std::cout << "Type: " << kitty->getType() << std::endl;
	kitty->makeSound();
	meta->makeSound();

	WrongAnimal* fakeCat = const_cast<WrongAnimal*>(kitty);
	fakeCat->setType(setColor("FakeCat"));

	std::cout << "Updated Type: " << kitty->getType() << std::endl;
	kitty->makeSound();

	delete meta;
	delete kitty;
}

void	testNormal(void) {
	const Animal	*meta = new Animal();
	const Animal	*i = new Cat();
	const Animal	*j = new Dog();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	Animal	*kitten = const_cast<Animal*>(i);
	Animal	*puppy = const_cast<Animal*>(j);

	kitten->setType(setColor("Kitten"));
	puppy->setType(setColor("Puppy"));
	std::cout << "Updated Type:" << i->getType() << " " << std::endl;
	std::cout << "Updated Type:" << j->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	
	// delete kitten;
	// delete puppy;
	delete i;
	delete j;
	delete meta;
}

int main(void) {
	std::cout << "--- [ Animal Test Start ] ---" << std::endl;
	testNormal();
	std::cout << "--- [ Animal Test End ] ---" << std::endl;
	
	std::cout << "--- [ WrongAnimal Test Start ] ---" << std::endl;
	testAbnormal();
	std::cout << "--- [ WrongAnimal Test End ] ---" << std::endl;
}