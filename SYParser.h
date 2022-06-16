#pragma once

enum class Type
{
	NUMBER,
	OP,
	SPEC
};

struct Element
{
	void* el;
	Type t;
	Element(void* el_, Type t_);
	~Element();
};

class SYParser
{
	char* line;
	size_t pos;
	char* DeleteAllSpaces(const char* line);
	float GetNum();
	bool IsBeg();
	bool IsOpChar(char);
public:
	SYParser(const char* follow_line);
	~SYParser();
	Element GetNextEl();
	bool IsEnd();
};

