/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:35:17 by shonakam          #+#    #+#             */
/*   Updated: 2025/05/04 12:16:24 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iterator>
#include <stdexcept>

/*
 * Template Requirements:
 *  - T must be a container type that provides:
 *    - T::iterator
 *    - begin() and end() member functions
 *  - This function is not intended to work with primitive types (e.g., int, double)
 */
template <typename T>
typename T::iterator	easyfind(T& container, int value) {
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
	return it;
}
