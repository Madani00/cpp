#include "Serializer.hpp"

int main() {


    Data *data = new Data();
    data->Id = 42;

    std::cout << "original address: " << data << std::endl;

    uintptr_t my_int = Serializer::serialize(data);
    std::cout << "decimal representation of the memory address: " << my_int << std::endl;

    Data *returned_ptr = Serializer::deserialize(my_int);
    if (returned_ptr == data)
        std::cout << "returned memory address: " << returned_ptr << std::endl;
    std::cout << "returned Id: " << returned_ptr->Id << std::endl;
}