/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:46:58 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/08 21:30:35 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <iostream>

class AForm;
class Intern {
	private:
		typedef AForm	*(Intern::*FormCreationFunc)(const std::string &target);
		static AForm	*createShrubbery(const std::string &target);
		static AForm	*createRobotomy(const std::string &target);
		static AForm	*createPresidential(const std::string &target);

	public:
		Intern(void);
		Intern(const Intern &other);
		~Intern(void);
		Intern &operator=(const Intern &other);

		AForm	*makeForm(const std::string &formName, const std::string &target);
		
		class FormNotFoundException : public std::exception {
			public:
				const char *what(void) const throw();
		};
};

#endif
