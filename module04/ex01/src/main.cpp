/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:00:49 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 22:22:40 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// static std::string	setColor(const std::string &name) { return (YELLOW + name + RESET); }

void	checkArray(const unsigned int count) {
	std::cout << "--- [ Array Test START ] ---" << std::endl;

	Animal		**animals = new Animal*[count];

	for (unsigned int j = 0; j < count; j++) {
		animals[j] = (j % 2 == 0)
			? static_cast<Animal*>(new Cat())
			: static_cast<Animal*>(new Dog());
	}
	for (unsigned int j = 0; j < count; j++) {
		animals[j]->makeSound();
		delete animals[j];
	}
	delete[] animals;

	std::cout << "--- [ Array Test END ] ---" << std::endl;
}

void	checkDogDeepCopy(void) {
	std::cout << "--- [ DogDeepCopy Test START ] ---" << std::endl;

	Dog a;
	a.setIdeaById("POCHI", 0);

	Dog b = a;
	a.setIdeaById("Bella", 0);

	std::cout << "[a0]: " << a.getIdeaById(0) << std::endl;
	std::cout << "[b0]: " << b.getIdeaById(0) << std::endl;

	std::cout << "--- [ DogDeepCopy Test END ] ---" << std::endl;
}

void	checkCatDeepCopy(void) {
	std::cout << "--- [ CatDeepCopy Test START ] ---" << std::endl;

	Cat a;
	a.setIdeaById("TAMA", 0);

	Cat b = a;
	a.setIdeaById("Minette", 0);

	std::cout << "[a0]: " << a.getIdeaById(0) << std::endl;
	std::cout << "[b0]: " << b.getIdeaById(0) << std::endl;

	std::cout << "--- [ CatDeepCopy Test END ] ---" << std::endl;
}

/*
 * is a: inheritance
 * has a: composition
 * can do: polymorphism
 *　- 
*/
int main()
{
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	
	delete i;
	delete j;

	// const Animal* meta = new Animal[100];
	// delete [] meta;

	checkDogDeepCopy();
	checkCatDeepCopy();
	checkArray(4);
}