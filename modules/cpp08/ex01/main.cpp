#include "Span.hpp"


void simple_test()
{
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "short span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    

}

int main()
{
    unsigned int N = 10;
    srand(time(0));
    Span sp(N);
    // std::list<int> random_numbers;
    std::vector<int> random_numbers;
    // std::deque<int> random_numbers;

    for (unsigned int i = 0; i < N; ++i) {
        random_numbers.push_back(std::rand());
    }

    try {
        sp.addMultiple(random_numbers.begin(), random_numbers.end());
        sp.printarr();
        std::cout << std::endl;

        std::cout << "short span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::string(10, '=') << " test over flow" << std::endl;
    try {
         sp.addNumber(422);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::string(10, '=') << " simple test" << std::endl;
    simple_test();

    
    return 0;
}