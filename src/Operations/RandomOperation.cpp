#include "RandomOperation.h"

RandomOperation::RandomOperation(int lower, int upper) : _lower(lower), _upper(upper)
{
    _count = 0;
    _componentOp = nullptr;
}

RandomOperation::RandomOperation(int upper) : RandomOperation::RandomOperation(1, upper) {}

void RandomOperation::evaluate() 
{ 
    if(_lower >= _upper) throw std::invalid_argument(
        "In RandomOperation: " + std::to_string(_lower) + " is higher or equal to " + std::to_string(_upper));

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(_lower, _upper);
    _elements.push_back(distribution(generator));
    _count = 1;
}