/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 01:16:26 by shonakam          #+#    #+#             */
/*   Updated: 2025/08/08 03:12:24 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Error: usage: ./RPN \"<expression>\"" << std::endl;
    return EXIT_FAILURE;
  }

  try {
    double result = RPN::run(argv[1]);
    std::cout << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
