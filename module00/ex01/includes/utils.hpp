/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:11:08 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/12 04:05:53 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>
# include <istream>

std::string		trim(const std::string& str);
std::string		strShorten(const std::string &str, unsigned int from = 9);
void			checkEOF(std::istream& in);


#endif
