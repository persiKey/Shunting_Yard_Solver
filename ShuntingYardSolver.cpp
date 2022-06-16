#include "ShuntingYardSolver.h"
#include "LinearStack.h"
#include <ctype.h>
#include <math.h>

char* ShuntingYardSolver::DeleteAllSpaces(const char* line)
{
	int size = strlen(line)+1;
	char* new_line = new char[size];
	strcpy_s(new_line, size, line);
	for (int i = 0; new_line[i] != '\0'; ++i)
	{
		if (new_line[i] == ' ')
		{
			for (int k = i; new_line[k] != '\0'; ++k)
			{
				new_line[k] = new_line[k + 1];
			}
		}
	}
	int new_size = strlen(new_line) + 1;
	char* tmp_line = new char[new_size];
	strcpy_s(tmp_line, new_size, new_line);
	delete[] new_line;
	return tmp_line;
}

bool ShuntingYardSolver::IsBeg(const char* line, int pos)
{
	if (pos - 1 < 0)
		return true;
	if (line[pos - 1] == '(' || IsOpChar(line[pos-1]))
		return true;

	return false;
}

float ShuntingYardSolver::GetNum(const char* line, size_t& pos)
{
	int sign = 1;
	if (line[pos] == '-')
	{
		sign = -1;
		++pos;
	}

	LinearStack<int> nums;
	for (; isdigit(line[pos]); ++pos)
		nums.push(int(line[pos] - '0'));

	int result = 0;
	for (int i = 0; !nums.empty(); ++i)
		result += nums.extract() * pow(10, i);

	return result * sign;
}

bool ShuntingYardSolver::IsOpChar(char op)
{
	return (op == '+') || (op == '-') || (op == '/') || (op == '*') || (op == '^');
}

Element ShuntingYardSolver::GetNextEl(const char* line, size_t& pos)
{
	if (line[pos] == '(' || line[pos] == ')')
		return Element(new char(line[pos++]), Type::OP);
	if (line[pos] == '-')
	{
		if (IsBeg(line, pos))
		{
			return Element(new float(GetNum(line, pos)), Type::NUMBER);
		}
		return Element(new char(line[pos++]), Type::OP);
	}
	if(IsOpChar(line[pos]))
		return Element(new char(line[pos++]), Type::OP);

	if (isdigit(line[pos]))
	{
		return Element(new float(GetNum(line, pos)), Type::NUMBER);
	}

}

ShuntingYardSolver::ShuntingYardSolver()
{
	num_stack = new LinearStack<float>;
	op_stack = new LinearStack<char>;
}

ShuntingYardSolver::~ShuntingYardSolver()
{
}

float ShuntingYardSolver::Solve(const char* line)
{
	return 0.0f;
}

Element::Element(void* el, Type t) : el(el), t(t)
{
}

Element::~Element()
{
	switch (t)
	{
	case Type::NUMBER: delete (float*)el; break;
	case Type::OP: delete (char*)el; break;
	}
}
