#include "GetNumberOperation.hpp"

GetNumberOperation::GetNumberOperation(int number) : _number(number)
{
    _count = 0;
    _componentOp = nullptr;
}

void GetNumberOperation::evaluate()
{
    execute();
}

void GetNumberOperation::execute() 
{ 
    _elements.push_back(_number);
    _count = 1;
}
