/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:07:47 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 23:12:51 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

# include <iostream>

// This class enforces a contract for all animals to implement makeSound(),
// making it impossible to instantiate AAnimal directly.
class AAnimal {
	protected:
		std::string	_type;

	public:
		/* <===  Orthodox Canonical Class Form  ===> */
		AAnimal(void);
		virtual	~AAnimal(void);
		AAnimal	&operator=(const AAnimal &other);
		AAnimal(const AAnimal &other);

		// https://en.cppreference.com/w/cpp/language/abstract_class
		// https://cplusplus.com/doc/tutorial/polymorphism/
		virtual void	makeSound(void) const = 0;

		/* <===  ACCESSERS  ===> */
		std::string	getType(void) const;
		void		setType(const std::string &type);
};

#endif
