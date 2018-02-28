#pragma once
#include"IStack.h"

template<typename T>
class Stack : public IStack<T>
{
private:
	T *items;
	int capacity;
	int increment;
	int top;
	void expand();
public:
	Stack(const int increment = 10);
	Stack(const Stack& orignalStack);
	Stack<T>& operator=(const Stack<T>& orignalStack);
	virtual void push(T item);
	virtual T pop();
	virtual T peek() const;
	virtual bool isEmpty() const;
	~Stack();
};

template<typename T>
inline void Stack<T>::expand()
{
	T *tempItems = new T[this->capacity + this->increment];
	for (int i = 0; i < this->top; i++)
	{
		tempItems[i] = T(this->items[i]);
	}
	delete[] this->items;
	this->items = tempItems;
}

template<typename T>
inline Stack<T>::Stack(const int increment)
{
	this->items = new T[increment];
	this->capacity = increment;
	this->increment = increment;
	this->top = 0;
}

template<typename T>
inline Stack<T>::Stack(const Stack & orignalStack)
{
	this->items = new T[orignalStack.capacity];
	this->capacity = orignalStack.capacity;
	this->increment = orignalStack.increment;
	for (int i = 0; i < orignalStack.top; i++)
	{
		this->items[i] = T(orignalStack.items[i]);
	}
	this->top = orignalStack.top;
}

template<typename T>
inline Stack<T>& Stack<T>::operator=(const Stack<T> &orignalStack)
{
	if (this != &orignalStack)
	{
		delete[] this->items;
		this->items = new T[orignalStack.capacity];
		this->capacity = orignalStack.capacity;
		this->increment = orignalStack.increment;
		for (int i = 0; i < orignalStack.top; i++)
		{
			this->items[i] = T(orignalStack.items[i]);
		}
		this->top = orignalStack.top;
	}
	return *this;
}

template<typename T>
inline void Stack<T>::push(T item)
{
	if (this->capacity == this->top)
	{
		this->expand();
	}
	this->items[this->top] = T(item);
	this->top++;
}

template<typename T>
inline T Stack<T>::pop()
{
	T topItem = this->items[this->top - 1];
	this->top--;
	return topItem;
}

template<typename T>
inline T Stack<T>::peek() const
{
	return this->items[this->top - 1];
}

template<typename T>
inline bool Stack<T>::isEmpty() const
{
	if (this->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline Stack<T>::~Stack()
{
	delete[] this->items;
	this->capacity = 0;
	this->top = 0;
}