/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:25:15 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/09 04:01:04 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	ft_capitalize(char *str) {
	for (int i = 0; str[i]; i++) {
		str[i] = (char)toupper(str[i]);
	}
}

int	main(int ac, char **av) {
	if (ac > 1) {
		for (int i = 1; av[i]; i++) {
			ft_capitalize(av[i]);
			std::cout << av[i];
			if (i != ac - 1) {
				std::cout << " ";
			}
		}
	} else {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << std::endl;
}
