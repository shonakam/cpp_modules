/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:10:45 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 16:49:04 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	public:
		/* <===  Orthodox Canonical Class Form  ===> */
		Cat(void);
		~Cat(void);
		Cat		&operator=(const Cat &other);
		Cat(const Cat &other);

		void	makeSound(void) const;
};

#endif
