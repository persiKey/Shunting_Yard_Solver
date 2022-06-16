#pragma once
#include "IStack.h"
#include <stdexcept>

template<class T>
class BaseStack : public IStack<T>
{
protected:
	T* mem_ptr;
	int _top;
	size_t _capacity;

protected:
	void virtual rellocate() = 0;
	void virtual shrink() = 0;
	void virtual mem_move(size_t new_size);

public:
	bool empty() ;
	size_t size();
	T extract() override;
	const T& top() override;
	virtual ~BaseStack() {};
};

template<class T>
inline void BaseStack<T>::mem_move(size_t new_size)
{
	_capacity = new_size;
	T* tmp_ptr = new T[_capacity];
	for (int i = 0; i <= _top; i++)
	{
		tmp_ptr[i] = mem_ptr[i];
	}
	delete[] mem_ptr;
	mem_ptr = tmp_ptr;
}

template<class T>
bool BaseStack<T>::empty()
{
	return _top < 0;
}

template<class T>
size_t BaseStack<T>::size()
{
	return _top + 1;
}

template<class T>
const T& BaseStack<T>::top()
{
	if (_top < 0)
	{
		throw std::out_of_range("top < 0");
	}
	return mem_ptr[_top];
}

template<class T>
 T BaseStack<T>::extract()
{
	T el = this->top();
	this->pop();
	return el;
}