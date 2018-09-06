//#include <SFML/System.hpp>
#include<thread>
#include <iostream>

using namespace std;

void func()
{
	// this function is started when thread.launch() is called

	for (int i = 0; i < 10; ++i)
		cout << "I'm thread number one" << std::endl;
}

int main()
{
	// create a thread with func() as entry point
	thread thread(func);

	// the main thread continues to run...

	for (int i = 0; i < 10; ++i)
		cout << "I'm the main thread" << std::endl;
	
	thread.join(); //The thread joins back up
	cin.get();
	return 0;
}