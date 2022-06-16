#pragma once
template <class T>
class IStack
{
public:
	IStack() {};
	virtual ~IStack() {};
	virtual void push(T val) = 0;
	virtual void pop() = 0;
	virtual T extract() = 0;
	virtual const T& top() = 0;
	virtual size_t size() = 0;
	virtual bool empty() = 0;
};
