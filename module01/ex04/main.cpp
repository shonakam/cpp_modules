/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:39:23 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/14 12:27:11 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>


/* 
 * newline are not taken into account
 * partial matches are not supported
*/
void	replaceTarget(
	std::string &line,
	const std::string target,
	const std::string replace
) {
	if (target.empty()) return;
	size_t	pos = 0;

	while ((pos = line.find(target, pos)) != std::string::npos) {
		line.erase(pos, target.length());
		line.insert(pos, replace);
		pos += replace.length();
	}
}

void	processFile(
	std::string file,
	const std::string target,
	const std::string replace
) {
	std::ifstream	ifs(file.c_str());
	std::ofstream	ofs((file + ".replace").c_str());
	std::string		line;

	if (ifs.fail() || ofs.fail()) {
		std::cout << "Failed to open file" << std::endl;
		exit(1);
	}
	while (std::getline(ifs, line)) {
		replaceTarget(line, target, replace);
		ofs << line << std::endl;
	}
}

int	main(int ac, char **av) {
	if (ac != 4) return (std::cout << "Error: Invalid number of arguments." << std::endl, 0);
	processFile(av[1], av[2], av[3]);
}
