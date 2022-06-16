#include <iostream>
#include "StackSolver.h"
#include "ShuntingYardSolver.h"
#include <string>
using std::cout;

int main(int argc, char** argv)
{
	ISolver *s = new StackSolver;
	std::string in;
	ShuntingYardSolver test;
	
	size_t pos = 0;
	const char* t_l = "6*-9";
	while (t_l[pos] != '\0')
	{
		Element El = test.GetNextEl(t_l, pos);
		switch (El.t)
		{
		case Type::NUMBER: cout << *(float*)El.el << '\n' ; break;
		case Type::OP: cout << *(char*)El.el << '\n'; break;
		}
	}
	while (true)
	{
		std::getline(std::cin, in);
		cout << s->Solve(in.c_str()) << '\n';
	}
	delete s;
	return 0;
}