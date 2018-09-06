#pragma once
#include "MovingObject.h"

const sf::Vector2f PROJECTILEIMAGESIZE = sf::Vector2f(30, 30);

class Projectile : public MovingObject
{
private:
	const float SPEEDMULTIPLIER = 10;
public:
	Projectile(const sf::Texture &texture = sf::Texture(), const sf::Vector2f sizeOfKeyFrame = sf::Vector2f(), const sf::Vector2f position = sf::Vector2f(), const sf::Vector2f scale = sf::Vector2f(1.0, 1.0));
	Projectile(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale);
	Projectile(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale);
	Projectile(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale);
	Projectile(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale);
	Projectile(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale);
	Projectile(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY);
	Projectile(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY);
	Projectile(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale);
	Projectile(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale);
	Projectile(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY);
	Projectile(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY);
	Projectile(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY);
	Projectile(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY);
	Projectile(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY);
	Projectile(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY);
	Projectile(const Projectile &originalProjectile);
	Projectile& operator=(const Projectile &originalProjectile);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update();
	bool isActive() const;
	~Projectile();
};

