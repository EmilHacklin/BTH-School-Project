#include "MovingObject.h"

sf::Vector2u windowSize;
sf::Clock MovingObject::globalClock;
float MovingObject::deltaTime = 0;
float MovingObject::globalSpeed = DEAFULTSPEED;

MovingObject::MovingObject(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame,const sf::Vector2f position , const sf::Vector2f scale) throw(...)
{
	if (position.x < 0 || position.y < 0 || position.x > windowSize.x || position.y > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	this->texture = texture;
	this->sprite = sf::Sprite(this->texture);
	this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(sizeOfKeyFrame.x), static_cast<int>(sizeOfKeyFrame.y));
	this->sprite.setTextureRect(this->keyFrameRect);
	this->sprite.setPosition(position);
	this->sprite.setScale(scale);
}

MovingObject::MovingObject(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale) throw(...)
{
	if (position.x < 0 || position.y < 0 || position.x > windowSize.x || position.y > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	if (this->texture.loadFromFile(filePath))
	{
		this->sprite = sf::Sprite(this->texture);
		this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(sizeOfKeyFrame.x), static_cast<int>(sizeOfKeyFrame.y));
		this->sprite.setTextureRect(this->keyFrameRect);
		this->sprite.setPosition(position);
		this->sprite.setScale(scale);
	}
	else
	{
		throw "Exception: Could not load texture";
	}
}

MovingObject::MovingObject(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale) throw(...)
{
	if (position.x < 0 || position.y < 0 || position.x > windowSize.x || position.y > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	this->texture = texture;
	this->sprite = sf::Sprite(this->texture);
	this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(keyFrameWidth), static_cast<int>(keyFrameHeight));
	this->sprite.setTextureRect(this->keyFrameRect);
	this->sprite.setPosition(position);
	this->sprite.setScale(scale);
}

MovingObject::MovingObject(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale) throw(...)
{
	if (position.x < 0 || position.y < 0 || position.x > windowSize.x || position.y > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	if (this->texture.loadFromFile(filePath))
	{
		this->sprite = sf::Sprite(this->texture);
		this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(keyFrameWidth), static_cast<int>(keyFrameHeight));
		this->sprite.setTextureRect(this->keyFrameRect);
		this->sprite.setPosition(position);
		this->sprite.setScale(scale);
	}
	else
	{
		throw "Exception: Could not load texture";
	}
}

MovingObject::MovingObject(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale) throw(...)
{
	if (positionX < 0 || positionY < 0 || positionX > windowSize.x || positionY > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	this->texture = texture;
	this->sprite = sf::Sprite(this->texture);
	this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(sizeOfKeyFrame.x), static_cast<int>(sizeOfKeyFrame.y));
	this->sprite.setTextureRect(this->keyFrameRect);
	this->sprite.setPosition(positionX, positionY);
	this->sprite.setScale(scale);
}

MovingObject::MovingObject(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale) throw(...)
{
	if (positionX < 0 || positionY < 0 || positionX > windowSize.x || positionY > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	if (this->texture.loadFromFile(filePath))
	{
		this->sprite = sf::Sprite(this->texture);
		this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(sizeOfKeyFrame.x), static_cast<int>(sizeOfKeyFrame.y));
		this->sprite.setTextureRect(this->keyFrameRect);
		this->sprite.setPosition(positionX, positionY);
		this->sprite.setScale(scale);
	}
	else
	{
		throw "Exception: Could not load texture";
	}
}

MovingObject::MovingObject(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY) throw(...)
{
	if (position.x < 0 || position.y < 0 || position.x > windowSize.x || position.y > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	this->texture = texture;
	this->sprite = sf::Sprite(this->texture);
	this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(sizeOfKeyFrame.x), static_cast<int>(sizeOfKeyFrame.y));
	this->sprite.setTextureRect(this->keyFrameRect);
	this->sprite.setPosition(position);
	this->sprite.setScale(scaleX, scaleY);
}

