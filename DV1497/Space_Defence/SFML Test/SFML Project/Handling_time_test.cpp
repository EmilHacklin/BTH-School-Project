#include<SFML\System.hpp>
#include<SFML\Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

int main()
{
	Clock clock;
	Time times[3];
	times[0] = microseconds(10000);
	times[1] = milliseconds(10);
	times[2] = seconds(0.01f);

	cout << times[0].asMicroseconds() << endl;
	cout << times[0].asMilliseconds() << endl;
	cout << times[0].asSeconds() << endl;
	cin.get();

	Int64 usec = times[0].asMicroseconds();
	Int32 msec = times[1].asMilliseconds();
	float sec = times[2].asSeconds();

	cout << usec << endl;
	cout << msec << endl;
	cout << sec << endl;
	cin.get();

	Time t1 = seconds(0.5f);
	Time t2 = t1 * (Int64)2;
	Time t3 = t1 + t2;
	Time t4 = -t3;

	bool b1 = (t1 == t2);
	bool b2 = (t3 > t4);

	cout << t1.asSeconds() << endl;
	cout << t2.asSeconds() << endl;
	cout << t3.asSeconds() << endl;
	cout << t4.asSeconds() << endl;
	cout << b1 << endl;
	cout << b2 << endl;
	cin.get();


	Time elapsed1 = clock.getElapsedTime();
	cout << elapsed1.asSeconds() << std::endl;
	clock.restart();

	Time elapsed2 = clock.getElapsedTime();
	std::cout << elapsed2.asSeconds() << std::endl;

	cin.get();
	return 0;
}