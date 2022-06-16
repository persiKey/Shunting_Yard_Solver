#pragma once
#include "BaseStack.h"

constexpr int SCALE_FACTOR = 2;

template<class T>
class RatioStack : public BaseStack<T>
{
	void rellocate() override;
	void shrink() override;
public:
	RatioStack();
	~RatioStack() override;
	void push(T val) override;
	void pop() override;
};

template<class T>
 void RatioStack<T>::rellocate()
{
	 this->mem_move(this->_capacity * SCALE_FACTOR);
}

template<class T>
inline void RatioStack<T>::shrink()
{
	this->mem_move(std::max(1,int(this->_capacity / SCALE_FACTOR)));
}

template<class T>
RatioStack<T>::RatioStack()
{
	this->_capacity = 1;
	this->mem_ptr = new T[this->_capacity];
	this->_top = 0;
}

template<class T>
RatioStack<T>::~RatioStack()
{
	delete[] this->mem_ptr;
}

template<class T>
inline void RatioStack<T>::push(T val)
{
	if (this->_top + 1 >= this->_capacity)
		rellocate();
	this->mem_ptr[++this->_top] = val;
}

template<class T>
void RatioStack<T>::pop()
{
	if (this->_top < 0)
		throw std::out_of_range("top < 0");

	if (--this->_top < this->_capacity /2)
		shrink();
}
