////////////////////////////////////////////////////////////////////////////////
// Module Name:  int_stack.h/cpp
// Authors:      Sergey Shershakov
// Version:      0.2.0
// Date:         23.01.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////


#include "int_stack.h"
#include <stdexcept>

// TODO: add necessary headers here
// #include <...

namespace xi {

IntStack::IntStack(size_t sz) : _ssize(sz), _head(0) 
{
    _stack = new int[sz];
}

IntStack::~IntStack() 
{
    delete[] _stack;
    _stack = nullptr;
}

void IntStack::push(int el) 
{
    if (_head == _ssize)
        throw std::logic_error("int_stack overflow, can't push more elements");
    _stack[_head++] = el;
}

int IntStack::top() 
{
    if (_head == 0)
        throw std::logic_error("int_stack error, stack is empty");
    return _stack[_head - 1];
}

int IntStack::pop() 
{
    if (_head == 0)
        throw std::logic_error("int_stack error, stack is empty");
    return _stack[--_head];
}

void IntStack::clear() 
{
    _head = 0;
}

bool IntStack::isEmpty() const 
{
    return _head == 0;
}

bool IntStack::isFull() const 
{
    return _head == _ssize;
}
} // namespace xi

