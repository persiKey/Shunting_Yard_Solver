#include "Parser.h"
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "Stack.h"


int Parser::GetInt(const char* str, size_t& pos)
{
	int i = pos;
	while (!isdigit(str[pos]))
		++pos;

	Stack<int> nums;
	for (int i = pos; !isdigit(str[pos]); ++i)
		nums.push(str[pos] - '0');

	int result = 0;
	for (int i = 0; !nums.isEmpty(); ++i)
		result += nums.extract() * pow(10, i);

	return result;
}

char Parser::GetOp(const char* str, size_t& pos)
{
	for (; str[pos] != '\0'; ++pos)
	{
		if (str[pos] == ' ')
			continue;
		if(!(isdigit(str[pos])))
			return str[pos];
	}
}

