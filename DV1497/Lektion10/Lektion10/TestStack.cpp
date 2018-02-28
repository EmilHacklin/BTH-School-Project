#include<iostream>
#include<crtdbg.h>
#include"Stack.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Stack<int> stack;

	if (stack.isEmpty())
	{
		cout << "Correct" << endl;
	}
	else
	{
		cout << "Wrong" << endl;
	}

	stack.push(100);
	cout << "Expected printout: 100 100" << endl;
	cout << "Printout at runtime: ";
	cout << stack.peek() << " ";
	cout << stack.peek() << endl;

	cin.get();

	if (!stack.isEmpty())
	{
		cout << "Correct" << endl;
	}
	else
	{
		cout << "Wrong" << endl;
	}
	
	cin.get();

	cout << "Expected printout: 100" << endl; 
	cout << "Printout at runtime: ";
	cout << stack.pop() << endl;

	cin.get();

	if (stack.isEmpty())
	{
		cout << "Correct" << endl;
	}
	else
	{
		cout << "Wrong" << endl;
	}

	cin.get();

	stack.push(200);
	Stack<int> testCopy(stack);
	stack.push(300);
	cout << "Expected printout: 200" << endl;
	cout << "Printout at runtime: ";
	cout << testCopy.peek() << endl;

	cin.get();

	testCopy = stack;
	cout << "Expected printout: 300" << endl;
	cout << "Printout at runtime: ";
	cout << testCopy.peek() << endl;
	
	cin.get();
	return 0;
}