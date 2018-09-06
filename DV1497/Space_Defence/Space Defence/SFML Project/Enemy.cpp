#include "Enemy.h"

Enemy::Enemy(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale):
	MovingObject(texture, sizeOfKeyFrame, position, scale)
{
	this->health = Health(1);
	this->animationClock;
}

Enemy::Enemy(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale) :
	MovingObject(filePath, sizeOfKeyFrame, position, scale)
{
	this->health = Health(1);
	this->animationClock;
}

Enemy::Enemy(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale) :
	MovingObject(texture, keyFrameWidth, keyFrameHeight, position, scale)
{
	this->health;
	this->animationClock;
}

Enemy::Enemy(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale) :
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, position, scale)
{
	this->health = Health(1);
	this->animationClock;
}

Enemy::Enemy(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale) :
	MovingObject(texture, sizeOfKeyFrame, positionX, positionY, scale)
{
	this->health = Health(1);
	this->animationClock;
}

Enemy::Enemy(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale) :
	MovingObject(filePath, sizeOfKeyFrame, positionX, positionY, scale)
{
	this->health = Health(1);
	this->animationClock;
}

Enemy::Enemy(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY) :
	MovingObject(texture, sizeOfKeyFrame, position, scaleX, scaleY)
{
	this->health = Health(1);
	this->animationClock;
}

Enemy::Enemy(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY) :
	MovingObject(filePath, sizeOfKeyFrame, position, scaleX, scaleY)
{
	this->health = Health(1);
	this->animationClock;
}

Enemy::Enemy(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale) :
	MovingObject(texture, keyFrameWidth, keyFrameHeight, positionX, positionY, scale)
{
	this->health = Health(1);
	this->animationClock;
}

Enemy::Enemy(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale) :
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, positionX, positionY, scale)
{
	this->health = Health(1);
	this->animationClock;
}

Enemy::Enemy(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY) :
	MovingObject(texture, sizeOfKeyFrame, positionX, positionY, scaleX, scaleY)
{
	this->health = Health(1);
	this->animationClock;
}

Enemy::Enemy(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY) :
	MovingObject(filePath, sizeOfKeyFrame, positionX, positionY, scaleX, scaleY)
{
	this->health = Health(1);
	this->animationClock;
}

Enemy::Enemy(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY) :
	MovingObject(texture, keyFrameWidth, keyFrameHeight, position, scaleX, scaleY)
{
	this->health = Health(1);
	this->animationClock;
}

Enemy::Enemy(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY) :
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, position, scaleX, scaleY)
{
	this->health = Health(1);
	this->animationClock;
}

Enemy::Enemy(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY) :
	MovingObject(texture, keyFrameWidth, keyFrameHeight, positionX, positionY, scaleX, scaleY)
{
	this->health = Health(1);
	this->animationClock;
}

Enemy::Enemy(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY):
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, positionX, positionY, scaleX, scaleY)
{
	this->health = Health(1);
	this->animationClock;
}

Enemy::Enemy(const Enemy &originalEnemy):
	MovingObject(originalEnemy)
{
	this->health = originalEnemy.health;
	this->animationClock = originalEnemy.animationClock;
}

Enemy & Enemy::operator=(const Enemy &originalEnemy)
{
	if (&originalEnemy != this)
	{
		MovingObject::operator=(originalEnemy);
		this->health = originalEnemy.health;
		this->animationClock = originalEnemy.animationClock;
	}
	return *this;
}

bool Enemy::haveCollisionOccurred(sf::FloatRect boundingBox) const
{
	if (boundingBox.intersects(this->getGlobalBoundingBox()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Enemy::haveCollisionOccurred(const MovingObject & otherMovingObject) const
{
	if (this->intersects(otherMovingObject))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Enemy::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	MovingObject::draw(target, states);
}

void Enemy::update()
{
	this->animation();
}

void Enemy::update(sf::Vector2i direction)
{
	this->move(direction , Enemy::SPEEDMULTIPLIER);
	this->animation();
}

void Enemy::animation()
{
	if (this->animationClock.getElapsedTime().asSeconds() >= this->TIMEDELAY)
	{
		sf::IntRect keyFrame = this->getKeyFrameRect();
		if (keyFrame.left == keyFrame.width * (this->NROFKEYFRAMES - 1))
		{
			this->setKeyFrameRect(sf::IntRect(0, 0, keyFrame.width, keyFrame.height));
		}
		else
		{
			this->setKeyFrameRect(sf::IntRect(keyFrame.left + keyFrame.width, keyFrame.top, keyFrame.width, keyFrame.height));
		}
		this->animationClock.restart();
	}
}

bool Enemy::isAlive() const
{
	return this->health.isAlive();
}

void Enemy::reduceHealth()
{
	this->health.reduceHealthPoints();
}

Enemy::~Enemy()
{
	cout << "Deleting Enemy" << endl;
}