MovingObject::MovingObject(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY) throw(...)
{
	if (position.x < 0 || position.y < 0 || position.x > windowSize.x || position.y > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	if (this->texture.loadFromFile(filePath))
	{
		this->sprite = sf::Sprite(this->texture);
		this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(sizeOfKeyFrame.x), static_cast<int>(sizeOfKeyFrame.y));
		this->sprite.setTextureRect(this->keyFrameRect);
		this->sprite.setPosition(position);
		this->sprite.setScale(scaleX, scaleY);
	}
	else
	{
		throw "Exception: Could not load texture";
	}
}

MovingObject::MovingObject(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale) throw(...)
{
	if (positionX < 0 || positionY < 0 || positionX > windowSize.x || positionY > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	this->texture = texture;
	this->sprite = sf::Sprite(this->texture);
	this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(keyFrameWidth), static_cast<int>(keyFrameHeight));
	this->sprite.setTextureRect(this->keyFrameRect);
	this->sprite.setPosition(positionX, positionY);
	this->sprite.setScale(scale);
}

MovingObject::MovingObject(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale) throw(...)
{
	if (positionX < 0 || positionY < 0 || positionX > windowSize.x || positionY > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	if (this->texture.loadFromFile(filePath))
	{
		this->sprite = sf::Sprite(this->texture);
		this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(keyFrameWidth), static_cast<int>(keyFrameHeight));
		this->sprite.setTextureRect(this->keyFrameRect);
		this->sprite.setPosition(positionX, positionY);
		this->sprite.setScale(scale);
	}
	else
	{
		throw "Exception: Could not load texture";
	}
}

MovingObject::MovingObject(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY) throw(...)
{
	if (positionX < 0 || positionY < 0 || positionX > windowSize.x || positionY > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	this->texture = texture;
	this->sprite = sf::Sprite(this->texture);
	this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(sizeOfKeyFrame.x), static_cast<int>(sizeOfKeyFrame.y));
	this->sprite.setTextureRect(this->keyFrameRect);
	this->sprite.setPosition(positionX, positionY);
	this->sprite.setScale(scaleX, scaleY);
}

MovingObject::MovingObject(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY) throw(...)
{
	if (positionX < 0 || positionY < 0 || positionX > windowSize.x || positionY > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	if (this->texture.loadFromFile(filePath))
	{
		this->sprite = sf::Sprite(this->texture);
		this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(sizeOfKeyFrame.x), static_cast<int>(sizeOfKeyFrame.y));
		this->sprite.setTextureRect(this->keyFrameRect);
		this->sprite.setPosition(positionX, positionY);
		this->sprite.setScale(scaleX, scaleY);
	}
	else
	{
		throw "Exception: Could not load texture";
	}
}

MovingObject::MovingObject(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY) throw(...)
{
	if (position.x < 0 || position.y < 0 || position.x > windowSize.x || position.y > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	this->texture = texture;
	this->sprite = sf::Sprite(this->texture);
	this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(keyFrameWidth), static_cast<int>(keyFrameHeight));
	this->sprite.setTextureRect(this->keyFrameRect);
	this->sprite.setPosition(position);
	this->sprite.setScale(scaleX, scaleY);
}

MovingObject::MovingObject(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY) throw(...)
{
	if (position.x < 0 || position.y < 0 || position.x > windowSize.x || position.y > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	if (this->texture.loadFromFile(filePath))
	{
		this->sprite = sf::Sprite(this->texture);
		this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(keyFrameWidth), static_cast<int>(keyFrameHeight));
		this->sprite.setTextureRect(this->keyFrameRect);
		this->sprite.setPosition(position);
		this->sprite.setScale(scaleX, scaleY);
	}
	else
	{
		throw "Exception: Could not load texture";
	}
}

MovingObject::MovingObject(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY) throw(...)
{
	if (positionX < 0 || positionY < 0 || positionX > windowSize.x || positionY > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	this->texture = texture;
	this->sprite = sf::Sprite(this->texture);
	this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(keyFrameWidth), static_cast<int>(keyFrameHeight));
	this->sprite.setTextureRect(this->keyFrameRect);
	this->sprite.setPosition(positionX, positionY);
	this->sprite.setScale(scaleX, scaleY);
}

