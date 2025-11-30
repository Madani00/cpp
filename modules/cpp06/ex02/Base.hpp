#pragma once

class A;
class B;
class C;
#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()



class Base
{
    private:
        /* data */
    public:
        Base(/* args */);
        virtual ~Base(); // very important for dynamic_cast

        Base * generate(void);
        void identify(Base* p);
        void identify(Base& p);

};
