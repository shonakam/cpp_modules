/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:40:25 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/07 00:32:04 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;
class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
		AForm(void);

	protected:
		void	checkExecutability(const Bureaucrat &executor) const;

	public:
		/* <===  OCCF  ===> */
		AForm(const std::string &name, int signGrade, int execGrade);
		virtual ~AForm(void);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);

		/* <===  Accessors  ===> */
		const std::string	&getName(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		bool				getSigned(void) const;

		/* <===  Member Functions  ===> */
		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(const Bureaucrat &executor) const = 0;
		
		/* <===  Exceptions  ===> */
		class GradeTooHighException : public std::exception {
			public:
				const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what(void) const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				const char *what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const AForm &form);

#endif
