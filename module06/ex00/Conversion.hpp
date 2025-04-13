/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:31:29 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/13 16:25:37 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

# include <iostream>
# include <sstream>
# include <limits>
# include <cstdlib>
# include <cmath>
# include <iomanip>

class Conversion {
	private:
		Conversion(void);
		Conversion(const Conversion &other);
		~Conversion(void);
		Conversion	&operator=(const Conversion &other);

		static bool	_isChar(const std::string &literal);
		static bool	_isInt(const std::string &literal);
		static bool	_isFloat(const std::string &literal);
		static bool	_isDouble(const std::string &literal);

	public:
		static void	convert(const std::string &input);
};

#endif
