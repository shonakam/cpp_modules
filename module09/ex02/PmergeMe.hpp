/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 07:31:00 by shonakam          #+#    #+#             */
/*   Updated: 2025/08/10 22:10:42 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "ANSI.h"

#define DEBUGMODE false

class PmergeMe {
 private:
  PmergeMe(void);
  PmergeMe(const PmergeMe& other);
  ~PmergeMe(void);
  PmergeMe& operator=(const PmergeMe& other);

  static void mergeInsertSort(std::vector<int>&);
  static void mergeInsertSort(std::deque<int>&);
  static void insertPendingElements(std::vector<int>&, const std::vector<int>&);
  static void insertPendingElements(std::deque<int>&, const std::deque<int>&);

 public:
  static void run(int, char**);
};

// ==========================
//  TEMPLATE FUNCTIONS
// ==========================

template <typename ContainerU, typename ContainerV>
bool isEqual(const ContainerU& u, const ContainerV& v) {
  if (u.size() != v.size())
    return false;
  typename ContainerU::const_iterator it1 = u.begin();
  typename ContainerV::const_iterator it2 = v.begin();

  for (; it1 != u.end(); ++it1, ++it2) {
    if (*it1 != *it2)
      return false;
  }
  return true;
}

template <typename Container>
void parseInput(int argc, char** argv, Container& container) {
  for (int i = 1; i < argc; ++i) {
    std::istringstream iss(argv[i]);
    int num;
    if (!(iss >> num) || num < 0) {
      throw std::runtime_error("Error");
    }
    container.push_back(num);
  }
}

template <typename Container>
void printSequence(const std::string& label, const Container& container) {
  std::cout << label;
  typename Container::const_iterator it = container.begin();
  for (; it != container.end(); ++it) {
    std::cout << *it;
    if (std::next(it) != container.end()) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}

template <typename Func, typename Arg>
double benchmark(const Func& fn, Arg& arg) {
  clock_t s = clock();
  fn(arg);
  clock_t e = clock();
  return static_cast<double>(e - s) * 1e6 / CLOCKS_PER_SEC;
}

template <typename Container>
int extractStraggler(Container& container) {
  int straggler = -1;
  if (container.size() % 2 != 0) {
    straggler = container.back();
    container.pop_back();
  }
  return straggler;
}
