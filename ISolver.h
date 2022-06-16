#pragma once

class ISolver
{
public:
	ISolver() {};
	virtual float Solve(const char* line) = 0;
	virtual ~ISolver() {};
};