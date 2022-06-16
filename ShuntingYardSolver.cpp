#include "ShuntingYardSolver.h"
#include "LinearStack.h"
#include <ctype.h>
#include <math.h>

ShuntingYardSolver::ShuntingYardSolver()
{
	num_stack = new LinearStack<float>;
	op_stack = new LinearStack<char>;
}

ShuntingYardSolver::~ShuntingYardSolver()
{
	delete num_stack;
	delete op_stack;
}

int ShuntingYardSolver::GetPriority(char op)
{
	switch (op)
	{
	case '-': case '+': return 1;
	case '*': case '/': return 2;
	case '^': return 3;
	}
}

void ShuntingYardSolver::PerformOperation()
{
	float right = num_stack->extract();
	float left = num_stack->extract();
	switch (op_stack->extract())
	{
	case '-': num_stack->push(left - right); break;
	case '+': num_stack->push(left + right); break;;
	case '*': num_stack->push(left * right); break; 
	case '/': num_stack->push(left / right); break;
	case '^': num_stack->push(pow(left,right)); break;;
	}
}


float ShuntingYardSolver::Solve(const char* line)
{
	parser = new SYParser(line);
	
	while (!parser->IsEnd())
	{
		Element next = parser->GetNextEl();
		if (next.t == Type::NUMBER)
		{
			num_stack->push(*(float*)next.el);
			continue;
		}
		else if (next.t == Type::SPEC)
		{
			char next_spec = *(char*)next.el;
			if (next_spec == '(')
			{
				op_stack->push(next_spec);
				continue;
			}
			else if (next_spec == ')')
			{
				while (op_stack->top() != '(')
				{
					PerformOperation();
				}
				op_stack->pop();
			}
		}
		else if (next.t == Type::OP)
		{
			char next_op = *(char*)next.el;
			if (op_stack->empty())
			{
				op_stack->push(next_op);
				continue;
			}
			while (!op_stack->empty() && op_stack->top() != '(' && GetPriority(next_op) <= GetPriority(op_stack->top()))
			{
				PerformOperation();
			}
			op_stack->push(next_op);
		}
	}
	while (!op_stack->empty())
		PerformOperation();

	delete parser;
	return num_stack->extract();
}
