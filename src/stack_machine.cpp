////////////////////////////////////////////////////////////////////////////////
// Module Name:  stack_machine.h/cpp
// Authors:      Sergey Shershakov
// Version:      0.2.0
// Date:         23.01.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////

#include "stack_machine.h"

#include <vector>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <climits>

namespace xi {

//==============================================================================
// Free functions -- helpers
//==============================================================================

// TODO: if you need any free functions, add their definitions here.

//==============================================================================
// class PlusOp
//==============================================================================


    int PlusOp::operation(char op, int a, int b,
                          int /*c*/) // < just commented unused argument. This does not affect the code anyhow.
    {
        if (op != '+')
            throw std::logic_error("Operation other than Plus (+) are not supported");

        // here we just ignore unused operands
        return a + b;
    }

    IOperation::Arity PlusOp::getArity() const
    {
        return arDue;
    }

    int MultOp::operation(char op, int a, int b, int /*c*/)
    {
        if (op != '*')
            throw std::logic_error("Operation other than Mult (*) are not supported");

        return a * b;
    }

    IOperation::Arity MultOp::getArity() const
    {
        return arDue;
    }

    int OrOp::operation(char op, int a, int b, int /*c*/)
    {
        if (op != '|')
            throw std::logic_error("Operation other than Or (|) are not supported");

        return a | b;
    }

    IOperation::Arity OrOp::getArity() const
    {
        return arDue;
    }

    int DivOp::operation(char op, int a, int b, int /*c*/)
    {
        if (op != '/')
            throw std::logic_error("Operation other than Div (/) are not supported");

        if (!b)
            return a < 0 ? -INT_MAX : INT_MAX;

        return a / b;
    }

    IOperation::Arity DivOp::getArity() const
    {
        return arDue;
    }

//==============================================================================
// class StackMachine
//==============================================================================


// TODO: put StackMachine methods implementation here

    void StackMachine::registerOperation(char symb, IOperation* oper)
    {
        SymbolToOperMapConstIter it = _opers.find(symb);
        if (it != _opers.end())
            throw std::logic_error("An operation is already registered");

        _opers[symb] = oper;
    }

    IOperation *StackMachine::getOperation(char symb)
    {
        SymbolToOperMapConstIter it = _opers.find(symb);
        if (it == _opers.end())
            throw std::logic_error("An operation isn't registered");

        return it->second;
    }

    int StackMachine::calculate(const std::string& expr, bool clearStack)
    {
        if(clearStack)
            _s.clear();
        std::string el = "";
        int number = 0;
        for (auto iter = expr.begin(); iter != expr.end(); ++iter) {
            if (*iter != ' ')
                el += *iter;
            if (*iter == ' ' || (iter + 1) == expr.end()) {
                number = atoi(el.c_str());
                if (number == 0 && el != "0") {
                    if (el.size() != 1)
                        throw std::logic_error("It's not an operation");
                    IOperation *oper = getOperation(el.c_str()[0]);
                    switch (oper->getArity()) {
                        case IOperation::arUno: {
                            int first = _s.pop();
                            _s.push(oper->operation(el.c_str()[0], first));
                            break;
                        }
                        case IOperation::arDue: {
                            int second = _s.pop();
                            int first = _s.pop();
                            _s.push(oper->operation(el.c_str()[0], first, second));
                            break;
                        }
                        case IOperation::arTre: {
                            int third = _s.pop();
                            int second = _s.pop();
                            int first = _s.pop();
                            _s.push(oper->operation(el.c_str()[0], first, second, third));
                            break;
                        }
                        default: {
                            throw std::logic_error("An operation not found");
                        }
                    }
                } else _s.push(number);
                el = "";
            }
        }
        return _s.top();
    }

    int MinusOp::operation(char op, int a, int b, int /*c*/)
    {
        if (op != '-')
            throw std::logic_error("Operation other than Minus (-) are not supported");

        return a - b;
    }

    IOperation::Arity MinusOp::getArity() const
    {
        return arDue;
    }

    int ChoiceOp::operation(char op, int a, int b, int c)
    {
        if (op != '?')
            throw std::logic_error("Operation other than Choice (?) are not supported");

        return a ? b : c;
    }

    IOperation::Arity ChoiceOp::getArity() const
    {
        return arTre;
    }

    int SigChangeOp::operation(char op, int a, int /*b*/, int /*c*/)
    {
        if (op != '!')
            throw std::logic_error("Operation other than SigChange (!) are not supported");

        return -a;
    }

    IOperation::Arity SigChangeOp::getArity() const
    {
        return arUno;
    }

    int InverOp::operation(char op, int a, int /*b*/, int /*c*/)
    {
        if (op != '~')
            throw std::logic_error("Operation other than Inver (~) are not supported");

        return ~a;
    }

    IOperation::Arity InverOp::getArity() const
    {
        return arUno;
    }

    int AndOp::operation(char op, int a, int b, int /*c*/)
    {
        if (op != '&')
            throw std::logic_error("Operation other than And (&) are not supported");

        return a & b;
    }

    IOperation::Arity AndOp::getArity() const
    {
        return arDue;
    }

    int PowOp::operation(char op, int a, int b, int /*c*/)
    {
        if (op != '^')
            throw std::logic_error("Operation other than Pow (^) are not supported");

        int ans = 1;
        while (b) {
            if (b & 1)
                ans *= a;
            a *= a;
            b >>= 1;
        }
        return ans;
    }

    IOperation::Arity PowOp::getArity() const
    {
        return arDue;
    }

    int AssignOp::operation(char op, int a, int /*b*/, int /*c*/)
    {
        if (op != '=')
            throw std::logic_error("Operation other than Assign (=) are not supported");

        return a;
    }

    IOperation::Arity AssignOp::getArity() const
    {
        return arUno;
    }

} // namespace xi
