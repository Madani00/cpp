#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <deque>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <iterator>
#include <sys/time.h>
#include <iomanip>

#include <list>


class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    template <typename Container>
    static Container merge_insertion(Container Myvector);
};

// ─────────────────────────────────────────────────────────────────────────────
// Template helper functions (same logic as main.cpp, generic over Container)
// ─────────────────────────────────────────────────────────────────────────────

template <typename Container>
std::vector<std::pair<int, int> > t_extract_biggest(std::vector<std::pair<int, int> > pairs) {
    std::vector<int> main_vec;
    typename std::vector<std::pair<int, int> >::const_iterator it = pairs.begin();
    for (; it != pairs.end(); ++it)
        main_vec.push_back(it->second);
    return pairs; // returns pairs; winners extracted inside merge_insertion
}

template <typename Container>
std::vector<int> t_jacob_numbers(size_t sizePend) {
    std::vector<int> jn;
    if (sizePend == 0) return jn;
    jn.push_back(3);
    jn.push_back(5);
    for (size_t i = 1; i < sizePend; i++) {
        size_t next = jn[i] + 2 * jn[i - 1];
        if (next >= sizePend) 
            break;
        jn.push_back(next);
    }
    return jn;
}

template <typename Container>
std::vector<int> t_generate_jacob_order(size_t sizePend) {
    std::vector<int> jacob_order;
    std::vector<int> jacob_numb = t_jacob_numbers<Container>(sizePend);
    for (size_t i = 0; i < jacob_numb.size(); i++) {
        jacob_order.push_back(jacob_numb[i]);
        jacob_order.push_back(jacob_numb[i] - 1);
    }

     // append any index from 2..sizePend not already in jacob_order
    // (index 1 is skipped because pend[0] is always inserted first separately)
    for (size_t x = 2; x <= sizePend; x++)
    {
        bool found = false;
        for (size_t i = 0; i < jacob_order.size(); i++)
        {
            if ((size_t)jacob_order[i] == x)
            {
                found = true;
                break;
            }
        }
        if (!found)
            jacob_order.push_back(x);
    }

    return jacob_order;
}

template <typename Container>
Container t_begin_insertion(Container main_chain, Container pend) {
    // Insert the first pend element at the beginning of main_chain
    main_chain.insert(main_chain.begin(), pend[0]);

    // Generate Jacobsthal insertion order
    std::vector<int> jacob_order = t_generate_jacob_order<Container>(pend.size());

    // Insert remaining pend elements using binary search
    int target;
    for (size_t i = 0; i < jacob_order.size(); i++) {
        if (jacob_order[i] - 1 >= (int)pend.size())
            continue;
        target = pend[jacob_order[i] - 1];

        typename Container::iterator it;
        it = std::lower_bound(main_chain.begin(), main_chain.end(), target);
        size_t index = std::distance(main_chain.begin(), it);
        main_chain.insert(main_chain.begin() + index, target);
    }
    return main_chain;
}

template <typename Container>
std::vector<std::pair<int, int> > t_sort_pairs_recursive(std::vector<std::pair<int, int> > pairs) {
    if (pairs.size() <= 1)
        return pairs;

    // Extract larger elements for recursive sorting
    std::vector<int> larger_elements;
    for (size_t i = 0; i < pairs.size(); i++)
        larger_elements.push_back(pairs[i].second);

    Container larger_cont(larger_elements.begin(), larger_elements.end());
    Container sorted_cont = PmergeMe::merge_insertion(larger_cont);
    std::vector<int> sorted_larger(sorted_cont.begin(), sorted_cont.end());

    // Reorder pairs to match sorted larger elements
    std::vector<std::pair<int, int> > sorted_pairs;
    for (size_t i = 0; i < sorted_larger.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].second == sorted_larger[i]) {
                sorted_pairs.push_back(pairs[j]);
                break;
            }
        }
    }
    return sorted_pairs;
}

template <typename Container>
Container PmergeMe::merge_insertion(Container Myvector) {

    if (Myvector.size() <= 1)
        return Myvector;

    // Handle leftover element
    int leftover = -1;
    if (Myvector.size() % 2 != 0) {
        leftover = Myvector[Myvector.size() - 1];
        Myvector.pop_back();
    }

    // Create pairs (smaller, larger)
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < Myvector.size(); i += 2) {
        if (Myvector[i] < Myvector[i + 1])
            pairs.push_back(std::make_pair(Myvector[i], Myvector[i + 1]));
        else
            pairs.push_back(std::make_pair(Myvector[i + 1], Myvector[i]));
    }

    // Recursively sort pairs by their larger element, maintaining pairing
    pairs = t_sort_pairs_recursive<Container>(pairs);

    // Build main_chain and pend from sorted pairs
    Container main_chain;
    for (size_t i = 0; i < pairs.size(); i++)
        main_chain.push_back(pairs[i].second);

    Container pend;
    for (size_t i = 0; i < pairs.size(); i++)
        pend.push_back(pairs[i].first);
    if (leftover >= 0)
        pend.push_back(leftover);

    main_chain = t_begin_insertion<Container>(main_chain, pend);

    return main_chain;
}