/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:06:58 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/12 05:10:33 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "utils.hpp"
# include <iostream>
# include <iomanip>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"
# define ERR_INVALID_PHONE RED "⚠ Invalid phone number. Please enter only digits.\n" RESET
# define ERR_EMPTY_INPUT RED "⚠ Empty input is not allowed. Please try again.\n" RESET
# define MAX_CONTACTS 8

class PhoneBook {
	private:
		Contact		_contacts[MAX_CONTACTS];
		void		printList(void) const;
		void		printDetails(void) const;
		void		shiftContact(Contact contacts[], const Contact& newContact);
		std::string	getInformation(const std::string& prompt);

	public:
		PhoneBook();
		~PhoneBook();
		void	add();
		void	search() const;
};

#endif
