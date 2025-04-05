/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:40:25 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/06 00:33:17 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;
class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
		Form(void);

	public:
		/* <===  OCCF  ===> */
		Form(const std::string &name, int signGrade, int execGrade);
		virtual ~Form(void);
		Form(const Form &other);
		Form &operator=(const Form &other);

		/* <===  Accessors  ===> */
		const std::string	&getName(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		bool				getSigned(void) const;

		/* <===  Member Functions  ===> */
		void				beSigned(const Bureaucrat &bureaucrat);
		
		/* <===  Exceptions  ===> */
		class GradeTooHighException : public std::exception {
			public:
				const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Form &form);

#endif
