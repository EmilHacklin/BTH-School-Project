#pragma once
#include "MovingObject.h"
#include"Health.h"

const sf::Vector2f ENEMYIMAGESIZE = sf::Vector2f(64, 64);

class Enemy : public MovingObject
{
private:
	Health health;
	sf::Clock animationClock;
	const int NROFKEYFRAMES = 15;
	const double TIMEDELAY = 0.075;
	const float SPEEDMULTIPLIER = 1;
public:
	Enemy(const sf::Texture &texture = sf::Texture(), const sf::Vector2f sizeOfKeyFrame = sf::Vector2f(), const sf::Vector2f position = sf::Vector2f(), const sf::Vector2f scale = sf::Vector2f(1.0, 1.0));
	Enemy(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale);
	Enemy(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale);
	Enemy(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale);
	Enemy(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale);
	Enemy(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale);
	Enemy(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY);
	Enemy(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY);
	Enemy(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale);
	Enemy(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale);
	Enemy(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY);
	Enemy(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY);
	Enemy(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY);
	Enemy(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY);
	Enemy(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY);
	Enemy(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY);
	Enemy(const Enemy &originalEnemy);
	Enemy& operator=(const Enemy &originalEnemy);
	bool haveCollisionOccurred(sf::FloatRect boundingBox) const;
	bool haveCollisionOccurred(const MovingObject &otherMovingObject) const;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update();
	virtual void update(sf::Vector2i direction);
	void animation();
	bool isAlive() const;
	void reduceHealth();
	~Enemy();
};