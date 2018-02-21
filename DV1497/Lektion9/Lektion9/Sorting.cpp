#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

void randomNrs(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void printAll(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "   ";
	}
	cout << endl;
}

void swapThem(int arr[], int firstIndex, int secondIndex)
{
	int tempValue = arr[firstIndex];
	arr[firstIndex] = arr[secondIndex];
	arr[secondIndex] = tempValue;
}


void selectionSort(int arr[], int n)
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
		swapThem(arr, i, smalest);
	}
}



int main()
{
	unsigned int seed = time(0);
	srand(seed);
	const int CAP = 5;
	int arr[CAP];

	randomNrs(arr, CAP);
	printAll(arr, CAP);

	selectionSort(arr, CAP);
	printAll(arr, CAP);

	cin.get();
	return 0;
}