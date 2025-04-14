/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:16:08 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/14 21:42:01 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "type/A.hpp"
#include "type/B.hpp"
#include "type/C.hpp"
#include <cstdlib>
#include <ctime>

void	identify(Base *p) {
	if (dynamic_cast<A*>(p)) std::cout << "Identified: A\n";
	else if (dynamic_cast<B*>(p)) std::cout << "Identified: B\n";
	else if (dynamic_cast<C*>(p)) std::cout << "Identified: C\n";
	else std::cout << "Identified: Unknown\n";
}

void	identify(Base& p) {
	try { 
		dynamic_cast<A&>(p);
		std::cout << "Identified: A\n";
		return ;
	} catch (...) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "Identified: B\n";
		return ;
	} catch (...) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "Identified: C\n";
		return ;
	} catch (...) {}
	std::cout << "Identified: Unknown\n";
}

Base*	generate(void) {
	int r = rand() % 3;
	if (r == 0) { std::cout << "[generate] A\n"; return new A(); }
	else if (r == 1) { std::cout << "[generate] B\n"; return new B(); }
	else { std::cout << "[generate] C\n"; return new C(); }
}

void	fuzzing(void) {
	int	count = 100;
	for (int i = 0; i < count; i++) {
		Base*	what = generate();
		identify(what);
		delete what;
	}
}

// https://learn.microsoft.com/en-us/cpp/cpp/run-time-type-information?view=msvc-170
// https://en.cppreference.com/w/cpp/language/dynamic_cast
int main(void) {
	srand(static_cast<unsigned>(time(0)));
	Base*	what = generate();
	identify(what);
	delete what;

	// fuzzing();
}
