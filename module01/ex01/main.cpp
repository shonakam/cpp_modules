/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:57:25 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/12 06:00:13 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	if (N <= 0) return NULL;

	Zombie*	horde = new Zombie[N];
	for (int i = 0; i < N; i++) horde[i].setName(name);
	return horde;
}

int main() {
	int N = 5;
	Zombie* horde = zombieHorde(N, "HordeZombie");

	for (int i = 0; i < N; i++) horde[i].announce();
	delete[] horde;
}
