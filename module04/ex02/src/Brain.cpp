/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:22:38 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/24 19:11:30 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain:	has been created!" << std::endl;
	for (int i = 0; i < 100; i++) _ideas[i] = "";
}
Brain::~Brain(void) { std::cout << "Brain:	has been destroyed!" << std::endl; }

/* <===  DEEP COPY  ===> */
Brain::Brain(const Brain &other) { *this = other; }
Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) _ideas[i] = other.getIdeaById(i);
	}
	return *this;
}

void	Brain::setIdeaById(const std::string &idea, int index) {
	if (index < 0 || index >= 100) return ;
	_ideas[index] = idea;
}

std::string	Brain::getIdeas(void) const {
	std::string ideas;
	for (int i = 0; i < 100; i++) ideas += _ideas[i] + " ";
	return ideas;
}

std::string	Brain::getIdeaById(int index) const {
	if (index < 0 || index >= 100) return "";
	return _ideas[index];
}
