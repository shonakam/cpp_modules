/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:00:49 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 22:42:15 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void testAbstractInstantiation() {
	std::cout << "--- [ Abstract Class Instantiation Test ] ---" << std::endl;
	
	// AAnimal a;
	// const AAnimal* b = new AAnimal();

	std::cout << "### Cannot instantiate abstract class AAnimal (as expected)" << std::endl;
}

void testPolymorphism() {
	std::cout << "--- [ Polymorphism Test ] ---" << std::endl;

	const AAnimal* cat = new Cat();
	const AAnimal* dog = new Dog();

	std::cout << "Cat type: " << cat->getType() << std::endl;
	std::cout << "Dog type: " << dog->getType() << std::endl;

	cat->makeSound();
	dog->makeSound();

	delete cat;
	delete dog;

	std::cout << "-----------------------------" << std::endl;
}

int main() {
	testAbstractInstantiation();
	testPolymorphism();
}
