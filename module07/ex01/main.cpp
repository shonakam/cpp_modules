/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:52:34 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/26 22:25:24 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void	increment(int& n) { n += 1; }
void	increment(double& n) { n += 1.1; }

void	print(const std::string& str) { std::cout << str << std::endl; }
void	print(const int& n) { std::cout << n << std::endl; }
void	print(const double& n) { std::cout << n << std::endl; }

int main(void) {
	int 		iArray[] = {1, 2, 3, 4, 5};
	double		dArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string	strArray[] = {"Hello", "World", "!"};

	std::cout << "Incrementing int array:" << std::endl;
	ft::iter(iArray, 5, increment);
	ft::iter(iArray, 5, print);

	std::cout << "Incrementing double array:" << std::endl;
	ft::iter(dArray, 5, increment);
	ft::iter(dArray, 5, print);

	std::cout << "Printing string array:" << std::endl;
	ft::iter(strArray, 3, print);
}
