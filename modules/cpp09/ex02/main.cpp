

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

void Printpair(std::vector<std::pair<int, int> > pairs) {
    std::vector<std::pair<int, int> >::const_iterator it;
    for (it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
}

void PrintVec(std::vector<int> pairs) {
    // std::cout << "Before:   ";
    std::vector<int>::const_iterator it;
    for (it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// FUNCTION PmergeMe(input_data):
//     IF input_data.size < 2:
//         RETURN input_data

//     // 1. CREATE PAIRS
//     pairs = []
//     extra = NULL
//     IF input_data.size is odd:
//         extra = input_data.pop_back()

//     FOR i FROM 0 TO input_data.size STEP 2:
//         IF input_data[i] < input_data[i+1]:
//             pairs.add( {small: input_data[i], large: input_data[i+1]} )
//         ELSE:
//             pairs.add( {small: input_data[i+1], large: input_data[i]} )

//     // 2. RECURSIVE SORTING
//     // Extract 'large' elements to sort them
//     larges_to_sort = [p.large for p in pairs]
//     sorted_larges = PmergeMe(larges_to_sort)

//     // 3. RE-BUILD RELATIONSHIPS
//     // Rearrange 'small' elements (pend) to match the new order of 'large' (main)
//     main_chain = []
//     pend = []
//     FOR each val IN sorted_larges:
//         main_chain.add(val)
//         // Find the original 'small' partner for this 'large' value
//         pend.add(find_partner_of(val, pairs))
    
//     IF extra is NOT NULL:
//         pend.add(extra)

//     // 4. INSERTION PHASE
//     // Always insert first pend element at the start
//     main_chain.prepend(pend[0]) 

//     // Generate Jacobsthal insertion order (indices: 3, 2, 5, 4, 11, 10, 9...)
//     insertion_indices = generate_jacob_indices(pend.size)

//     FOR each idx IN insertion_indices:
//         IF idx >= pend.size: CONTINUE
        
//         target = pend[idx]
        
//         // BOUNDED BINARY SEARCH
//         // Limit the search range to the position of its 'large' partner in main_chain
//         limit_val = find_partner_of_small_in_main(target, pairs)
//         limit_pos = find_index_in_main(limit_val, main_chain)
        
//         pos = binary_search(main_chain, target, 0, limit_pos)
//         main_chain.insert(pos, target)

//     RETURN main_chain

std::vector<int> extract_biggest(std::vector<std::pair<int, int> > pairs) {

    std::vector<int> main;

    std::vector<std::pair<int, int> >::const_iterator it;
    for (it = pairs.begin(); it != pairs.end(); it++)
    {
        main.push_back(it->second);
    }
    return main;
    
}

std::vector<int> generate_jacob_indices(size_t sizePend) {
    std::vector<int> jacob_indices;

    jacob_indices.push_back(0);
    jacob_indices.push_back(1);
    int nextNm;
    for (int i = 1; i < sizePend; i++)
    {
        nextNm = jacob_indices[i] + 2 * jacob_indices[i-1];
        if (nextNm >= sizePend)
            break;
        jacob_indices.push_back(nextNm);
    }
    return jacob_indices;
}



std::vector<int> jacob(std::vector<int> Myvector) {

    if (Myvector.size() <= 1)
        return Myvector;

    // store the leftover
    int leftover = -1; 
    if (Myvector.size() % 2 != 0) {
        leftover = Myvector[Myvector.size() - 1];
        std::cout << "leftover: " <<  leftover << std::endl;
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < Myvector.size(); i += 2)
    {
        if (Myvector[i] < Myvector[i + 1])
            pairs.push_back(std::make_pair(Myvector[i], Myvector[i + 1]));
        else
            pairs.push_back(std::make_pair(Myvector[i + 1], Myvector[i]));
    }

    // i did recursion here
    std::vector<int> biggest = extract_biggest(pairs); // larger element in the main 
    std::cout << "biggest:   ";
    PrintVec(biggest);
    std::vector<int> main = biggest;
    std::vector<int> pend;
    std::cout << "main:   ";
    PrintVec(main);
    std::vector<std::pair<int, int> >::const_iterator it;
    for (it = pairs.begin(); it != pairs.end(); ++it) {
        pend.push_back(it->first);
    }
    // add the left number to pend
    if (leftover >= 0)
        pend.push_back(leftover);
    std::cout << "pend:   ";
    PrintVec(pend);
    std::cout << std::endl;
    std::vector<int> sorted_biggest = jacob(biggest);
    // std::cout << "see see see:     " << count << std::endl;
    // count++;
    generate_jacob_indices(pend.size)



    Printpair(pairs);
    std::cout << std::endl;

    return Myvector;
}

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
        // std::cout << "Before:   ";
        // PrintVec(Myvector);
        jacob(Myvector);
        std::cout << std::endl;
        
    }
    else
        std::cout << "Error!" << std::endl;
}