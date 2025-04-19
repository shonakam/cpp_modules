/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:44:10 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/19 22:01:16 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void	swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename U>
const U&	min(const U& a, const U& b) {
	return ((a < b) ? a : b);
}

template <typename V>
const V&	max(const V& a, const V& b) {
	return ((a > b) ? a : b);
}