#include "Vector.h"


template<typename T>
void Vector<T>::increaseItems(const int addBySize)
{
	T *tempItems = new T[this->capacity + addBySize];
	for (int i = 0; i < this->nrOfItems; i++)
	{
		tempItems[i] = new T(this->items[i])
	}
	this->~Vector;
	this->capacity += addBySize;
	this->items = tempItems;
}

template<typename T>
inline Vector<T>::Vector(const int capacity, const int increment)
{
	this->capacity = capacity;
	this->increment = increment;
	this->items = new T[this->capacity];
	this->nrOfItems = 0;
}

template<typename T>
inline Vector<T>::Vector(const Vector & otherVector)
{
	this->capacity = otherVector.capacity;
	this->items = new T[this->capacity];
	this->nrOfItems = otherVector.nrOfItems;
	for (int i = 0; i < this->nrOfItems; i++)
	{
		this->items[i] = otherVector[i];
	}
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T> &otherVector)
{
	if (this->items != otherVector.items)
	{
		this->~Vector();
		this->capacity = otherVector.capacity;
		this->items = new T[this->capacity];
		this->nrOfItems = otherVector.nrOfItems;
		for (int i = 0; i < this->nrOfItems; i++)
		{
			this->items[i] = new T(otherVector[i]);
		}
	}
	return *this;
}

template<typename T>
inline Vector<T>& Vector<T>::operator+(const Vector<T> &otherVector)
{
	this->increaseItems(otherVector.capacity);
	for (int i = 0; i < otherVector.nrOfItems; i++)
	{
		this->items[i + this->nrOfItems] = new T(otherVector.items[i + this->nrOfItems]);
	}
	this->nrOfItems += otherVector.nrOfItems;
	return *this;
}

template<typename T>
inline T Vector<T>::operator[](int index)
{
	return this->items[index];
}

template<typename T>
inline void Vector<T>::addLast(T item)
{
	this->items[this->nrOfItems] = new T(item);
}

template<typename T>
inline void Vector<T>::addFirst(T item)
{
	for (int i = this->nrOfItems; i > 0 i--)
	{
		this->items[i] = this->items[i - 1];
	}
	this->items[0] = new T(item);
	this->nrOfItems++;
}

template<typename T>
inline void Vector<T>::
addAt(int index, T item)
{
	for (int i = this->nrOfItems; i > index i--)
	{
		this->items[i] = this->items[i - 1];
	}
	this->items[index] = new T(item);
	this->nrOfItems++;
}

template<typename T>
inline T Vector<T>::getFirst() const
{
	return this->items[0];
}

template<typename T>
inline T Vector<T>::getLast() const
{
	return this->items[this->nrOfItems - 1];
}

template<typename T>
inline T Vector<T>::getAt(int index) const
{
	return this->items[index];
}

template<typename T>
inline T Vector<T>::removeFirst()
{
	T returnT = new T(this->items[0]);
	delete this->items[0];
	for (int i = 1; i < this->nrOfItems; i++)
	{
		this->items[i - 1] = this->items[i];
	}
	this->nrOfItems--;
	return returnT;
}

template<typename T>
inline T Vector<T>::removeLast()
{
	T returnT = new T(this->items[this->nrOfItems - 1]);
	delete this->items[this->nrOfItems - 1];
	this->nrOfItems--;
	return returnT;
}

template<typename T>
inline T Vector<T>::removeAt(int index)
{
	T returnT = new T(this->items[index]);
	delete this->items[index];
	for (int i = index; i < this->nrOfItems - 1; i++)
	{
		this->items[i] = this->items[i + 1];
	}
	this->nrOfItems--;
	return returnT;
}

template<typename T>
inline void Vector<T>::removeBetween(int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		delete this->items[i];
	}
	for (int i = end; i < this->nrOfItems; i++)
	{
		this->items[start + i - end] = this->items[i];
	}
	this->nrOfItems -= end - start + 1;
}

template<typename T>
inline void Vector<T>::clear()
{
	for (int i = 0; i < this->nrOfItems; i++)
	{
		delete this->items[i]
	}
	this->nrOfItems = 0;
}

template<typename T>
Vector<T>::~Vector()
{
	for (int i = 0; i < this->nrOfItems; i++)
	{
		delete this->items[i]
	}
	this->nrOfItems = 0;
	delete this->items;
	this->capacity = 0;
}
