#pragma once

template<typename T>
class Vector
{
private:
	T * items;
	int capacity;
	int increment;
	int nrOfItems;
	void expand();
public:
	Vector(const int capacity = 10, const int increment = 10);
	Vector(const Vector &otherVector);
	Vector<T>& operator=(const Vector<T> &otherVector);
	Vector<T>& operator+(const Vector<T> &otherVector);
	T operator[](int index);
	void addLast(T item);
	void addFirst(T item);
	void addAt(int index, T item);
	T getFirst() const throw(...);
	T getLast() const throw(...); //throw tells that the function throws an exception
	T getAt(int index) const throw(...);
	T removeFirst() throw(...);
	T removeLast() throw(...);
	T removeAt(int index) throw(...);
	void removeBetween(int start, int end) throw(...);
	void clear();
	~Vector();
};

template<typename T>
void Vector<T>::expand()
{
	T *tempItems = new T[this->capacity + this->increment];
	for (int i = 0; i < this->nrOfItems; i++)
	{
		tempItems[i] = T(this->items[i])
	}
	this->~Vector;
	this->capacity += this->increment;
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
			this->items[i] = T(otherVector[i]);
		}
	}
	return *this;
}

template<typename T>
inline Vector<T>& Vector<T>::operator+(const Vector<T> &otherVector)
{
	T *tempItems = new T[this->capacity + otherVector.capacity];
	for (int i = 0; i < this->nrOfItems; i++)
	{
		tempItems[i] = T(this->items[i])
	}
	for (int i = 0; i < otherVector.nrOfItems; i++)
	{
		tempItems[i + this->nrOfItems] = T(otherVector.items[i]);
	}
	this->nrOfItems += otherVector.nrOfItems;
	this->capacity += otherVector.capacity;
	delete[] this->items;
	this->items = tempItems;
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
	if (this->nrOfItems == this->capacity)
	{
		this->expand();
	}
	this->items[this->nrOfItems] = new T(item);
}

template<typename T>
inline void Vector<T>::addFirst(T item)
{
	if (this->nrOfItems == this->capacity)
	{
		this->expand();
	}
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
	if (this->nrOfItems == this->capacity)
	{
		this->expand();
	}
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
	if (this->nrOfItems == 0)
	{
		throw "Exception: no elements in vector":
	}
	return this->items[0];
}

template<typename T>
inline T Vector<T>::getLast() const
{
	if (this->nrOfItems == 0)
	{
		throw "Exception: no elements in vector":
	}
	return this->items[this->nrOfItems - 1];
}

template<typename T>
inline T Vector<T>::getAt(int index) const
{
	if (index < 0 || index >= this->nrOfItems)
	{
		throw "Exception: index outside of range of vector":
	}
	return this->items[index];
}

template<typename T>
inline T Vector<T>::removeFirst()
{
	if (this->nrOfItems == 0)
	{
		throw "Exception: can not remove from empty vector":
	}
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
	if (this->nrOfItems == 0)
	{
		throw "Exception: can not remove from empty vector":
	}
	T returnT = new T(this->items[this->nrOfItems - 1]);
	delete this->items[this->nrOfItems - 1];
	this->nrOfItems--;
	return returnT;
}

template<typename T>
inline T Vector<T>::removeAt(int index)
{
	if (index < 0 || index >= this->nrOfItems)
	{
		throw "Exception: index outside of range of vector":
	}
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
	if (start > end)
	{
		throw "Exception: start larger then end":
	}
	else if (start < 0)
	{
		throw "Exception: start outside of range of vector":
	}
	else if (end >= this->nrOfItems)
	{
		throw "Exception: end outside of range of vector":
	}
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
	delete[] this->items;
	this->capacity = 0;
	this->nrOfItems = 0;
}