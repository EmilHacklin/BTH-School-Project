#include"Vector.h"
#include<string>
#include<iostream>

using namespace std;

int main()
{
	Vector<int> nrs;
	//Vector<string> names;

	try
	{
		cout << nrs.getLast() << endl;
	}
	catch (char* exep)
	{
		cout << exep << endl;
	}

	cin.get();
}