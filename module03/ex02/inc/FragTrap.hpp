/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:10:05 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 03:20:57 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		FragTrap(void);

	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		FragTrap	&operator=(const FragTrap &other);
		~FragTrap(void);

		void highFivesGuys(void);
};

#endif
