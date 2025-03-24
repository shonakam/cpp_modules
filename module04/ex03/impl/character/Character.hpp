/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:46:56 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/25 00:20:42 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"


# include "../../interface/ICharacter.hpp"
# include "../../interface/AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string	_name;
		AMateria	*_materias[4];
		AMateria*	_tmpSlot[100];
		int			_tmpSlotIndex;

	public:
		Character(void);
		Character(const std::string &name);
		virtual	~Character(void);
		Character	&operator=(const Character &other);
		Character(const Character &other);

		std::string const	&getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
};

#endif
