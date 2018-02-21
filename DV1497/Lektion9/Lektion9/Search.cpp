#include<iostream>
#include<string>

using namespace std;

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

template<typename T>
int binarySerch(T arr[], T toFind, int n)
{
	if (n > 0)
	{
		int startIndex = 0;
		int endIndex = n - 1;
		int partisionIndex = n / 2;
		while (startIndex <= endIndex && arr[partisionIndex] != toFind)
		{
			if (toFind < arr[partisionIndex])
			{
				endIndex = partisionIndex - 1;
			}
			else
			{
				startIndex = partisionIndex + 1;
			}
			partisionIndex = (startIndex + endIndex) / 2;
		}
		return partisionIndex;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	int awnser = binarySerch(arr, 4, 5);

	cout << to_string(awnser);
	cin.get();
	return 0;
}