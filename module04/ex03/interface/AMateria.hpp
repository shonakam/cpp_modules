/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:07:07 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 23:59:25 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMAATERIAL_HPP
# define AMAATERIAL_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria {
	protected:
		std::string	_type;

	public:
		AMateria(void);
		virtual		~AMateria(void);
		AMateria	&operator=(const AMateria &other);
		AMateria(const AMateria &other);
		AMateria(const std::string &type);

		std::string const	&getType(void) const;
		virtual	AMateria	*clone(void) const = 0;
		virtual	void		use(ICharacter &target);
};

#endif
