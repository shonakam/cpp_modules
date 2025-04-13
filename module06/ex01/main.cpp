/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:51:19 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/13 21:50:35 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Serialize.hpp"

int	main(void) {
	Data	original = {"Alice", 30};

	std::cout << "================================" << std::endl;

	uintptr_t	raw = Serializer::serialize(&original);
	Data		*ptr = Serializer::deserialize(raw);
	
	std::cout << "Original:		" << &original << std::endl;
	std::cout << "Serialized:		" << raw << std::endl;
	std::cout << "Deserialized:		" << ptr << std::endl;

	std::cout	<< "Deserialized Data:	"
				<< "name->" << ptr->name << ", "
				<< "age->" << ptr->age << std::endl;

	if (ptr == &original) std::cout << GREEN << "[OK]" << RESET << " Pointer matches" << std::endl;
	else std::cout << RED << "[FAIL]" << RESET << " Pointer mismatch!" << std::endl;

	std::cout << "================================" << std::endl;
}
