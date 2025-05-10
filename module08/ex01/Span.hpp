/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:37:26 by shonakam          #+#    #+#             */
/*   Updated: 2025/05/10 12:10:27 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <limits>

class Span {
	private:
		unsigned int        _maxSize;
		std::vector<int>    _numbers;
		Span();
	
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
	
		void	addNumber(int number);
		int		shortestSpan() const;
		int		longestSpan() const;
	
		template <typename Iterator>
		void	addRange(Iterator begin, Iterator end) {
			while (begin != end) {
				if (_numbers.size() >= _maxSize)
					throw std::runtime_error("Span is full");
				_numbers.push_back(*begin);
				++begin;
			}
		}
};
