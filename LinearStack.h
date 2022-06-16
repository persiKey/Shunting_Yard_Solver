#pragma once
#include "BaseStack.h"
#include <stdexcept>

constexpr int GAP = 10;

template <class T>
class LinearStack : public BaseStack<T>
{
	void rellocate() override;
	void shrink() override;
public:
	LinearStack();
	~LinearStack() override;
	void push(T val) override;
	void pop() override;
};

template<class T>
LinearStack<T>::LinearStack()
{
	
	this->mem_ptr = new T[GAP];
	this->_capacity = GAP;
	this->_top = -1;
}

template<class T>
LinearStack<T>::~LinearStack()
{
	delete[] this->mem_ptr;
}

template<class T>
void LinearStack<T>::rellocate()
{
	this->mem_move(this->_capacity + GAP);
}

template<class T>
void LinearStack<T>::shrink()
{
	this->mem_move(this->_capacity - GAP);
}

template<class T>
void LinearStack<T>::push(T val)
{
	if (this->_top + 1 >= this->_capacity)
	{
		rellocate();
	}
	this->mem_ptr[++this->_top] = val;
}

template<class T>
void LinearStack<T>::pop()
{
	if (this->_top < 0)
	{
		throw std::out_of_range("top < 0");
	}
	if (--this->_top < this->_capacity - GAP)
	{
		shrink();
	}
}
