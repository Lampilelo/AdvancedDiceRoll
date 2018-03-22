#include "DiceRoll/Operations/RandomOperation.hpp"

RandomOperation::RandomOperation(int lower, int upper)
    : IOperation(nullptr), _lower(lower), _upper(upper)
{
    _fixedSeed = false;
}

RandomOperation::RandomOperation(int upper) : RandomOperation(1, upper) {}

std::unique_ptr<RollResult> RandomOperation::execute() 
{ 
    if(_lower >= _upper) throw std::invalid_argument(
        "In RandomOperation: " + std::to_string(_lower) + " is higher or equal to " + std::to_string(_upper));


    //we'll use random_device to seed the random
    //if you want to change it, call changeSeed function
    std::random_device r;
    if (false == _fixedSeed)
	_seed = r();
    
    std::default_random_engine generator(_seed);
    std::uniform_int_distribution<int> distribution(_lower, _upper);

    auto randomNumber = distribution(generator);

    auto result = std::make_unique<RollResult>();
    result->appendLastResult(randomNumber);
    result->setOperationLog(std::to_string(randomNumber));
    return result;
}

std::unique_ptr<RollResult> RandomOperation::evaluate()
{
    return execute();
}

void RandomOperation::changeSeed(unsigned newSeed)
{
    _fixedSeed = true;
    _seed = newSeed;
}
