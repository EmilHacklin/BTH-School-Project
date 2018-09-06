#include<SFML\System.hpp>
#include<SFML\Window.hpp>
#include<iostream>

using namespace std;
using namespace sf;

int main()
{
	Window window(VideoMode(800, 600), "Test", 6);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				// left key is pressed: move our character
				//character.move(1, 0);
			}
		}
	}
	return 0;
}