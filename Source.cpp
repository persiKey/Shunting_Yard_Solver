#include <iostream>
#include "StackSolver.h"
#include "ShuntingYardSolver.h"
#include <string>
using std::cout;

int main(int argc, char** argv)
{
	ISolver *s = new ShuntingYardSolver;
	std::string in;
	ShuntingYardSolver test;
	
	while (true)
	{
		std::getline(std::cin, in);
		cout << s->Solve(in.c_str()) << '\n';
	}
	delete s;
	return 0;
}