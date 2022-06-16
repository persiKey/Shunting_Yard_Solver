#pragma once
#include "ISolver.h"
#include "IStack.h"


enum class Type
{
	NUMBER,
	OP,
	SPEC
};

struct Element
{
	void* el;
	Type t;
	Element(void* el_, Type t_);
	~Element();
};


class ShuntingYardSolver : public ISolver
{
	IStack<float>* num_stack;
	IStack<char>* op_stack;


	char* DeleteAllSpaces(const char*line);
	float GetNum(const char* line, size_t& pos);
	bool IsBeg(const char* line, int pos);
	bool IsOpChar(char);
	int GetPriority(char);
	void PerformOperation();
	Element GetNextEl(const char* line, size_t& pos);
public:
	ShuntingYardSolver();
	~ShuntingYardSolver();
	float Solve(const char* line) override;
};
