/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:13:33 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 17:31:28 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	protected:
		std::string _type;

	public:
		/* <===  Orthodox Canonical Class Form  ===> */
		WrongAnimal(void);
		virtual		~WrongAnimal(void);
		WrongAnimal	&operator=(const WrongAnimal &other);
		WrongAnimal(const WrongAnimal &other);

		void		makeSound(void) const;
		std::string	getType(void) const;
		void		setType(const std::string &type);
};

#endif
