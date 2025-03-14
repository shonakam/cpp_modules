/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:49:35 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/13 07:53:09 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class	Weapon {
	private:
		std::string	_type;

	public:
		Weapon(std::string type);
		~Weapon(void);
		std::string	&getType(void);
		void		setType(std::string type);
};

#endif
