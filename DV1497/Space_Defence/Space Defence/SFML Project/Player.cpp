#include "Player.h"

void Player::input()
{
	sf::IntRect keyFrameRect = this->getKeyFrameRect();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(-1, 0, Player::SPEEDMULTIPLIER);
		this->animation(-1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(1, 0, Player::SPEEDMULTIPLIER);
		this->animation(1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->inputClock.getElapsedTime().asSeconds() >= 0.5)
	{
		int i = 0;
		sf::Vector2f position = this->getPosition();
		while (this->projectiles[i]->isActive() && i < this->nrOfProjectiles - 1)
		{
			i++;
		}
		this->projectiles[i]->setPosition(position.x + (this->getGlobalBoundingBox().width / 2) - (this->projectiles[i]->getGlobalBoundingBox().width / 2), position.y);
		this->inputClock.restart();
	}
	else
	{
		this->animation(0);
	}
}

Player::Player(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, sizeOfKeyFrame, position, scale)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, sizeOfKeyFrame, position, scale)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, keyFrameWidth, keyFrameHeight, position, scale)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, position, scale)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, sizeOfKeyFrame, positionX, positionY, scale)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, sizeOfKeyFrame, positionX, positionY, scale)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, sizeOfKeyFrame, position, scaleX, scaleY)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, sizeOfKeyFrame, position, scaleX, scaleY)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, keyFrameWidth, keyFrameHeight, positionX, positionY, scale)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, positionX, positionY, scale)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, sizeOfKeyFrame, positionX, positionY, scaleX, scaleY)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, sizeOfKeyFrame, positionX, positionY, scaleX, scaleY)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, keyFrameWidth, keyFrameHeight, position, scaleX, scaleY)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, position, scaleX, scaleY)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, keyFrameWidth, keyFrameHeight, positionX, positionY, scaleX, scaleY)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, positionX, positionY, scaleX, scaleY)
{
	this->health;
	this->nrOfProjectiles = nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = projectiles[i];
	}
	this->angle = 0;
	this->inputClock;
	this->animationClock;
}

Player::Player(const Player &originalPlayer):
	MovingObject(originalPlayer)
{
	this->health = originalPlayer.health;
	this->nrOfProjectiles = originalPlayer.nrOfProjectiles;
	this->projectiles = new Projectile*[this->nrOfProjectiles];
	for (int i = 0; i < this->nrOfProjectiles; i++)
	{
		this->projectiles[i] = originalPlayer.projectiles[i];
	}
	this->angle = originalPlayer.angle;
	this->inputClock = originalPlayer.inputClock;
	this->animationClock = originalPlayer.animationClock;
}

Player & Player::operator=(const Player &originalPlayer)
{
	if (&originalPlayer != this)
	{
		this->~Player();
		MovingObject::operator=(originalPlayer);
		this->health = originalPlayer.health;
		this->nrOfProjectiles = originalPlayer.nrOfProjectiles;
		this->projectiles = new Projectile*[this->nrOfProjectiles];
		for (int i = 0; i < this->nrOfProjectiles; i++)
		{
			this->projectiles[i] = originalPlayer.projectiles[i];
		}
		this->angle = originalPlayer.angle;
		this->inputClock = originalPlayer.inputClock;
		this->animationClock = originalPlayer.animationClock;
	}
	return *this;
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	MovingObject::draw(target, states);
}

void Player::update()
{
	this->input();
}

void Player::animation(const int direction)
{
	sf::IntRect keyFrameRect = this->getKeyFrameRect();
	if (direction == -1 && this->angle > -(this->NROFKEYFRAMES / 2) && this->animationClock.getElapsedTime().asSeconds() > this->TIMEDELAY)
	{
		if (this->angle >= 0)
		{
			keyFrameRect.top = keyFrameRect.height;
			this->angle = -1;
		}
		else
		{
			keyFrameRect.top += keyFrameRect.height;
			this->angle--;
		}
		this->setKeyFrameRect(keyFrameRect);
		this->animationClock.restart();
	}
	else if (direction == 1 && this->angle < (this->NROFKEYFRAMES / 2) && this->animationClock.getElapsedTime().asSeconds() > this->TIMEDELAY)
	{
		if (this->angle <= 0)
		{
			keyFrameRect.top = keyFrameRect.height * ((this->NROFKEYFRAMES / 2) + 1);
			this->angle = 1;
		}
		else
		{
			keyFrameRect.top += keyFrameRect.height;
			this->angle++;
		}
		this->setKeyFrameRect(keyFrameRect);
		this->animationClock.restart();
	}
	else if (direction == 0 && this->angle != 0 && this->animationClock.getElapsedTime().asSeconds() > TIMEDELAY)
	{
		if (this->angle == 1)
		{
			keyFrameRect.top = 0;
			this->angle--;
		}
		else
		{
			if (this->angle < 0)
			{
				this->angle++;
			}
			else if (this->angle > 0)
			{
				this->angle--;
			}
			keyFrameRect.top -= keyFrameRect.height;
		}
		this->setKeyFrameRect(keyFrameRect);
		this->animationClock.restart();
	}
}

bool Player::isAlive() const
{
	return this->health.isAlive();
}

void Player::reduceHealth()
{
	this->health.reduceHealthPoints();
}

Player::~Player()
{
	delete[] this->projectiles;
	cout << "Deleting Player" << endl;
}