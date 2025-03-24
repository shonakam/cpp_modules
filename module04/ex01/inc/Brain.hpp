/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:14:44 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 18:47:13 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	private:
		std::string _ideas[100];

	public:
		Brain(void);
		virtual	~Brain(void);
		Brain	&operator=(const Brain &other);
		Brain(const Brain &other);

		void		setIdeaById(const std::string &idea, int index);
		std::string	getIdeas(void) const;
		std::string	getIdeaById(int index) const;
};

#endif