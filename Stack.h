#pragma once

constexpr int GAP = 10;

template <class T>
class Stack
{
	T* mem_ptr;
	size_t memory_size;

	int top_index;
	size_t logical_size;

	void rellocate();
public:
	Stack();
	~Stack();
	void push_back(const T& val);
	void pop_back();
	T& top();
	bool isEmpty();
	size_t size();
};

#include "Stack.h"

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
void Stack<T>::push_back(const T& val)
{
	if (top_index + 1 >= memory_size)
	{
		rellocate();
	}
	mem_ptr[++top_index] = val;
}


template<class T>
void Stack<T>::pop_back()
{
	if (top_index < 0)
	{
		throw "invalid";
	}
	--top_index;
}

template<class T>
T& Stack<T>::top()
{
	if (top_index < 0)
	{
		throw "invalid";
	}
	return mem_ptr[top_index];
}

template<class T>
bool Stack<T>::isEmpty()
{
	return false;
}


