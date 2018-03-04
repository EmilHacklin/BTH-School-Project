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
	void swap(const int pos1, const int pos2);
	int partition(const int startPos, const int endPos);
	void quickSort(const int startPos, const int endPos);
public:
	PriorityQueue(const int increment = 10);
	PriorityQueue(const PriorityQueue &originalPriorityQueue);
	PriorityQueue& operator=(const PriorityQueue &originalPriorityQueue);
	virtual void enqueue(const T& element);
	virtual T dequeue() throw(...);
	virtual T front() const throw(...);
	virtual bool isEmpty() const;
	~PriorityQueue();
};

template<typename T>
inline void PriorityQueue<T>::swap(const int pos1, const int pos2)
{
	T temp = this->items[pos1];
	this->items[pos1] = this->items[pos2];
	this->items[pos2] = temp;
}

template<typename T>
inline int PriorityQueue<T>::partition(const int startPos, const int endPos)
{
	int partisionIndex = startPos;
	for (int i = startPos; i < endPos; i++)
	{
		if (this->items[i] > this->items[i + 1])
		{
			swap(i, i + 1);
			partisionIndex++;
		}
	}
	return partisionIndex;
}

template<typename T>
inline void PriorityQueue<T>::quickSort(const int startPos, const int endPos)
{
	if (startPos < endPos)
	{
		int pivotIndex = partition(startPos, endPos);
		this->quickSort(startPos, pivotIndex - 1);
		this->quickSort(pivotIndex + 1, endPos);
	}
}

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
	if (this->capacity == this->nrOfItems)
	{
		T *temp = new T[this->capacity + this->increment];
		for (int i = 0; i < this->nrOfItems; i++)
		{
			temp[i] = T(this->items[i]);
		}
		delete[] this->items;
		this->items = temp;
		this->capacity += this->increment;
	}
	this->items[this->nrOfItems] = element;
	this->nrOfItems++;
	this->quickSort(0, this->nrOfItems);
}

template<typename T>
inline T PriorityQueue<T>::dequeue() throw(...)
{
	if (this->nrOfItems > 0)
	{
		this->nrOfItems--;
		return T(this->items[this->nrOfItems]);
	}
	else
	{
		throw "Exception: queue is empty";
	}
}

template<typename T>
inline T PriorityQueue<T>::front() const throw(...)
{
	if (this->nrOfItems > 0)
	{
		return this->items[this->nrOfItems - 1];
	}
	else
	{
		throw "Exception: queue is empty";
	}
}

template<typename T>
inline bool PriorityQueue<T>::isEmpty() const
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
