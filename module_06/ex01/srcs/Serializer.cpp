#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer&) {}
Serializer& Serializer::operator=(const Serializer&) {
    return *this;
}
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
    if (!ptr) {
        std::cerr << "[Serializer::serialize] Error: trying to serialize a "
                     "null pointer.\n";

        return 0;
    }
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    if (raw == 0) {
        std::cerr << "[Serializer::deserialize] Warning: raw address is 0.\n";
        return nullptr;
    }

    Data* ptr = reinterpret_cast<Data*>(raw);

    return ptr;
}
