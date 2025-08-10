/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 07:30:49 by shonakam          #+#    #+#             */
/*   Updated: 2025/08/10 23:18:50 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
}
PmergeMe::~PmergeMe(void) {
}
PmergeMe::PmergeMe(const PmergeMe& other) {
  (void)other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  (void)other;
  return *this;
}

void PmergeMe::run(int ac, char** av) {
  std::vector<int> vector_data;
  std::deque<int> deque_data;
  double vector_sequence_time, deque_sequence_time;

  parseInput(ac, av, vector_data);
  parseInput(ac, av, deque_data);

  printSequence("Before:", vector_data);
  vector_sequence_time = benchmark(
      static_cast<void (*)(std::vector<int>&)>(PmergeMe::mergeInsertSort),
      vector_data);
  deque_sequence_time = benchmark(
      static_cast<void (*)(std::deque<int>&)>(PmergeMe::mergeInsertSort),
      deque_data);
  printSequence("After :", vector_data);
  std::cout << "Time to process a range of " << vector_data.size()
            << " elements with std::vector : " << vector_sequence_time
            << " us\n";
  std::cout << "Time to process a range of " << deque_data.size()
            << " elements with std::deque  : " << deque_sequence_time
            << " us\n";
}

// ==========================
//  UTILE FUNCTIONS
// ==========================

/**
 * @brief Generates Jacobsthal numbers to determine the optimal insertion order.
 * This sequence ensures that we insert elements from smaller groups first,
 * keeping the binary search range as small as possible.
 * Jn = Jn−1 + 2Jn−2
 */
static std::vector<size_t> generateJacobsthalIndices(size_t n) {
  std::vector<size_t> indices;
  if (n == 0)
    return indices;

  size_t J0 = 1, J1 = 3;
  while (J0 < n) {
    indices.push_back(J1 < n ? J1 : n);
    size_t Jn = J1 + 2 * J0;
    J0 = J1;
    J1 = Jn;
  }
  return indices;
}

// ==========================
//  VECTOR ALGORLITHM
// ==========================

void PmergeMe::insertPendingElements(std::vector<int>& main_chain,
                                     const std::vector<int>& pending_list) {
  if (pending_list.empty())
    return;
  std::vector<size_t> jacob_indices =
      generateJacobsthalIndices(pending_list.size());
  size_t last_inserted_end = 1;

  main_chain.insert(main_chain.begin(), pending_list[0]);

  for (size_t i = 0; i < jacob_indices.size(); i++) {
    size_t group_end = jacob_indices[i];

    for (size_t j = group_end; j > last_inserted_end; j--) {
      if (j - 1 >= pending_list.size())
        continue;

      int value_to_insert = pending_list[j - 1];
      // https://cpprefjp.github.io/reference/algorithm/lower_bound.html
      std::vector<int>::iterator pos = std::lower_bound(
          main_chain.begin(), main_chain.end(), value_to_insert);
      main_chain.insert(pos, value_to_insert);
    }
    last_inserted_end = group_end;
  }
}

/*
 * STEPS:
 *   - Check data size.
 *   - Extract straggler.
 *   - Create pairs.
 *   - Building mainchain -> recursive.
 *   - Building a pending list while tracking the mainchain.
 *   - Insert pendinglist elements into the mainchain.
 *   - Insert straggler into mainchain.
 *
 * Reerence:
 *   -
 * https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
 */
void PmergeMe::mergeInsertSort(std::vector<int>& main_chain) {
  if (main_chain.size() < 2)
    return;

  int straggler = extractStraggler(main_chain);

  std::vector<std::pair<int, int> > pairs;
  for (size_t i = 0; i < main_chain.size(); i += 2) {
    (main_chain[i] > main_chain[i + 1])
        ? pairs.push_back(std::make_pair(main_chain[i + 1], main_chain[i]))
        : pairs.push_back(std::make_pair(main_chain[i], main_chain[i + 1]));
  }

  std::vector<int> next_main, pending_list;
  for (size_t i = 0; i < pairs.size(); i++) {
    next_main.push_back(pairs[i].second);
  }
  mergeInsertSort(next_main);

  for (size_t i = 0; i < next_main.size(); i++) {
    int winner = next_main[i];

    for (size_t j = 0; j < pairs.size(); j++) {
      if (pairs[j].second == winner) {
        pending_list.push_back(pairs[j].first);
        break;
      }
    }
  }
  insertPendingElements(next_main, pending_list);

  if (straggler != -1) {
    std::vector<int>::iterator pos =
        std::lower_bound(next_main.begin(), next_main.end(), straggler);
    next_main.insert(pos, straggler);
  }
  main_chain = next_main;
}

// ==========================
//  DEQUE ALGORLITHM
// ==========================

void PmergeMe::insertPendingElements(std::deque<int>& main_chain,
                                     const std::deque<int>& pending_list) {
  if (pending_list.empty())
    return;
  std::vector<size_t> jacob_indices =
      generateJacobsthalIndices(pending_list.size());
  size_t last_inserted_end = 1;

  // Using push_front() is highly efficient for std::deque.
  main_chain.push_front(pending_list[0]);

  for (size_t i = 0; i < jacob_indices.size(); i++) {
    size_t group_end = jacob_indices[i];

    for (size_t j = group_end; j > last_inserted_end; j--) {
      if (j - 1 >= pending_list.size())
        continue;

      // Its memory is not contiguous like a vector's, so using iterators is a
      // robust practice.
      int value_to_insert = *(pending_list.begin() + (j - 1));
      std::deque<int>::iterator pos = std::lower_bound(
          main_chain.begin(), main_chain.end(), value_to_insert);
      main_chain.insert(pos, value_to_insert);
    }
    last_inserted_end = group_end;
  }
}

void PmergeMe::mergeInsertSort(std::deque<int>& main_chain) {
  if (main_chain.size() < 2)
    return;

  int straggler = extractStraggler(main_chain);

  std::deque<std::pair<int, int> > pairs;
  for (size_t i = 0; i < main_chain.size(); i += 2) {
    (main_chain[i] > main_chain[i + 1])
        ? pairs.push_back(std::make_pair(main_chain[i + 1], main_chain[i]))
        : pairs.push_back(std::make_pair(main_chain[i], main_chain[i + 1]));
  }

  std::deque<int> next_main, pending_list;
  for (size_t i = 0; i < pairs.size(); i++) {
    next_main.push_back(pairs[i].second);
  }

  mergeInsertSort(next_main);

  for (size_t i = 0; i < next_main.size(); i++) {
    int winner = next_main[i];

    for (size_t j = 0; j < pairs.size(); j++) {
      if (pairs[j].second == winner) {
        pending_list.push_back(pairs[j].first);
        break;
      }
    }
  }

  insertPendingElements(next_main, pending_list);
  if (straggler != -1) {
    std::deque<int>::iterator pos =
        std::lower_bound(next_main.begin(), next_main.end(), straggler);
    next_main.insert(pos, straggler);
  }
  main_chain = next_main;
}
