/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:17:23 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/07 01:34:21 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# define PRESIDENTIAL_SIGN 25
# define PRESIDENTIAL_EXEC 5

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm {
	private:
		std::string				_target;
		PresidentialPardonForm(void);

	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
		virtual					~PresidentialPardonForm(void);

		void					execute(const Bureaucrat &executor) const;
};

#endif
