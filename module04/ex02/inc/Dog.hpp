/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:00:03 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 21:06:33 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain	*_brain;

	public:
		/* <===  Orthodox Canonical Class Form  ===> */
		Dog(void);
		virtual	~Dog(void);
		Dog		&operator=(const Dog &other);
		Dog(const Dog &other);

		void		makeSound(void) const;
		std::string	getIdeas(void) const;
		std::string	getIdeaById(int index) const;
		void		setIdeaById(const std::string &idea, int index);
};

#endif
