#pragma once
#include "IStack.h"
#include <stdexcept>

constexpr int GAP = 10;

template <class T>
class Stack : public IStack<T>
{
	T* mem_ptr;
	size_t memory_size;

	int top_index;
	size_t logical_size;

	void rellocate();
public:
	Stack();
	~Stack() override;
	void push(T val) override;
	void pop() override;
	T extract() override;
	const T& top() override;
	bool isEmpty();
	size_t size() override;
	
};

template<class T>
void Stack<T>::rellocate()
{
	T* tmp_ptr = new T[memory_size + GAP];
	for (int i = 0; i <= top_index; i++)
	{
		tmp_ptr[i] = mem_ptr[i];
	}
	memory_size += GAP;
	delete[] mem_ptr;
	mem_ptr = tmp_ptr;
}

template<class T>
Stack<T>::Stack()
{
	mem_ptr = new T[GAP];
	memory_size = GAP;
	logical_size = 0;
	top_index = -1;
}

template<class T>
size_t Stack<T>::size()
{
	return top_index + 1;
}

template<class T>
Stack<T>::~Stack()
{
	delete mem_ptr;
}

template<class T>
void Stack<T>::push(T val)
{
	if (top_index + 1 >= memory_size)
	{
		rellocate();
	}
	mem_ptr[++top_index] = val;
}


template<class T>
void Stack<T>::pop()
{
	if (top_index < 0)
	{
		throw std::out_of_range("index < 0");
	}
	--top_index;
}

template<class T>
inline T Stack<T>::extract()
{
	pop();
	return mem_ptr[top_index + 1];
}

template<class T>
const T& Stack<T>::top()
{
	if (top_index < 0)
	{
		throw std::out_of_range("index < 0");
	}
	return mem_ptr[top_index];
}

template<class T>
bool Stack<T>::isEmpty()
{
	return top_index < 0;
}
