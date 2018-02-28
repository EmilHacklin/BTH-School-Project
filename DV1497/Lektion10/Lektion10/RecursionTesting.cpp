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