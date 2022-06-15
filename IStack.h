#pragma once
template <class T>
class IStack
{
public:
	virtual void push(const T& val) = 0;
	virtual void pop() = 0;
	virtual T extract() = 0;
	virtual const T& top() = 0;
	virtual ~IStack() = 0;
};
