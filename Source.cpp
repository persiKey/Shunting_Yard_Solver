#include <iostream>
#include "Stack.h"

using std::cout;

int main(int argc, char** argv)
{

	Stack<int> Nums;
	for (int i = 1; i <= 20; ++i)
	{
		Nums.push_back(rand() % i);
		cout << "Put " << Nums.top() << '\n';
	}
	for (int i = 0; i < 20; i++)
	{
		cout << "Aga " << Nums.top() << '\n';
		Nums.pop_back();
	}
	return 0;
}