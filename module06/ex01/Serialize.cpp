/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:18:06 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/13 21:35:09 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

// == OCCF ====================================================================
Serializer::Serializer(void) {
	std::cout << "Serializer: has been created!" << std::endl;
}

Serializer::Serializer(const Serializer &other) {
	std::cout << "Serializer: has been copied!" << std::endl;
	*this = other;
}

Serializer::~Serializer(void) {
	std::cout << "Serializer: has been destroyed!" << std::endl;
}

Serializer	&Serializer::operator=(const Serializer &other) {
	std::cout << "Serializer: has been assigned!" << std::endl;
	if (this != &other) { }
	return (*this);
}

// https://learn.microsoft.com/ja-jp/cpp/cpp/reinterpret-cast-operator?view=msvc-170
uintptr_t	Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
