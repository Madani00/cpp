#include "PmergeMe.hpp"

void PrintVec(std::vector<int> pairs) {
    std::vector<int>::const_iterator it;
    for (it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

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
        double vecUs = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

        std::cout << "After:   ";
        PrintVec(sortedVec);

        // ── deque ───────────────────────────────────────────────────────
        gettimeofday(&start, NULL);
        std::deque<int> sortedDeq = PmergeMe::merge_insertion(Mydeque);
        gettimeofday(&end, NULL);
        double deqUs = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

        std::cout << "Time to process a range of " << Myvector.size()
                  << " elements with std::vector : "
                  << std::fixed << std::setprecision(2) << vecUs << " us" << std::endl;
        std::cout << "Time to process a range of " << Mydeque.size()
                  << " elements with std::deque  : "
                  << std::fixed << std::setprecision(2) << deqUs << " us" << std::endl;
    }
    else
        std::cerr << "Error" << std::endl;
}