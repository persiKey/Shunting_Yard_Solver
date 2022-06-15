#include <iostream>
#include "StackSolver.h"
#include <string>
using std::cout;

int main(int argc, char** argv)
{
	StackSolver s;
	std::string in;

	while (true)
	{
		std::getline(std::cin, in);
		cout << s.Solve(in.c_str()) << '\n';
	}
	
	return 0;
}