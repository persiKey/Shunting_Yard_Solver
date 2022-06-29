#include "SYParser.h"
#include "LinearStack.h"
#include <ctype.h>
#include <math.h>

char* SYParser::DeleteAllSpaces(const char* line)
{
	int size = strlen(line) + 1;
	char* new_line = new char[size];
	strcpy_s(new_line, size, line);

	for (int i = 0; new_line[i] != '\0'; ++i)
	{
		if (new_line[i] == ' ')
		{
			for (int k = i; new_line[k] != '\0'; ++k)
			{
				new_line[k] = new_line[k + 1];
			}
			--i;
		}
	}

	int new_size = strlen(new_line) + 1;
	char* tmp_line = new char[new_size];
	strcpy_s(tmp_line, new_size, new_line);
	delete[] new_line;
	return tmp_line;
}

bool SYParser::IsBeg()
{
	if (pos - 1 < 0)
		return true;
	if (line[pos - 1] == '(' || IsOpChar(line[pos - 1]))
		return true;

	return false;
}

float SYParser::GetNum()
{
	int sign = 1;
	if (line[pos] == '-')
	{
		sign = -1;
		++pos;
	}

	LinearStack<int> nums;
	for (; isdigit(line[pos]); ++pos)
		nums.push(int(line[pos] - '0'));

	int result = 0;
	for (int i = 0; !nums.empty(); ++i)
		result += nums.extract() * pow(10, i);

	return result * sign;
}

bool SYParser::IsOpChar(char op)
{
	return (op == '+') || (op == '-') || (op == '/') || (op == '*') || (op == '^');
}

void SYParser::Valid()
{
	for (int i = pos; line[i] != '\0'; ++i)
	{
		if (IsOpChar(line[i]) || isdigit(line[i]) || line[i] == '(' || line[i] == ')')
			continue;
		else
		{
			std::string er("Strange symbol at pos : ");
			char buf[10];
			_itoa_s(i, buf, 10);
			er.append(buf);
			throw std::invalid_argument(er);
			exit(-1);
		}
	}
}



SYParser::SYParser(const char* follow_line) : pos(0)
{
	line = DeleteAllSpaces(follow_line);
	Valid();
}

SYParser::~SYParser()
{
	delete[] line;
}

Element SYParser::GetNextEl()
{
	if (line[pos] == '(' || line[pos] == ')')
		return Element(new char(line[pos++]), Type::SPEC);
	if (line[pos] == '-')
	{
		if (IsBeg())
		{
			return Element(new float(GetNum()), Type::NUMBER);
		}
		return Element(new char(line[pos++]), Type::OP);
	}
	if (IsOpChar(line[pos]))
		return Element(new char(line[pos++]), Type::OP);

	if (isdigit(line[pos]))
	{
		return Element(new float(GetNum()), Type::NUMBER);
	}

}

bool SYParser::IsEnd()
{
	return line[pos] == '\0';
}


Element::Element(void* el_, Type t_) : el(el_), t(t_) { }

Element::~Element()
{
	switch (t)
	{
	case Type::NUMBER: delete (float*)el; break;
	case Type::OP: delete (char*)el; break;
	}
}
