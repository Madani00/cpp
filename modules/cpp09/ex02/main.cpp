#include "PmergeMe.hpp"

void Printpair(std::vector<std::pair<int, int> > pairs) {
    std::vector<std::pair<int, int> >::const_iterator it;
    for (it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
}

void PrintVec(std::vector<int> pairs) {
    // std::cout << "Before:   ";
    std::vector<int>::const_iterator it;
    for (it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


// std::vector<int> merge_insertion(std::vector<int> Myvector);

// static size_t g_traceDepth = 0;
// static size_t g_traceIter = 0;

// struct TraceScope {
//     size_t depth;
//     size_t iter;

//     TraceScope() {
//         ++g_traceDepth;
//         depth = g_traceDepth;
//         ++g_traceIter;
//         iter = g_traceIter;
//     }

//     ~TraceScope() {
//         --g_traceDepth;
//     }
// };

// void PrintIndent(size_t depth) {
//     for (size_t i = 1; i < depth; ++i)
//         std::cout << "\t";
// }

// void PrintVecInline(const std::vector<int>& v) {
//     std::cout << "[";
//     for (size_t i = 0; i < v.size(); ++i) {
//         if (i > 0)
//             std::cout << ", ";
//         std::cout << v[i];
//     }
//     std::cout << "]";
// }

// void PrintPairsInline(const std::vector<std::pair<int, int> >& pairs) {
//     for (size_t i = 0; i < pairs.size(); ++i) {
//         if (i > 0)
//             std::cout << ", ";
//         std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")";
//     }
// }


// std::vector<int> extract_biggest(std::vector<std::pair<int, int> > pairs) {

//     std::vector<int> main;


//     std::vector<std::pair<int, int> >::const_iterator it;

//     // i added this line to make sure the first element of the first pair is in the main chain, as it is smaller than the first element in main
//     it = pairs.begin();
//     // main.push_back(it->first);

//     for (; it != pairs.end(); it++)
//     {
//         main.push_back(it->second);
//     }
//     return main;
// }

// std::vector<int> extract_smallest(std::vector<std::pair<int, int> > pairs, std::vector<int> Myvector) {

//     std::vector<int> pend;
//     // store the leftover
//     int leftover = -1; 
//     if (Myvector.size() % 2 != 0) {
//         leftover = Myvector[Myvector.size() - 1];
//         std::cout << "leftover: " <<  leftover << std::endl;
//     }

//     std::vector<std::pair<int, int> >::const_iterator it;
//     for (it = pairs.begin(); it != pairs.end(); ++it) {
//         pend.push_back(it->first);
//     }
//     // add the left number to pend
//     if (leftover >= 0)
//         pend.push_back(leftover);
//     return pend;
// }

// std::vector<int> jacob_numbers(size_t sizePend) {
//     std::vector<int> jacob_numbers;
//      if (sizePend == 0) return jacob_numbers;

//     jacob_numbers.push_back(3);
//     jacob_numbers.push_back(5);
//     size_t nextNm;
//     for (size_t i = 1; i < sizePend; i++)
//     {
//         nextNm = jacob_numbers[i] + 2 * jacob_numbers[i-1];
//         if (nextNm >= sizePend)
//             break;
//         jacob_numbers.push_back(nextNm);
//     }
//     return jacob_numbers;
// }

// std::vector<int> generate_jacob_order(size_t sizePend) {
//     std::vector<int> jacob_order;

//     std::vector<int> jacob_numb = jacob_numbers(sizePend);

//     for (size_t i = 0; i < jacob_numb.size(); i++)
//     {
//         jacob_order.push_back(jacob_numb[i]);
//         jacob_order.push_back(jacob_numb[i] - 1);
//     }

//     // append any index from 2..sizePend not already in jacob_order
//     // (index 1 is skipped because pend[0] is always inserted first separately)
//     for (size_t x = 2; x <= sizePend; x++)
//     {
//         bool found = false;
//         for (size_t i = 0; i < jacob_order.size(); i++)
//         {
//             if ((size_t)jacob_order[i] == x)
//             {
//                 found = true;
//                 break;
//             }
//         }
//         if (!found)
//             jacob_order.push_back(x);
//     }

//     return jacob_order;
// }

// std::vector<int> begin_insertion(std::vector<int> main_chain, std::vector<int> pend) {
//     // Insert the first pend element at the beginning of main_chain
//     main_chain.insert(main_chain.begin(), pend[0]);
//     PrintIndent(g_traceDepth);
//     std::cout << "- Main-chain (after insert first element) : ";
//     PrintVecInline(main_chain);
//     std::cout << std::endl;
    
//     // Generate Jacobsthal insertion order
//     std::vector<int> jacob_order = generate_jacob_order(pend.size());
//     PrintIndent(g_traceDepth);
//     std::cout << "- Jacob order: ";
//     PrintVecInline(jacob_order);
//     std::cout << std::endl;
    
//     // Insert remaining pend elements using binary search
//     int target;
//     for (size_t i = 0; i < jacob_order.size(); i++)
//     {                                               // pend size = 4
//         if (jacob_order[i] - 1 >= (int)pend.size()) // [jacob_order: 2, 1, 4, 3, 5] if the order is bigger than the size of pend, just skip it
//             continue;
//         target = pend[jacob_order[i] - 1]; // [3 - 1]


//         // Binary search for insertion position
//         std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), target);
//         size_t index = std::distance(main_chain.begin(), it);
//         main_chain.insert(main_chain.begin() + index, target); 
//         PrintIndent(g_traceDepth);
//         std::cout << "+ insert " << target << " at index " << index << " in main-chain";
//         std::cout << std::endl;
//     }

//     PrintIndent(g_traceDepth);
//     std::cout << "- Pending = ";
//     PrintVecInline(pend);
//     std::cout << "    Main-chain: ";
//     PrintVecInline(main_chain);
//     std::cout << std::endl;
//     std::cout << std::endl;
//     return main_chain;
// }



// // Helper to recursively sort pairs by their larger element
// std::vector<std::pair<int, int> > sort_pairs_recursive(std::vector<std::pair<int, int> > pairs) {
//     if (pairs.size() <= 1)
//         return pairs;
    
//     // Extract larger elements for recursive sorting
//     std::vector<int> larger_elements = extract_biggest(pairs); // [50 , 4 ,  2, 9]
//     PrintIndent(g_traceDepth);
//     std::cout << "- Winners to recurse: ";
//     PrintVecInline(larger_elements);
//     std::cout << std::endl;
//     std::vector<int> sorted_larger = merge_insertion(larger_elements); // [4, 50, 2, 9]

    
//     // Reorder pairs to match sorted larger elements
//     std::vector<std::pair<int, int> > sorted_pairs;
//     for (size_t i = 0; i < sorted_larger.size(); i++) {
//         for (size_t j = 0; j < pairs.size(); j++) {
//             if (pairs[j].second == sorted_larger[i]) {
//                 sorted_pairs.push_back(pairs[j]);
//                 break;
//             }
//         }
//     }
//     // PrintIndent(g_traceDepth);
//     // std::cout << "--> Reorder pairs smaller to bigger: ";
//     //  PrintPairsInline(sorted_pairs);
//     return sorted_pairs;
// }

// std::vector<int> merge_insertion(std::vector<int> Myvector) {

//     TraceScope trace;

//     PrintIndent(trace.depth);
//     std::cout << "###ITERATION NUM " << trace.iter << "###" << std::endl;
//     PrintIndent(trace.depth);
//     std::cout << "- Numbers to sort: ";
//     PrintVecInline(Myvector);
//     std::cout << std::endl;
//     PrintIndent(trace.depth);
//     std::cout << "- Pending = ()    Main-chain: ()" << std::endl;

//     if (Myvector.size() <= 1)
//         return Myvector;

//     // Handle leftover element
//     int leftover = -1;
//     bool hasLeftover = false;
//     if (Myvector.size() % 2 != 0) {
//         leftover = Myvector[Myvector.size() - 1];
//         hasLeftover = true;
//         PrintIndent(trace.depth);
//         std::cout << "- leftover (add it to Pend) : " << leftover;
//         std::cout << std::endl;
//     }

//     // Create pairs (smaller, larger)
//     std::vector<std::pair<int, int> > original_pairs;
//     std::vector<std::pair<int, int> > pairs;
//     for (size_t i = 0; i + 1 < Myvector.size(); i += 2)
//     {
//         original_pairs.push_back(std::make_pair(Myvector[i], Myvector[i + 1]));
//         if (Myvector[i] < Myvector[i + 1])
//             pairs.push_back(std::make_pair(Myvector[i], Myvector[i + 1]));
//         else
//             pairs.push_back(std::make_pair(Myvector[i + 1], Myvector[i]));
//     }
//     // PrintIndent(trace.depth);
//     // std::cout << "- Original pairs: ";
//     // PrintPairsInline(original_pairs);
//     // if (hasLeftover) {
//     //     if (!original_pairs.empty())
//     //         std::cout << ", ";
//     //     std::cout << "(" << leftover << ", NULL)";
//     // }
//     // std::cout << std::endl;

//     PrintIndent(trace.depth);
//     std::cout << "- Sorted pairs: ";
//     PrintPairsInline(pairs);
//     std::cout << std::endl;

//     // Recursively sort pairs by their larger element, maintaining pairing
//     pairs = sort_pairs_recursive(pairs);

//     std::cout << std::endl;
//     PrintIndent(trace.depth);
//     std::cout << "--> Pairs ordered by winners: ";
//     PrintPairsInline(pairs);
//     std::cout << std::endl;
    
//     // Build main_chain and pend from sorted pairs
//     std::vector<int> main_chain = extract_biggest(pairs);
//     std::vector<int> pend;
//     for (size_t i = 0; i < pairs.size(); i++) {
//         pend.push_back(pairs[i].first);
//     }
//     if (leftover >= 0)
//         pend.push_back(leftover);

//     PrintIndent(trace.depth);
//     std::cout << "- Pending = ";
//     PrintVecInline(pend);
//     std::cout << "    Main-chain: ";
//     PrintVecInline(main_chain);
//     std::cout << std::endl;


//     main_chain = begin_insertion(main_chain, pend);

//     return main_chain;
// }


int main(int ac, char *av[]) 
{
    struct timeval start, end;
    if (ac > 1) {
        std::vector<int> Myvector;
        std::deque<int>  Mydeque;

        for (int i = 1; i < ac; i++)
        {
            std::string arg = av[i];
            for (size_t j = 0; j < arg.size(); j++)
            {
                if (!isdigit(arg[j])) {
                    std::cerr << "Error" << std::endl;
                    return 1;
                }
            }
            int digit = std::atoi(av[i]);
            Myvector.push_back(digit);
            Mydeque.push_back(digit);
        }

        std::cout << "Before:  ";
        PrintVec(Myvector);

        // // ── vector ──────────────────────────────────────────────────────
        gettimeofday(&start, NULL);
        std::vector<int> sortedVec = PmergeMe::merge_insertion(Myvector);
        gettimeofday(&end, NULL);
        long vecUs = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

        std::cout << "After:   ";
        PrintVec(sortedVec);

        // ── deque ───────────────────────────────────────────────────────
        gettimeofday(&start, NULL);
        std::deque<int> sortedDeq = PmergeMe::merge_insertion(Mydeque);
        gettimeofday(&end, NULL);
        long deqUs = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

        std::cout << "Time to process a range of " << Myvector.size()
                  << " elements with std::vector : "
                  << std::fixed << std::setprecision(5) << (double)vecUs << " us" << std::endl;
        std::cout << "Time to process a range of " << Mydeque.size()
                  << " elements with std::deque  : "
                  << std::fixed << std::setprecision(5) << (double)deqUs << " us" << std::endl;
    }
    else
        std::cerr << "Error" << std::endl;
}