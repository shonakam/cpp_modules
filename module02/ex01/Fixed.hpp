/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:26:58 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/15 14:20:46 by shonakam         ###   ########.fr       */
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

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		Fixed(const int intValue);
		Fixed(const float floatValue);
		~Fixed(); 

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif