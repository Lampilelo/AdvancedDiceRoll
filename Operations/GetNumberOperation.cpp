#include "GetNumberOperation.h"

GetNumberOperation::GetNumberOperation(int number) : _number(number)
{
    _count = 0;
    _componentOp = nullptr;
}

void GetNumberOperation::evaluate() 
{ 
    _elements.push_back(_number);
    _count = 1;
}