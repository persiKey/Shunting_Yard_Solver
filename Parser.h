#pragma once
class Parser
{
public:
	int GetInt(const char* str, size_t& pos);
	char GetOp(const char* str, size_t& pos);
};

