#include "StackSolver.h"
#include <sstream>
StackSolver::StackSolver()
{
	num_stack = new Stack<int>;
	op_stack = new Stack<char>;
}

StackSolver::~StackSolver()
{
	delete num_stack;
	delete op_stack;
}


int StackSolver::operation(int a, int b, char op)
{
	switch (op)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
}

int StackSolver::Calc(const char* line, size_t pos)
{
	
}
