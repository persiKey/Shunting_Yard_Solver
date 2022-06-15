#include "Parser.h"
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "Stack.h"


int Parser::GetInt(const char* str, size_t& pos)
{
	while (!isdigit(str[pos]))
		++pos;

	Stack<int> nums;
	for (; isdigit(str[pos]); ++pos)
		nums.push(int(str[pos] - '0'));

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

