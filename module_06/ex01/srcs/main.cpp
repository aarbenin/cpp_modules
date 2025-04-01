#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
    Data myData;
    myData.id   = 42;
    myData.name = "Hello Serialization";

    uintptr_t raw = Serializer::serialize(&myData);

    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original Data address: " << &myData << std::endl;
    std::cout << "Deserialized address:  " << ptr << std::endl;

    std::cout << "myData.id:        " << myData.id << std::endl;
    std::cout << "ptr->id:          " << ptr->id << std::endl;
    std::cout << "myData.name:      " << myData.name << std::endl;
    std::cout << "ptr->name:        " << ptr->name << std::endl;

    if (ptr == &myData)
        std::cout << "Pointers match! Serialization works." << std::endl;
    else
        std::cout << "Pointers do NOT match! Something's wrong." << std::endl;

    return 0;
}
