/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:44:49 by shonakam          #+#    #+#             */
/*   Updated: 2025/08/06 23:03:26 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"

#define DATA_FILE "data/data.csv"

int main(int argc, char** argv) {
  (void)argc;
  (void)argv;
  // if (argc != 2) {
  //   std::cerr << "ERRMSG_00" << std::endl;
  //   return EXIT_FAILURE;
  // }

  try {
    // BitcoinExchange::btcExchange(argv[1], DATA_FILE);
    BitcoinExchange::run("data/input.txt", DATA_FILE);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
