#pragma once
#include "Stack.h"
#include "Parser.h"

class StackSolver
{
	IStack<float>* num_stack;
	IStack<char>* op_stack;
	Parser parser;

	int get_priority(char op);
	float operation(float a, float b, char op);
	float Oper(char op);
	float Calc(const char* line, size_t &pos);
public:
	StackSolver();
	~StackSolver();
	float Solve(const char* line);

};

