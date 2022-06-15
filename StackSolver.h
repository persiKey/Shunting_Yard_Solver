#pragma once
#include "Stack.h"

class StackSolver
{
	IStack<int>* num_stack;
	IStack<char>* op_stack;


	int operation(int a, int b, char op);
	int Calc(const char** line, size_t pos);
public:
	int Solve(const char** line);

};

