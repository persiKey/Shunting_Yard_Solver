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
		try
		{
			if (strlen(argv[i]) < 1)
				continue;
			cout << s->Solve(argv[i]) << '\n';
		}
		catch (std::logic_error a)
		{
				cout.flush(); cout.clear();
				cout << a.what() << '\n';
		}
	}
	
	std::string in;

	while (true)
	{
		try
		{
			std::getline(std::cin, in);
			if (in.size() < 1)
				break;
			cout << s->Solve(in.c_str()) << '\n';
		}
		catch (std::logic_error a)
		{
			cout.flush(); cout.clear();
			cout << a.what() << '\n';
		}
	}
	delete s;
	return 0;
}