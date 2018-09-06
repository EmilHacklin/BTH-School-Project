#include<SFML\System.hpp>
#include<SFML\Window.hpp>
#include<iostream>

using namespace std;
using namespace sf;

int main()
{
	Window window(VideoMode(800, 600), "Test", 6);
	Event event;

	while (window.isOpen())
	{
		// while there are pending events...
		while (window.pollEvent(event))
		{
			// check the type of the event...
			switch (event.type)
			{
				// window closed
			case Event::Closed:
				window.close();
				break;
			case Event::Resized:
				std::cout << "new width: " << event.size.width << std::endl;
				std::cout << "new height: " << event.size.height << std::endl;
				break;
				// key pressed
			case Event::LostFocus:
				//pause;
			case Event::GainedFocus:
				//resume
			case Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					std::cout << "the escape key was pressed" << std::endl;
					std::cout << "control:" << event.key.control << std::endl;
					std::cout << "alt:" << event.key.alt << std::endl;
					std::cout << "shift:" << event.key.shift << std::endl;
					std::cout << "system:" << event.key.system << std::endl;
				}
				break;
			default:// we don't process other types of events
				break;
			}
		}
	}
	return 0;
}
