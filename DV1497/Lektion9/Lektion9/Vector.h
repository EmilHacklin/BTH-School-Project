#pragma once

template<typename T>
class Vector
{
private:
	T * items;
	int capacity;
	int nrOfItems;
public:
	Vector(const int capacity = 10, const int increment = 10);
	Vector(const Vector &otherVector);
	Vector& operator=(const Vector &otherVector);
	Vector& operator+(const Vector &otherVector);
	T operator[](int index);
	void addLast(T item);
	void addFirst(T item);
	void addAt(int index, T item);
	T getFirst() const;
	T getLast() const;
	T getAt(int index) const;
	T removeFirst();
	T removeLast();
	T removeAt(int index);
	void removeBetween(int start, int end);
	void clear();
	~Vector();
};