#pragma once
#include<SFML\System.hpp>
#include<SFML\Graphics.hpp>
#include<iostream>
#include<string>

using namespace std;

extern sf::Vector2u windowSize;
const float DEAFULTSPEED = 100;

class MovingObject : public sf::Transformable, public sf::Drawable
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::IntRect keyFrameRect;
	static sf::Clock globalClock;
	static float deltaTime;
	static float globalSpeed;
public:
	MovingObject(const sf::Texture &texture = sf::Texture(), const sf::Vector2f sizeOfKeyFrame = sf::Vector2f(), const sf::Vector2f position = sf::Vector2f(), const sf::Vector2f scale = sf::Vector2f(1.0, 1.0)) throw (...);
	MovingObject(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale) throw (...);
	MovingObject(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale) throw (...);
	MovingObject(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale) throw (...);
	MovingObject(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale) throw (...);
	MovingObject(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale) throw (...);
	MovingObject(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY) throw (...);
	MovingObject(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY) throw (...);
	MovingObject(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale) throw (...);
	MovingObject(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale) throw (...);
	MovingObject(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY) throw (...);
	MovingObject(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY) throw (...);
	MovingObject(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY) throw (...);
	MovingObject(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY) throw (...);
	MovingObject(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY) throw (...);
	MovingObject(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY) throw (...);
	MovingObject(const MovingObject &originalObject);
	MovingObject& operator=(const MovingObject &originalObject);
	sf::Vector2f getPosition() const;
	sf::Vector2u getSizeOfTexture() const;
	sf::IntRect getKeyFrameRect() const;
	sf::FloatRect getGlobalBoundingBox() const;
	bool intersects(const MovingObject &otherMovingObject) const;
	void setTexture(const string filePath, const sf::Vector2u sizeOfKeyFrame) throw(...);
	void setTexture(const sf::Texture texture, const sf::Vector2u sizeOfKeyFrame);
	void setKeyFrameRect(const sf::IntRect keyFrameRect) throw(...);
	void setKeyFrameRect(const int left, const int top, const int width, const int height) throw(...);
	void setPosition(const sf::Vector2f position) throw(...);
	void setPosition(const float positionX, const float positionY) throw(...);
	void setScale(sf::Vector2f scale) throw(...);
	void setScale(const float scaleX, const float scaleY) throw(...);
	static void resetGlobalClock();
	static float getSpeed();
	static void increaseSpeed();
	static void resetSpeed();
	void move(const sf::Vector2i direction, const float speedMultiplier);
	void move(const int directionX, const int directionY, const float speedMultiplier);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update() = 0;
	~MovingObject();
};

