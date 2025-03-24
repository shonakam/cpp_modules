/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:54:12 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 16:49:11 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		/* <===  Orthodox Canonical Class Form  ===> */
		WrongCat(void);
		~WrongCat(void);
		WrongCat	&operator=(const WrongCat &other);
		WrongCat(const WrongCat &other);

		void	makeSound(void) const;
};

#endif
