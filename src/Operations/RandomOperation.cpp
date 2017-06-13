#include "DiceRoll/Operations/RandomOperation.hpp"

RandomOperation::RandomOperation(int lower, int upper) : _lower(lower), _upper(upper)
{
    _count = 0;
    _componentOp = nullptr;
    _fixedSeed = false;
}

RandomOperation::RandomOperation(int upper) : RandomOperation(1, upper) {}

std::shared_ptr<RollResult> RandomOperation::execute() 
{ 
    if(_lower >= _upper) throw std::invalid_argument(
        "In RandomOperation: " + std::to_string(_lower) + " is higher or equal to " + std::to_string(_upper));

    //we'll use clock to seed the random
    //if you want to change it, call changeSeed function
    if (false == _fixedSeed)
	_seed = std::chrono::system_clock::now()
	    .time_since_epoch().count();
    
    std::default_random_engine generator(_seed);
    std::uniform_int_distribution<int> distribution(_lower, _upper);
    _elements.push_back(distribution(generator));
    _count = 1;

    //return dummy roll result
    return std::make_shared<RollResult>();
}

std::shared_ptr<RollResult> RandomOperation::evaluate()
{
    return execute();
}

void RandomOperation::changeSeed(unsigned newSeed)
{
    _fixedSeed = true;
    _seed = newSeed;
}
