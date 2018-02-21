#include "Vector.h"


template<typename T>
inline Vector<T>::Vector(const int capacity, const int increment)
{
}

template<typename T>
inline Vector<T>::Vector(const Vector & otherVector)
{
}

template<typename T>
inline Vector & Vector<T>::operator=(const Vector & otherVector)
{
	// TODO: insert return statement here
}

template<typename T>
inline Vector & Vector<T>::operator+(const Vector & otherVector)
{
	// TODO: insert return statement here
}

template<typename T>
inline T Vector<T>::operator[](int index)
{
	return T();
}

template<typename T>
inline void Vector<T>::addLast(T item)
{
}

template<typename T>
inline void Vector<T>::addFirst(T item)
{
}

template<typename T>
inline void Vector<T>::
addAt(int index, T item)
{
}

template<typename T>
inline T Vector<T>::getFirst() const
{
	return T();
}

template<typename T>
inline T Vector<T>::getLast() const
{
	return T();
}

template<typename T>
inline T Vector<T>::getAt(int index) const
{
	return T();
}

template<typename T>
inline T Vector<T>::removeFirst()
{
	return T();
}

template<typename T>
inline T Vector<T>::removeLast()
{
	return T();
}

template<typename T>
inline T Vector<T>::removeAt(int index)
{
	return T();
}

template<typename T>
inline void Vector<T>::removeBetween(int start, int end)
{
}

template<typename T>
inline void Vector<T>::clear()
{
}

template<typename T>
Vector<T>::~Vector()
{
}
