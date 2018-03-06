#include<iostream>
#include<crtdbg.h>
#include"PriorityQueue.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	PriorityQueue<int> numbers(2); //Sets the increment and capacity to 2 

	numbers.enqueue(2);
	numbers.enqueue(1);

	//Testing the enqueue function and the front function
	cout << "***Front test***" << endl;
	cout << "Expected result: 2 2" << endl;
	cout << "Runtime result: " << numbers.front() << " " << numbers.front() << endl;
	cin.get();

	//Testing the expansion of the queue
	numbers.enqueue(3);
	cout << "***Expansion test***" << endl;
	cout << "Expected result: 3" << endl;
	cout << "Runtime result: " << numbers.front() << endl;
	cin.get();

	//Testing the dequeue function
	cout << "***Dequeue test***" << endl;
	cout << "Expected result: 3 2" << endl;
	cout << "Runtime result: " << numbers.dequeue();
	cout << " " << numbers.front() << endl;
	cin.get();

	//Testing the isEmpty function
	cout << "***isEmpty test***" << endl;
	cout << "Expected result: False" << endl;
	cout << "Runtime result: ";
	if (numbers.isEmpty())
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False"<< endl;
	}
	cin.get();

	//Testing the isEmpty function
	numbers.dequeue();
	numbers.dequeue();
	cout << "***isEmpty test***" << endl;
	cout << "Expected result: True" << endl;
	cout << "Runtime result: ";
	if (numbers.isEmpty())
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cin.get();

	//Testing exception handling for dequeue
	cout << "***Exception handling dequeue test***" << endl;
	cout << "Expected result: Exception: queue is empty" << endl;
	cout << "Runtime result: ";
	try
	{
		numbers.dequeue();
		cout << "No exception" << endl;
	}
	catch (char* excep)
	{
		cout << excep << endl;
	}
	cin.get();
	
	//Testing exception handling for front
	cout << "***Exception handling front test***" << endl;
	cout << "Expected result: Exception: queue is empty" << endl;
	cout << "Runtime result: ";
	try
	{
		numbers.front();
		cout << "No exception" << endl;
	}
	catch (char* excep)
	{
		cout << excep << endl;
	}
	cin.get();

	//Testing the copy constructor
	numbers.enqueue(5);
	numbers.enqueue(4);
	PriorityQueue<int> copyNumbers(numbers);
	cout << "***copy constructor test***" << endl;
	cout << "Expected result: 5 5 6" << endl;
	cout << "Runtime result: " << copyNumbers.dequeue() << " ";
	copyNumbers.enqueue(6);
	cout << numbers.front() << " " << copyNumbers.front() << endl;
	cin.get();

	//Testing the assignment operator
	numbers = copyNumbers;
	cout << "***assignment operator test***" << endl;
	cout << "Expected result: 6 6 7" << endl;
	cout << "Runtime result: " << numbers.front() << " ";
	copyNumbers.enqueue(7);
	cout << numbers.front() << " " << copyNumbers.front() << endl;
	cin.get();

	return 0;
}