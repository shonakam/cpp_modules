/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:30:54 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 03:12:57 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

# include <string>
# include <iostream>

class ClapTrap
{
	private:
		ClapTrap(void); // default constructor
	
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		/* <===  Orthodox Canonical Form  ===> */
		ClapTrap(const ClapTrap &other);
		ClapTrap	&operator=(const ClapTrap &other);
		virtual		~ClapTrap(void);
		// ==  Additional Constractor  ==========
		ClapTrap(std::string name);

		virtual void	attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

};

#endif
