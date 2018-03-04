#pragma once
#include"IPriorityQueue.h"

template <typename T>
class PriorityQueue : public IPriorityQueue<T>
{
private:
	T *items;
	int capacity;
	int increment;
	int nrOfItems;
public:
	PriorityQueue(const int increment = 10);
	PriorityQueue(const PriorityQueue &originalPriorityQueue);
	PriorityQueue& operator=(const PriorityQueue &originalPriorityQueue);
	virtual void enqueue(const T& element);
	virtual T dequeue() throw(...);
	virtual T front() const throw(...);
	virtual bool isEmpty();
	~PriorityQueue();
};

template<typename T>
inline PriorityQueue<T>::PriorityQueue(const int increment)
{
	if (increment <= 0)
	{
		this->increment = 10;
	}
	else
	{
		this->increment = increment;
	}
	this->items = new T[this->increment];
	this->capacity = this->increment;
	this->nrOfItems = 0;
}

template<typename T>
inline PriorityQueue<T>::PriorityQueue(const PriorityQueue & originalPriorityQueue)
{
	this->increment = originalPriorityQueue.capacity;
	this->capacity = originalPriorityQueue.capacity;
	this->items = new T[this->capacity];
	this->nrOfItems = originalPriorityQueue.nrOfItems;
	for (int i = 0; i < this->nrOfItems; i++)
	{
		this->items[i] = T(originalPriorityQueue.items[i]);
	}
}

template<typename T>
inline PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T> &originalPriorityQueue)
{
	if (this != &originalPriorityQueue)
	{
		delete[] this->items;
		this->increment = originalPriorityQueue.capacity;
		this->capacity = originalPriorityQueue.capacity;
		this->items = new T[this->capacity];
		this->nrOfItems = originalPriorityQueue.nrOfItems;
		for (int i = 0; i < this->nrOfItems; i++)
		{
			this->items[i] = T(originalPriorityQueue.items[i]);
		}
	}
	return *this;
}

template<typename T>
inline void PriorityQueue<T>::enqueue(const T & element)
{

}

template<typename T>
inline T PriorityQueue<T>::dequeue() throw(...)
{
	return T();
}

template<typename T>
inline T PriorityQueue<T>::front() const throw(...)
{
	return T();
}

template<typename T>
inline bool PriorityQueue<T>::isEmpty()
{
	if (this->nrOfItems > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<typename T>
inline PriorityQueue<T>::~PriorityQueue()
{
	delete[] this->items;
	this->capacity = 0;
	this->nrOfItems = 0;
}
