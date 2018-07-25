#include "DiceRoll/Operations/RandomOperation.hpp"

namespace DiceRoll {
RandomOperation::RandomOperation(int lower, int upper)
    : lower_(lower), upper_(upper)
{
  if(lower_ >= upper_) throw std::invalid_argument(
        "In RandomOperation: " + std::to_string(lower_) +
        " is higher or equal to " + std::to_string(upper_));

    fixedSeed_ = false;
}

RandomOperation::RandomOperation(int upper) : RandomOperation(1, upper) {}

std::unique_ptr<RollResult> RandomOperation::evaluate()
{
    //we'll use random_device to seed the random
    //if you want to change it, call changeSeed function
    std::random_device r;
    if (false == fixedSeed_)
	seed_ = r();
    
    std::default_random_engine generator(seed_);
    std::uniform_int_distribution<int> distribution(lower_, upper_);

    auto randomNumber = distribution(generator);

    auto result = std::make_unique<RollResult>();
    result->appendShortResult(randomNumber);
    result->setFullResult(std::to_string(randomNumber));
    return result;
}

void RandomOperation::changeSeed(unsigned newSeed)
{
    fixedSeed_ = true;
    seed_ = newSeed;
}
}
