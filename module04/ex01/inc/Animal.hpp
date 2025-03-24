/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:07:47 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 17:18:53 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

# include <iostream>

class Animal {
	protected:
		std::string	_type;

	public:
		/* <===  Orthodox Canonical Class Form  ===> */
		Animal(void);
		virtual	~Animal(void);
		Animal	&operator=(const Animal &other);
		Animal(const Animal &other);

		virtual void		makeSound(void) const;

		/* <===  ACCESSERS  ===> */
		std::string	getType(void) const;
		void		setType(const std::string &type);
};

#endif
