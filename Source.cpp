#include <iostream>
#include "StackSolver.h"
#include "ShuntingYardSolver.h"
#include <string>

using std::cout;

int main(int argc, char** argv)
{
	ISolver* s = new ShuntingYardSolver;
	for (int i = 1; i < argc; ++i)
	{
		cout << s->Solve(argv[i]) << '\n';
	}
	
	std::string in;

	while (true)
	{
		std::getline(std::cin, in);
		if (in.size() < 1)
			break;
		cout << s->Solve(in.c_str()) << '\n';
	}
	delete s;
	return 0;
}