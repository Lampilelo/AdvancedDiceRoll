#include <iostream>

#include "IOperation.h"
#include "GetNumberOperation.h"
#include "RandomOperation.h"

int main()
{
    IOperation* operation = new GetNumberOperation(1);
    operation->evaluate();
    std::cout << operation->toString() << std::endl;
    delete operation;
    
    operation = new RandomOperation(6, 7);
    try
    {
        operation->evaluate();
    }
    catch (std::exception& e) { std::cout << e.what() << std::endl; }
    std::cout << operation->toString() << std::endl;
    delete operation;

    return 0;
}