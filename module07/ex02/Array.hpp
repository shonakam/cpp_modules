/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:24:36 by shonakam          #+#    #+#             */
/*   Updated: 2025/05/04 11:21:38 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdexcept> 

template <typename T>
class Array {
	private:
		T*				_array;
		unsigned int	_size;

	public:
		Array() : _array(NULL), _size(0) {};

		Array(unsigned int n): _array(NULL), _size(n) {
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; ++i)
				this->_array[i] = T();
		};

		Array(const Array& other):
			_array(NULL), _size(other.size()) {
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_array[i] = other._array[i];
		};

		Array&	operator=(const Array& other) {
			if (this != &other) {
				delete[] _array;
				_size = other._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; ++i) {
					_array[i] = other._array[i];
				}
			}
			return *this;
		};

		~Array() {
			delete[] _array; _array = NULL;
		};

		T& operator[](unsigned int index) {
			if (index >= this->_size)
				throw std::out_of_range("Array index out of range");
			return this->_array[index];
		}

		const T& operator[](unsigned int index) const {
			if (index >= this->_size)
				throw std::out_of_range("Array index out of range");
			return this->_array[index];
		}

		unsigned int size(void) const { return (this->_size); };
};
