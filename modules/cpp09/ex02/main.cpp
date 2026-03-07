

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

// - Binary Search: Use binary search to find the correct spot (i used the std::lower_bound function) for each b element in the Main Chain.
// - Optimization: When inserting bn​, you only need to search the Main Chain up to the position of its partner an​.

#include "PmergeMe.hpp"

// jacob order [3, 2, 5, 4, 6]
// The 5th [6] number in pend should be inserted before the 4th number.
// However, the first number is always inserted first, as it is smaller than the first element in main.

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


std::vector<int> extract_biggest(std::vector<std::pair<int, int> > pairs) {

    std::vector<int> main;

    std::vector<std::pair<int, int> >::const_iterator it;
    for (it = pairs.begin(); it != pairs.end(); it++)
    {
        main.push_back(it->second);
    }
    return main;
}

std::vector<int> extract_smallest(std::vector<std::pair<int, int> > pairs, std::vector<int> Myvector) {

    std::vector<int> pend;
    // store the leftover
    int leftover = -1; 
    if (Myvector.size() % 2 != 0) {
        leftover = Myvector[Myvector.size() - 1];
        std::cout << "leftover: " <<  leftover << std::endl;
    }

    std::vector<std::pair<int, int> >::const_iterator it;
    for (it = pairs.begin(); it != pairs.end(); ++it) {
        pend.push_back(it->first);
    }
    // add the left number to pend
    if (leftover >= 0)
        pend.push_back(leftover);
    return pend;
}

std::vector<int> jacob_numbers(size_t sizePend) {
    std::vector<int> jacob_numbers;
     if (sizePend == 0) return jacob_numbers;

    jacob_numbers.push_back(3);
    jacob_numbers.push_back(5);
    size_t nextNm;
    for (size_t i = 1; i < sizePend; i++)
    {
        nextNm = jacob_numbers[i] + 2 * jacob_numbers[i-1];
        if (nextNm >= sizePend)
            break;
        jacob_numbers.push_back(nextNm);
    }
    return jacob_numbers;
}

std::vector<int> generate_jacob_indices(size_t sizePend) {
    std::vector<int> jacob_order;

    std::vector<int> jacob_numb = jacob_numbers(sizePend);

   
    for (size_t i = 0; i < jacob_numb.size(); i++)
    {
        jacob_order.push_back(jacob_numb[i]);
        jacob_order.push_back(jacob_numb[i] - 1);
    }

    // yet still not know why 
    size_t add_more = sizePend;
    if (jacob_order.size() + 1 != add_more) {
        size_t i;
        for (i = 0; i < jacob_order.size(); i++)
        {
            if (add_more == (size_t)jacob_order[i])
                break;
        }
        if (jacob_order.size() == i && add_more > 1)
            jacob_order.push_back(add_more);
    }

    
    return jacob_order;
}



std::vector<int> merge_insertion(std::vector<int> Myvector) {

    if (Myvector.size() <= 1)
        return Myvector;


    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < Myvector.size(); i += 2)
    {
        if (Myvector[i] < Myvector[i + 1])
            pairs.push_back(std::make_pair(Myvector[i], Myvector[i + 1]));
        else
            pairs.push_back(std::make_pair(Myvector[i + 1], Myvector[i]));
    }
    std::cout << "pairs:   ";
    Printpair(pairs);

    
    std::vector<int> main = extract_biggest(pairs); // larger element in the main 
    std::vector<int> pend = extract_smallest(pairs, Myvector); // smaller element in the pend
    std::cout << "main:   ";
    PrintVec(main);
    std::cout << "pend:   ";
    PrintVec(pend);

    // recursive call on the main
    std::vector<int> jacob_order = generate_jacob_indices(pend.size());
    std::cout << std::endl;
    main = merge_insertion(main);
        
    // Always insert first pend element at the start
    // if (main[0] > pend[0])
    //     main.insert(main.begin(), pend[0]);
    // else
    //     main.insert(main.begin() + 1, pend[0]);
    main.insert(main.begin(), pend[0]);
    
    // now do the insertion order of jacob
    int target;
    for (size_t i = 0; i < jacob_order.size(); i++)
    {
        if (jacob_order[i] - 1  >= (int)pend.size()) // -1 important because the jacob order is 1-based index, but the vector is 0-based index
            continue;
        target = pend[jacob_order[i] - 1];

        std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), target);

        size_t index = std::distance(main.begin(), it);
        main.insert(main.begin() + index, target); 
    }

    std::cout << "main after insertion pend:   ";
    PrintVec(main);

    std::cout << std::endl;

    return main;
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

        PrintVec(merge_insertion(Myvector));
        std::cout << "After:   ";

        // std::cout << "Jacobsthal number:   ";
        // PrintVec(jacob_numbers(6));
        // std::cout << "generate jacob edits:   ";
        // PrintVec(generate_jacob_indices(6));

        std::cout << std::endl;
    }
    else
        std::cout << "Error!" << std::endl;
}