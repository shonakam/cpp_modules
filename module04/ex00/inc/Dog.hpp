/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:00:03 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 15:08:12 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
	public:
		/* <===  Orthodox Canonical Class Form  ===> */
		Dog(void);
		virtual	~Dog(void);
		Dog		&operator=(const Dog &other);
		Dog(const Dog &other);

		void	makeSound(void) const;
};

#endif
