/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:26:58 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/15 22:57:30 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

# include <iostream>
# include <cmath>

class Fixed {
	private:
		static const int	_fractionalBits = 8;
		int					_fixed;
		void				_calledLog(const std::string &target);

	public:
		/* <===  Orthodox Canonical Form  ===> */
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed	&operator=(const Fixed &other);
		~Fixed(void);
		// ==  Additional Constractor  ==========
		Fixed(const int intValue);
		Fixed(const float floatValue);

		int					getRawBits(void) const;
		void				setRawBits(const int raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		// <=== comparison operators ===>
		bool				operator>(const Fixed &other) const;
		bool				operator<(const Fixed &other) const;
		bool				operator>=(const Fixed &other) const;
		bool				operator<=(const Fixed &other) const;
		bool				operator==(const Fixed &other) const;
		bool				operator!=(const Fixed &other) const;

		// <=== binary operators ===>
		Fixed				operator+(const Fixed &other) const;
		Fixed				operator-(const Fixed &other) const;
		Fixed				operator*(const Fixed &other) const;
		Fixed				operator/(const Fixed &other) const;

		// <=== pre-increment / post-increment ===>
		// <=== pre-decrement / post-decrement ===>
		// https://en.cppreference.com/w/cpp/language/operators
		Fixed				&operator++(void);
		Fixed				operator++(int);
		Fixed				&operator--(void);
		Fixed				operator--(int);

		static Fixed		&min(Fixed &u, Fixed &v);
		static Fixed		&max(Fixed &u, Fixed &v);
		static const Fixed	&min(const Fixed &u, const Fixed &v);
		static const Fixed	&max(const Fixed &u, const Fixed &v);
};

/* <=== OVERLOADS ===> */
std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif
