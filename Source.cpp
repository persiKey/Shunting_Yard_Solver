#include <iostream>
#include "StackSolver.h"
#include <string>
using std::cout;

int main(int argc, char** argv)
{
	ISolver *s = new StackSolver;
	std::string in;

	while (true)
	{
		std::getline(std::cin, in);
		cout << s->Solve(in.c_str()) << '\n';
	}
	delete s;
	return 0;
}