MovingObject::MovingObject(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY) throw(...)
{
	if (positionX < 0 || positionY < 0 || positionX > windowSize.x || positionY > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	if (this->texture.loadFromFile(filePath))
	{
		this->sprite = sf::Sprite(this->texture);
		this->keyFrameRect = sf::IntRect(0, 0, static_cast<int>(keyFrameWidth), static_cast<int>(keyFrameHeight));
		this->sprite.setTextureRect(this->keyFrameRect);
		this->sprite.setPosition(positionX, positionY);
		this->sprite.setScale(scaleX, scaleY);
	}
	else
	{
		throw "Exception: Could not load texture";
	}
}

MovingObject::MovingObject(const MovingObject & originalObject)
{
	this->texture = originalObject.texture;
	this->sprite = sf::Sprite(this->texture);
	this->keyFrameRect = originalObject.getKeyFrameRect();
	this->sprite.setTextureRect(this->keyFrameRect);
	this->sprite.setPosition(originalObject.getPosition());
	this->sprite.setScale(originalObject.sprite.getScale());
}

MovingObject & MovingObject::operator=(const MovingObject & originalObject)
{
	if (&originalObject != this)
	{
		this->~MovingObject();
		this->texture = originalObject.texture;
		this->sprite = sf::Sprite(this->texture);
		this->keyFrameRect = originalObject.getKeyFrameRect();
		this->sprite.setTextureRect(this->keyFrameRect);
		this->sprite.setPosition(originalObject.getPosition());
		this->sprite.setScale(originalObject.sprite.getScale());
	}
	return *this;
}

sf::Vector2f MovingObject::getPosition() const
{
	return this->sprite.getPosition();
}

sf::Vector2u MovingObject::getSizeOfTexture() const
{
	return this->texture.getSize();
}

sf::IntRect MovingObject::getKeyFrameRect() const
{
	return this->keyFrameRect;
}

sf::FloatRect MovingObject::getGlobalBoundingBox() const
{
	return this->sprite.getGlobalBounds();
}

bool MovingObject::intersects(const MovingObject & otherMovingObject) const
{
	if (this->sprite.getGlobalBounds().intersects(otherMovingObject.sprite.getGlobalBounds()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MovingObject::setTexture(const string filePath, const sf::Vector2u sizeOfKeyFrame) throw(...)
{
	if (this->texture.loadFromFile(filePath))
	{
		sf::Vector2f pos = this->sprite.getPosition();
		this->sprite = sf::Sprite(this->texture);
		this->setPosition(pos);
		this->keyFrameRect = sf::IntRect(0, 0, sizeOfKeyFrame.x, sizeOfKeyFrame.y);
		this->sprite.setTextureRect(this->keyFrameRect);
	}
	else
	{
		throw "Exception: Could not load texture";
	}
}

void MovingObject::setTexture(const sf::Texture texture, const sf::Vector2u sizeOfKeyFrame)
{
	sf::Vector2f pos = this->sprite.getPosition();
	this->texture = sf::Texture(texture);
	this->sprite = sf::Sprite(this->texture);
	this->setPosition(pos);
	this->keyFrameRect = sf::IntRect(0, 0, sizeOfKeyFrame.x, sizeOfKeyFrame.y);
	this->sprite.setTextureRect(this->keyFrameRect);
}

void MovingObject::setKeyFrameRect(const sf::IntRect keyFrameRect) throw(...)
{
	if (keyFrameRect.width > this->texture.getSize().y || keyFrameRect.height > this->texture.getSize().y)
	{
		throw "Exception: keyFrame to big";
	}
	else if (keyFrameRect.left < 0 || keyFrameRect.left > this->texture.getSize().x
		|| keyFrameRect.top < 0 || keyFrameRect.top > this->texture.getSize().y)
	{
		throw "Exception: Invalid keyFrame position";
	}
	else if (keyFrameRect.left + keyFrameRect.width > this->texture.getSize().x || keyFrameRect.top + keyFrameRect.height > this->texture.getSize().y)
	{
		throw "Exception: Invalid keyFrame position and size";
	}
	this->keyFrameRect = keyFrameRect;
	this->sprite.setTextureRect(this->keyFrameRect);
}

void MovingObject::setKeyFrameRect(const int left, const int top, const int width, const int height) throw(...)
{
	if (width > this->texture.getSize().y || height > this->texture.getSize().y)
	{
		throw "Exception: keyFrame to big";
	}
	else if (left < 0 || left > this->texture.getSize().x
		|| top < 0 || top > this->texture.getSize().y)
	{
		throw "Exception: Invalid keyFrame position";
	}
	else if (left + width > this->texture.getSize().x || top + height > this->texture.getSize().y)
	{
		throw "Exception: Invalid keyFrame position and size";
	}
	this->keyFrameRect.left = left;
	this->keyFrameRect.top = top;
	this->keyFrameRect.width = width;
	this->keyFrameRect.height = height;
	this->sprite.setTextureRect(this->keyFrameRect);
}

void MovingObject::setPosition(const sf::Vector2f position) throw(...)
{
	if (position.x < 0 || position.y < 0 || position.x > windowSize.x || position.y > windowSize.y)
	{
		throw "Exception: Invalid coordinates";
	}
	this->sprite.setPosition(position);
}

void MovingObject::setPosition(const float positionX, const float positionY) throw(...)
{
	if (positionX < 0 || positionY < 0 || positionX > windowSize.x || positionY > windowSize.y)
	{
		throw "Exception: Invalid coordinates";
	}
	this->sprite.setPosition(positionX, positionY);
}

void MovingObject::setScale(sf::Vector2f scale)
{
	if (scale.x < 0 || scale.y < 0)
	{
		throw "Exception: Scale can not be smaller then 0";
	}
	this->sprite.setScale(scale);
}

void MovingObject::setScale(const float scaleX, const float scaleY)
{
	if (scaleX < 0 || scaleY < 0)
	{
		throw "Exception: Scale can not be smaller then 0";
	}
	this->sprite.setScale(scaleX, scaleY);
}

void MovingObject::resetGlobalClock()
{
	MovingObject::deltaTime = MovingObject::globalClock.restart().asSeconds();
}

float MovingObject::getSpeed()
{
	return MovingObject::globalSpeed;
}

void MovingObject::increaseSpeed()
{
	MovingObject::globalSpeed += 25;
}

void MovingObject::resetSpeed()
{
	MovingObject::globalSpeed = DEAFULTSPEED;
}

void MovingObject::move(const sf::Vector2i direction, const float speedMultiplier)
{
	if (direction.x == -1 && this->sprite.getPosition().x > 0)
	{
		this->sprite.move(-this->globalSpeed * this->deltaTime * this->sprite.getScale().x * speedMultiplier, 0);
	}
	else if (direction.x == 1 && this->sprite.getPosition().x + this->sprite.getGlobalBounds().width < windowSize.x)
	{
		this->sprite.move(this->globalSpeed * this->deltaTime * this->sprite.getScale().x * speedMultiplier, 0);
	}
	else if (direction.y == -1 && this->sprite.getPosition().y > 0)
	{
		this->sprite.move(0, -this->globalSpeed * this->deltaTime * this->sprite.getScale().y * speedMultiplier);
	}
	else if (direction.y == 1 && this->sprite.getPosition().y + this->sprite.getGlobalBounds().height < windowSize.y)
	{
		this->sprite.move(0, this->globalSpeed * this->deltaTime * this->sprite.getScale().y * speedMultiplier);
	}
}

void MovingObject::move(const int directionX, const int directionY, const float speedMultiplier)
{
	if (directionX == -1 && this->sprite.getPosition().x > 0)
	{
		this->sprite.move(-this->globalSpeed * this->deltaTime * this->sprite.getScale().x * speedMultiplier, 0);
	}
	else if (directionX == 1 && this->sprite.getPosition().x + this->sprite.getGlobalBounds().width < windowSize.x)
	{
		this->sprite.move(this->globalSpeed * this->deltaTime * this->sprite.getScale().x * speedMultiplier, 0);
	}
	else if (directionY == -1 && this->sprite.getPosition().y > 0)
	{
		this->sprite.move(0, -this->globalSpeed * this->deltaTime * this->sprite.getScale().x * speedMultiplier);
	}
	else if (directionY == 1 && this->sprite.getPosition().y + this->sprite.getGlobalBounds().height < windowSize.y)
	{
		this->sprite.move(0, this->globalSpeed * this->deltaTime * this->sprite.getScale().x * speedMultiplier);
	}
}

void MovingObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);
}

MovingObject::~MovingObject()
{
	//this->texture.~Texture(); //helps with memory leaks no idea why???
}