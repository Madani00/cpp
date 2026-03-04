

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
// pend



// 3 - Binary Insertion via Jacobsthal Numbers: Insert elements from the Pend into the Main Chain in a very specific order to minimize comparisons.