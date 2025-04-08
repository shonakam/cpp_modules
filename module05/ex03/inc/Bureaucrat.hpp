/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:47:47 by shonakam          #+#    #+#             */
/*   Updated: 2025/04/08 21:45:28 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

# define GRADE_MAX 1
# define GRADE_MIN 150

# include <iostream>

class AForm;
class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
		Bureaucrat(void);

	public:
		/* <===  OCCF  ===> */
		Bureaucrat(const std::string &name, int grade);
		virtual	~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat	&operator=(const Bureaucrat &other);

		/* <===  Accessors  ===> */
		const std::string	&getName(void) const;
		int					getGrade(void) const;

		/* <===  Member Functions  ===> */
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(AForm &form);
		void				executeForm(const AForm &form) const;

		/* <===  Exceptions  ===> */
		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
