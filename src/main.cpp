#include "DiceRoll/stdafx.hpp"

#include "DiceRoll/Operations/IOperation.hpp"
#include "DiceRoll/Operations/GetNumberOperation.hpp"
#include "DiceRoll/Operations/RandomOperation.hpp"
#include "DiceRoll/Operations/RollResult.h"

int main()
{
    std::unique_ptr<IOperation> operation(new GetNumberOperation(1));
    std::unique_ptr<RollResult> result = operation->evaluate();
    std::cout << result->getOperationLog() << '\n';

    operation.reset(new RandomOperation(3, 7));
    try
    {
        result = operation->evaluate();
    }
    catch (std::exception& e) { std::cout << e.what() << '\n'; }
    std::cout << result->getOperationLog() << '\n';

    return 0;
}
