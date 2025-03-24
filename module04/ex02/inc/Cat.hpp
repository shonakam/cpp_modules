/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:10:45 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 22:36:48 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
	private:
		Brain	*_brain;

	public:
		/* <===  Orthodox Canonical Class Form  ===> */
		Cat(void);
		~Cat(void);
		Cat		&operator=(const Cat &other);
		Cat(const Cat &other);

		void		makeSound(void) const;
		std::string	getIdeas(void) const;
		std::string	getIdeaById(int index) const;
		void		setIdeaById(const std::string &idea, int index);
};

#endif
