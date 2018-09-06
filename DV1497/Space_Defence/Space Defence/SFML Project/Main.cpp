#include<iostream>
#include<crtdbg.h>
#include"Game.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::VideoMode videoMode;
	int choice = -1;
	vector<sf::VideoMode> resolutionList(videoMode.getFullscreenModes());
	cout << "***Resolution Options***" << endl;
	for (int i = 0; i < static_cast<int>(resolutionList.size()); i++)
	{
		cout << i << ": " << resolutionList[i].height << "X" << resolutionList[i].width << endl;
	}
	
	while (choice < 0 || choice >= static_cast<int>(resolutionList.size()))
	{
		cout << "Pick the resolution: ";
		cin >> choice;
		cin.clear();
		cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');
	}
	cout << "************************" << endl;
	try
	{
		windowSize = sf::Vector2u(resolutionList[choice].width, resolutionList[choice].height);
		sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Space Defence", sf::Style::Close);
		Game game;
		sf::Clock inputClock;
		while (!game.isGameOver() && window.isOpen())
		{
			window.clear(sf::Color());
			sf::Event event;
			window.pollEvent(event);
			if (event.type == sf::Event::EventType::Closed)
			{
				window.close();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && inputClock.getElapsedTime().asSeconds() >= 0.5)
			{
				game.togglePaused();
				inputClock.restart();
			}
			else if (event.type == sf::Event::EventType::GainedFocus)
			{
				game.togglePaused();
			}
			else if (event.type == sf::Event::EventType::LostFocus)
			{
				if (!game.getIsPaused())
				{
					game.togglePaused();
				}
			}
			game.update();
			window.draw(game);
			window.display();
		}
		cout << "************************" << endl;
		cout << "You survived " << game.getNrOfRounds() << " round!\n" << endl;
		cout << "Press enter to quit";
		cin.get();
		return 0;
	}
	catch (char *exepString)
	{
		cout << exepString << endl;
		cin.get();
		return -1;
	}
}