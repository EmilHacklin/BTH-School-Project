#pragma once
#include"MovingObject.h"
#include"Health.h"
#include"Projectile.h"

const sf::Vector2f PLAYERIMAGESIZE = sf::Vector2f(95, 151);

class Player : public MovingObject
{
private:
	Health health;
	Projectile* *projectiles;
	int nrOfProjectiles;
	int angle;
	sf::Clock inputClock;
	sf::Clock animationClock;
	const int NROFKEYFRAMES = 11;
	const double TIMEDELAY = 0.075;
	const float SPEEDMULTIPLIER = 5;
	void input();
public:
	Player(const sf::Texture &texture = sf::Texture(), const sf::Vector2f sizeOfKeyFrame = sf::Vector2f(), const sf::Vector2f position = sf::Vector2f(), const sf::Vector2f scale = sf::Vector2f(1.0, 1.0), Projectile* *projectiles = nullptr, const int nrOfProjectiles = 0);
	Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles);
	Player(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles);
	Player(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles);
	Player(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles);
	Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles);
	Player(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles);
	Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles);
	Player(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles);
	Player(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles);
	Player(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles);
	Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles);
	Player(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles);
	Player(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles);
	Player(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles);
	Player(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles);
	Player(const Player &originalPlayer);
	Player& operator=(const Player &originalPlayer);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update();
	void animation(const int direction);
	bool isAlive() const;
	void reduceHealth();
	~Player();
};

