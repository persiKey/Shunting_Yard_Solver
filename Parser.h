#pragma once
class Parser
{
	bool IsOpChar(char op);
	int get_sign(const char* str, size_t start_pos, size_t end_pos);
public:
	int GetInt(const char* str, size_t& pos);
	char GetOp(const char* str, size_t& pos);
};

