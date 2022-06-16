#pragma once
#include <stack>

template<class T>
class STLStack : public IStack<T>
{
	std::stack<T> _base;
public:
	STLStack() {};
	void push(T val) override;
	void pop() override;
	T extract() override;
	const T& top() override;
	size_t size() override;
	bool empty() override;
	~STLStack() {};
};

template<class T>
inline void STLStack<T>::push(T val)
{
	_base.push(val);
}

template<class T>
inline void STLStack<T>::pop()
{
	_base.pop();
}

template<class T>
inline T STLStack<T>::extract()
{
	T tmp = _base.top();
	_base.pop();
	return tmp;
}

template<class T>
inline const T& STLStack<T>::top()
{
	return _base.top();
}

template<class T>
inline size_t STLStack<T>::size()
{
	return _base.size();
}

template<class T>
inline bool STLStack<T>::empty()
{
	return _base.empty();
}
