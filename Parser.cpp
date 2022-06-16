#include "Parser.h"
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "LinearStack.h"


bool Parser::IsOpChar(char op)
{
	return (op == '+') || (op == '-') || (op == '/') || (op == '*') || (op == '^');
}

int Parser::get_sign(const char* str, size_t start_pos, size_t end_pos)
{
	if (end_pos == 0)
		return 1;
	size_t op_pos = -1, minus_pos = -1;
	for (size_t i = start_pos; i < end_pos; ++i)
	{
		if (str[i] == '-')
		{
			if (start_pos == 0 || op_pos != -1)
				return -1;
		}
		if (IsOpChar(str[i]))
		{
			op_pos = i;
		}
	}
	return 1;
}

int Parser::GetInt(const char* str, size_t& pos)
{
	size_t start = pos;
	while (!isdigit(str[pos]))
		++pos;

	int sign = get_sign(str, start, pos);
	
	LinearStack<int> nums;
	for (; isdigit(str[pos]); ++pos)
		nums.push(int(str[pos] - '0'));

	int result = 0;
	for (int i = 0; !nums.empty(); ++i)
		result += nums.extract() * pow(10, i);

	return result*sign;
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

