/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:44:23 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/26 22:13:33 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>

namespace ft {
	template <typename T>
	void	iter(T* array, size_t length, void (*func)(T&)) {
		if (!array || !func) { return ; }
		for (size_t i = 0; i < length; ++i) func(array[i]);
	}

	template <typename T>
	void	iter(const T* array, size_t length, void (*func)(const T&)) {
		if (!array || !func) { return ; }
		for (size_t i = 0; i < length; ++i) func(array[i]);
	}
}
