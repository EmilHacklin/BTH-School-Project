#pragma once

template<typename T>
class IStack
{
public:
	virtual void push(T item) = 0;
	virtual T pop() = 0;
	virtual T peek() const = 0;
	virtual bool isEmpty() const = 0;
	virtual ~IStack() = 0 {};
};