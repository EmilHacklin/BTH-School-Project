#include<iostream>
#include<string>
#include<crtdbg.h>
#include"PriorityQueue.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	PriorityQueue<int> numbers;
	PriorityQueue<string> words;

	cin.get();
	return 0;
}