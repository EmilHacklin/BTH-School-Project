#include<iostream>
#include<vector>
#include<SFML\System.hpp>
#include<SFML\Graphics.hpp>

using namespace std;
using namespace sf;

void eventTest(RenderWindow &window, Sprite &sprite, Sprite &obstacle)
{
	Event event;
	window.pollEvent(event);
	Vector2u windowSize = window.getSize();
	Vector2f spritePos = sprite.getPosition();
	FloatRect spriteBoundingBox, obstacleBoundingBox;
	switch (event.type)
	{
	case Event::Closed:
		window.close();
		break;
	case Event::KeyPressed:
		spriteBoundingBox = sprite.getGlobalBounds();
		if (event.key.code == Keyboard::Left)
		{
			if (spritePos.x > 0)
			{
				sprite.move(-5, 0);
				spriteBoundingBox = sprite.getGlobalBounds();
			}
		}
		else if (event.key.code == Keyboard::Right)
		{
			if ((spritePos.x + spriteBoundingBox.width) < windowSize.x)
			{
				sprite.move(5, 0);
				spriteBoundingBox = sprite.getGlobalBounds();
			}
		}
		else if (event.key.code == Keyboard::Up)
		{
			if (spritePos.y > 0)
			{
				sprite.move(0, -5);
				spriteBoundingBox = sprite.getGlobalBounds();
			}
		}
		else if (event.key.code == Keyboard::Down)
		{
			if ((spritePos.y + spriteBoundingBox.height) < windowSize.y)
			{
				sprite.move(0, 5);
				spriteBoundingBox = sprite.getGlobalBounds();
			}
		}
		obstacleBoundingBox = obstacle.getGlobalBounds();
		if (spriteBoundingBox.intersects(obstacleBoundingBox))
		{
			cout << "Collision has occurred!" << endl;

			if (event.key.code == Keyboard::Left)
			{
				sprite.move(20, 0);
			}
			else if (event.key.code == Keyboard::Right)
			{
				sprite.move(-20, 0);
			}
			else if (event.key.code == Keyboard::Up)
			{
				sprite.move(0, 20);
			}
			else if (event.key.code == Keyboard::Down)
			{
				sprite.move(0, -20);
			}
		}
		break;
	default:
		break;
	}
}
 
int main()
{
	RenderWindow window(VideoMode(800, 600), "My window", Style::Close);
	Texture red, green;
	Vector2u sizeOfRed, sizeOfGreen;
	Sprite redBox, greenBox;


	if (!red.loadFromFile("../Resources/Red.png") || !green.loadFromFile("../Resources/Green.png"))
	{
		return -1;
	}

	sizeOfRed = red.getSize();
	sizeOfGreen = red.getSize();
	
	redBox.setTexture(red);
	greenBox.setTexture(green);

	redBox.setPosition((float)(400 - (sizeOfRed.x / 2)), (float)(300 - (sizeOfRed.y / 2)));
	greenBox.setPosition((float)(400 - (sizeOfGreen.x / 2)), (float)(100 - (sizeOfGreen.y / 2)));

	while (window.isOpen())
	{
		window.clear(Color::Black);

		window.draw(redBox);
		window.draw(greenBox);

		eventTest(window, greenBox, redBox);

		window.display();
	}

	return 0;
}