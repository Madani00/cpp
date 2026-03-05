

// 1 - Pairing and Recursive Sorting: Pair up elements, compare them, and recursively sort the "larger" elements.
// recursion 1: original sequence: [11 2 17 0 16 8 6 15]
// 1.1 - divide elements into pairs : [ (11 2) (17 0) (16 8) (6 15) ] 11 > 2 --> swap 
// 1.2 - sort the pairs :          [ (2 11) (0 17) (8 16) (6 15) ]
// 1.3 - sequence after sorting : [ 2 11 0 17 8 16 6 15 ]
//
// // recursion 2: original sequence: [ 2 11 0 17 8 16 6 15 ]
// 2.1 - divide elements into pairs : [ [(2 11) (0 17)] , [(8 16) (6 15)] ] swap second [] cause 16 > 15
// 2.2 - sort the pairs :          [ [(2 11) (0 17)] , [(6 15) (8 16)] ] 
// 2.3 - sequence after sorting : [ 2 11 0 17 6 15 8 16 ]
// 
// recursion3 : there is nothing to be done ( amount of numbers in the element doubles with each recursion call)
// if number in the pair is long than (array) --> stop

//    - (NOte: need to preserve the original pairing: we can't break pairs formed on the first recursion call on the fifth one.)


// 2 -  Main Chain & Pend: Separate the elements into a "Main Chain" (already sorted) and a "Pend" (elements waiting to be inserted).
// main : [ 2 11 0 17 6 15 8 16 ] (kind of sorted, but not entirely)
// pend [] empty
// Main Chain: Start with the smaller element of the first pair (let's call it b1) and then all the sorted larger elements (a1, a2, a3...).
// Why? Because b1 < a1 and a1 < a2 < a3..., so [b1, a1, a2, a3...] is guaranteed to be sorted.
// Pend: This contains the remaining smaller elements (b2, b3, b4...) and the odd element (if any).
// is short (the main is b1 and the rest of as, the pend is the rest of bs)



// 3 - Binary Insertion via Jacobsthal Numbers: Insert elements from the Pend into the Main Chain in a very specific order to minimize comparisons.
// - Order: b3, then b2. Then b5, then b4. Then b11, b10, b9, b8, b7, b6.

// - Binary Search: Use binary search to find the correct spot for each b element in the Main Chain.

// - Optimization: When inserting bn​, you only need to search the Main Chain up to the position of its partner an​.

#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
    if (ac > 1) {
        
        PmergeMe obj;
        std::vector<int> Myvector;

        for (int i = 1; i < ac; i++)
        {
            std::string arg = av[i];
            for (size_t i = 0; i < arg.size(); i++)
            {
                if (!isdigit(arg[i])) {
                    std::cout << "Error! fchkl" << std::endl;
                    return 1;
                }
            }
            int digit = std::atoi(av[i]);
            Myvector.push_back(digit);
 
        }
        // store the leftover 
        if (Myvector.size() % 2 != 0) {

            int leftover = Myvector[Myvector.size() - 1];
            std::cout << "leftover: " <<  leftover << std::endl;
        }

        std::vector<std::pair<int, int> > pairs;
        for (size_t i = 0; i + 1 < Myvector.size(); i += 2)
        {
            pairs.push_back(std::make_pair(Myvector[i], Myvector[i + 1]));
        }
        
        std::vector<std::pair<int, int> >::const_iterator it;
        for (it = pairs.begin(); it != pairs.end(); ++it) {
            // In C++98, 'it' acts like a pointer, so we use '->'
            std::cout << "(" << it->first << ", " << it->second << ") ";
        }
    }
    else
        std::cout << "Error!" << std::endl;
}