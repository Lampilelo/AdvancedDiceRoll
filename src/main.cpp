#include "stdafx.hpp"

#include "Operations/IOperation.hpp"
#include "Operations/GetNumberOperation.hpp"
#include "Operations/RandomOperation.hpp"

int main()
{
    std::unique_ptr<IOperation> operation(new GetNumberOperation(1));
    operation->evaluate();
    std::cout << operation->toString() << std::endl;

    operation.reset(new RandomOperation(3, 7));
    try
    {
        operation->evaluate();
    }
    catch (std::exception& e) { std::cout << e.what() << std::endl; }
    std::cout << operation->toString() << std::endl;

    return 0;
}
