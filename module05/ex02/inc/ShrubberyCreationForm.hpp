/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 00:48:02 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/07 01:32:41 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# define SHRUBBERY_SIGN 145
# define SHRUBBERY_EXEC 137

# include "AForm.hpp"
# include <string>

class ShrubberyCreationForm : public AForm {
	private:
		std::string				_target;
		ShrubberyCreationForm(void);

	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
		virtual					~ShrubberyCreationForm();

		void					execute(const Bureaucrat &executor) const;
};

#endif
