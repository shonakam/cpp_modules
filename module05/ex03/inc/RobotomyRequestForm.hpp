/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:16:04 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/07 01:32:52 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# define ROBOTOMY_SIGN 72
# define ROBOTOMY_EXEC 45

# include "AForm.hpp"
# include <string>

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
		RobotomyRequestForm(void);

	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);
		virtual				~RobotomyRequestForm(void);

		void				execute(const Bureaucrat &executor) const;
};

#endif