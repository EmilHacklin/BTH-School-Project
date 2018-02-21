#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>

using namespace std;

void randomNrs(int arr[], int n)
{
	unsigned int seed = static_cast<unsigned int>(time(0));
	srand(seed);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

template<typename T>
void printAll(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "   ";
	}
	cout << endl;
}

template<typename T>
void swapThem(T &first, T &second)
{
	T tempValue = first;
	first = second;
	second = tempValue;
}

template<typename T>
void bubbleSort(T arr[], int n)
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 1; x < n - y; x++)
		{
			if (arr[x] < arr[x - 1])
			{
				swapThem(arr[x], arr[x - 1]);
			}
		}
	}
}

template<typename T>
void selectionSort(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int smalest = i;
		for (int k = i + 1; k < n; k++)
		{
			if (arr[k] < arr[smalest])
			{
				smalest = k;
			}
		}
		swapThem(arr[i], arr[smalest]);
	}
}

template<typename T>
void insertionSort(T arr[], int n)
{
	for (int y = 1; y < n; y++)
	{
		int x = y;
		bool change = true;
		while (change && x > 0)
		{
			if (arr[x] < arr[x - 1])
			{
				swapThem(arr[x], arr[x - 1]);
			}
			else
			{
				change = false;
			}
			x--;
		}
	}
}

template<typename T>
void quickSort(T arr[], int indexStart, int indexEnd)
{
	if (indexStart < indexEnd)
	{
		int partisionIndex = indexStart;
		for (int i = indexStart + 1; i < indexEnd; i++)
		{
			if (arr[i] < arr[indexStart])
			{
				partisionIndex++;
				swapThem(arr[partisionIndex], arr[i]);
			}
		}
		swap(arr[partisionIndex], arr[indexStart]);
		quickSort(arr, indexStart, partisionIndex);
		quickSort(arr, partisionIndex + 1, indexEnd);
	}
}

int main()
{
	unsigned int seed = static_cast<unsigned int>(time(0));
	srand(seed);
	const int CAP = 5;
	int arr[CAP];

	randomNrs(arr, CAP);
	printAll(arr, CAP);

	selectionSort(arr, CAP);
	printAll(arr, CAP);

	string animals[] = { "fox", "cat", "cow", "dog", "snake", "fly", "horse" };
	printAll(animals, 7);

	selectionSort(animals, 7);
	printAll(animals, 7);

	randomNrs(arr, CAP);
	printAll(arr, CAP);

	quickSort(arr, 0, CAP);
	printAll(arr, CAP);

	string animals2[] = { "fox", "cat", "cow", "dog", "snake", "fly", "horse" };
	printAll(animals2, 7);

	quickSort(animals2, 0, 7);
	printAll(animals2, 7);

	randomNrs(arr, CAP);
	printAll(arr, CAP);

	insertionSort(arr, CAP);
	printAll(arr, CAP);

	string animals3[] = { "fox", "cat", "cow", "dog", "snake", "fly", "horse" };
	printAll(animals3, 7);

	insertionSort(animals3, 7);
	printAll(animals3, 7);

	randomNrs(arr, CAP);
	printAll(arr, CAP);

	bubbleSort(arr, CAP);
	printAll(arr, CAP);

	string animals4[] = { "fox", "cat", "cow", "dog", "snake", "fly", "horse" };
	printAll(animals4, 7);

	bubbleSort(animals4, 7);
	printAll(animals4, 7);

	cin.get();
	return 0;
}