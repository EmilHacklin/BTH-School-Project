#include<iostream>

using namespace std;

unsigned int factorial(unsigned int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}

unsigned int sum(unsigned int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n + sum(n - 1);
	}
}

template<typename T>
int partition(T arr[], int startPos, int endPos)
{
	int partisionIndex = startPos;
	for (int i = startPos; i < endPos; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			swap(arr[i], arr[i + 1]);
			partisionIndex++;
		}
	}
}

template<typename T>
void quicksort(T arr[], int startPos, int endPos)
{
	if (startPos < endPos)
	{
		int pivotIndex = partition(arr, startPos, endPos);
		quicksort(arr[], startPos, pivotIndex - 1);
		quicksort(arr[], pivotIndex + 1, endPos);
	}
}

int main()
{
	unsigned int result = factorial(0);

	cout << "0! = " << result << endl;

	result = factorial(4);

	cout << "4! = " << result << endl;

	result = sum(6);

	cout << "sum(6) = " << result << endl;

	cin.get();
	return 0;
}