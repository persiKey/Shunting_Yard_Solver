#pragma once
#include "ISolver.h"
#include "IStack.h"
#include "SYParser.h"

class ShuntingYardSolver : public ISolver
{
	IStack<float>* num_stack;
	IStack<char>* op_stack;
	SYParser* parser;

	int GetPriority(char);
	void PerformOperation();
public:
	ShuntingYardSolver();
	~ShuntingYardSolver();
	float Solve(const char* line) override;
};
