#pragma once

#include <iostream>
#include "Data.hpp"
// #include <cstdint>
#include <stdint.h>
// uintptr_t : t is an unsigned integer type guaranteed to be large enough to hold any object's address, 
// allowing for portable manipulation of pointer values as integers. 

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& other); 
        Serializer& operator=(const Serializer& other);
    public:
        static uintptr_t serialize(Data* ptr); 
        static Data* deserialize(uintptr_t raw);
       
};

