#include "StackSolver.h"
#include <sstream>
StackSolver::StackSolver()
{
	num_stack = new Stack<float>;
	op_stack = new Stack<char>;
}

StackSolver::~StackSolver()
{
	delete num_stack;
	delete op_stack;
}

float StackSolver::Solve(const char* line)
{
	size_t start = 0;
	return Calc(line, start);
}

int StackSolver::get_priority(char op)
{
	int pr;
	switch (op)
	{
	case '-': case '+': pr = 1; break;
	case '/': case '*': pr = 2; break;
	case '^': pr = 3; break;
	default:
		break;
	}
	return pr ;
}

float StackSolver::operation(float a, float b, char op)
{
	switch (op)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	case '^': return pow(a, b);
	}
}

float StackSolver::Oper(char op)
{
	float right = num_stack->extract();
	float left = num_stack->extract();

	return operation(left, right, op);
}

float StackSolver::Calc(const char* line, size_t &pos)
{
	int help_pos = pos;
	num_stack->push(parser.GetInt(line, pos));
	while (line[pos] != '\0')
	{
		op_stack->push(parser.GetOp(line, pos));
		num_stack->push(parser.GetInt(line, pos));
		if (line[pos] == '\0')
		{
			num_stack->push(Oper(op_stack->extract()));
			break;
		}
		help_pos = pos;
		char next_op = parser.GetOp(line, pos);
		pos = help_pos;

		while (get_priority(op_stack->top()) < get_priority(next_op))
		{
			num_stack->push(parser.GetInt(line, pos));
			num_stack->push((Oper(next_op)));
			if (line[pos] == '\0')
				break;
			help_pos = pos;
			next_op = parser.GetOp(line, pos);
			pos = help_pos;
		}
		
		num_stack->push(Oper(op_stack->extract()));
	}
	return num_stack->extract();
}
