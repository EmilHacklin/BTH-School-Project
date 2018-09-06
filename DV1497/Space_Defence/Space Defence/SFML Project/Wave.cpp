#include "Wave.h"

Wave::Wave(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f scale, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(texture, sizeOfKeyFrame, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scale);
	}
}

Wave::Wave(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f scale, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(filePath, sizeOfKeyFrame, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), yOffset, scale);
	}
}

Wave::Wave(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f scale, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(texture, keyFrameWidth, keyFrameHeight, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scale);
	}
}

Wave::Wave(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f scale, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(filePath, keyFrameWidth, keyFrameHeight, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scale);
	}
}

Wave::Wave(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float scaleX, const float scaleY, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(texture, sizeOfKeyFrame, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0, scaleX, scaleY);
	}
}

Wave::Wave(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float scaleX, const float scaleY, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(filePath, sizeOfKeyFrame, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0, scaleX, scaleY);
	}
}

Wave::Wave(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const float scaleX, const float scaleY, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];;
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(texture, keyFrameWidth, keyFrameHeight, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scaleX, scaleY);
	}
}

Wave::Wave(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float scaleX, const float scaleY, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(filePath, keyFrameWidth, keyFrameHeight, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scaleX, scaleY);
	}
}

Wave::Wave(const Wave &originalWave)
{
	this->nrOfEnemies = originalWave.nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(*originalWave.enemies[i]);
	}
}

Wave & Wave::operator=(const Wave &originalWave)
{
	if (&originalWave != this)
	{
		this->~Wave();
		this->nrOfEnemies = originalWave.nrOfEnemies;
		this->enemies = new Enemy*[this->nrOfEnemies];
		for (int i = 0; i < this->nrOfEnemies; i++)
		{
			this->enemies[i] = new Enemy(*originalWave.enemies[i]);
		}
	}
	return *this;
}

bool Wave::haveCollisionOccurred(MovingObject &otherMovingObject) const
{
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		if (this->enemies[i]->haveCollisionOccurred(otherMovingObject))
		{
			return true;
		}
	}
	return false;
}

int Wave::indexIfCollisionOccurred(MovingObject & otherMovingObject) const
{
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		if (this->enemies[i]->haveCollisionOccurred(otherMovingObject))
		{
			return i;
		}
	}
	return -1;
}

void Wave::reduceHealthOfEnemy(const int index) throw(...)
{
	if (index < 0 || index >= this->nrOfEnemies)
	{
		throw "Exception: Invalid enemy index";
	}
	else
	{
		this->enemies[index]->reduceHealth();
		if (!this->enemies[index]->isAlive())
		{
			delete this->enemies[index];
			if (index != this->nrOfEnemies - 1)
			{
				this->enemies[index] = this->enemies[this->nrOfEnemies - 1];
			}
			this->nrOfEnemies--;
		}
	}
}

bool Wave::isWaveDestroyed() const
{
	if (this->nrOfEnemies == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Wave::getNrOfEnemies() const
{
	return this->nrOfEnemies;
}

sf::Vector2f Wave::getPositionOfEnemy(const int index) const throw(...)
{
	if (index < 0 || index >= this->nrOfEnemies)
	{
		throw "Exception: Invalid enemy index";
	}
	else
	{
		return this->enemies[index]->getPosition();
	}
}

void Wave::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i]->draw(target, states);
	}
}

void Wave::update()
{
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i]->update();
	}
}

void Wave::update(const sf::Vector2i direction)
{
	if (this->nrOfEnemies > 0)
	{
		if (direction.x == -1)
		{
			this->enemies[0]->update(direction);
			if (this->nrOfEnemies > 2)
			{
				for (int i = 1; i < this->nrOfEnemies; i++)
				{
					if (!this->enemies[i]->intersects(*this->enemies[i - 1]))
					{
						this->enemies[i]->update(direction);
					}
					else
					{
						this->enemies[i]->update();
					}
				}
			}
			if (this->nrOfEnemies > 1 && !this->enemies[this->nrOfEnemies - 1]->intersects(*this->enemies[this->nrOfEnemies - 2]))
			{
				this->enemies[this->nrOfEnemies - 1]->update(direction);
			}
			else
			{
				this->enemies[this->nrOfEnemies - 1]->update();
			}
		}
		else if (direction.x == 1)
		{
			this->enemies[this->nrOfEnemies - 1]->update(direction);
			if (this->nrOfEnemies > 2)
			{
				for (int i = this->nrOfEnemies - 2; i > 0; i--)
				{
					if (!this->enemies[i]->intersects(*this->enemies[i + 1]))
					{
						this->enemies[i]->update(direction);
					}
					else
					{
						this->enemies[i]->update();
					}
				}
			}
			if (this->nrOfEnemies > 1 && !this->enemies[0]->intersects(*this->enemies[1]))
			{
				this->enemies[0]->update(direction);
			}
			else
			{
				this->enemies[0]->update();
			}
		}
		else if (direction.y == 1)
		{
			for (int i = 0; i < this->nrOfEnemies; i++)
			{
				this->enemies[i]->update(direction);
			}
		}
		else
		{
			for (int i = 0; i < this->nrOfEnemies; i++)
			{
				this->enemies[i]->update();
			}
		}
	}
}

void Wave::update(const sf::Vector2i direction, Wave* *otherWaves, const int nrOfWaves, const int curentIndex)
{
	if (this->nrOfEnemies > 0)
	{
		bool CollisionOccurred;
		int index;
		if (direction.x == -1)
		{
			CollisionOccurred = false;
			index = 0;
			while (!CollisionOccurred && index < nrOfWaves)
			{
				if (index != curentIndex && otherWaves[index]->haveCollisionOccurred(*this->enemies[0]))
				{
					CollisionOccurred = true;
				}
				else
				{
					index++;
				}
			}
			if (!CollisionOccurred)
			{
				this->enemies[0]->update(direction);
			}
			else
			{
				this->enemies[0]->update();
			}
			for (int i = 1; i < this->nrOfEnemies; i++)
			{
				CollisionOccurred = false;
				index = 0;
				while (!CollisionOccurred && index < nrOfWaves)
				{
					if (index != curentIndex && otherWaves[index]->haveCollisionOccurred(*this->enemies[1]))
					{
						CollisionOccurred = true;
					}
					else
					{
						index++;
					}
				}
				if (!CollisionOccurred && !this->enemies[i]->intersects(*this->enemies[i - 1]))
				{
					this->enemies[i]->update(direction);
				}
				else
				{
					this->enemies[i]->update();
				}
			}
		}
		else if (direction.x == 1)
		{
			CollisionOccurred = false;
			index = 0;
			while (!CollisionOccurred && index < nrOfWaves)
			{
				if (index != curentIndex && otherWaves[index]->haveCollisionOccurred(*this->enemies[this->nrOfEnemies - 1]))
				{
					CollisionOccurred = true;
				}
				else
				{
					index++;
				}
			}
			if (!CollisionOccurred)
			{
				this->enemies[this->nrOfEnemies - 1]->update(direction);
			}
			else
			{
				this->enemies[this->nrOfEnemies - 1]->update();
			}
			for (int i = this->nrOfEnemies - 2; i >= 0; i--)
			{
				CollisionOccurred = false;
				index = 0;
				while (!CollisionOccurred && index < nrOfWaves)
				{
					if (index != curentIndex && otherWaves[index]->haveCollisionOccurred(*this->enemies[i]))
					{
						CollisionOccurred = true;
					}
					else
					{
						index++;
					}
				}
				if (!CollisionOccurred && !this->enemies[i]->intersects(*this->enemies[i + 1]))
				{
					this->enemies[i]->update(direction);
				}
				else
				{
					this->enemies[i]->update();
				}
			}
		}
		else if (direction.y == 1)
		{
			for (int i = this->nrOfEnemies - 1; i >= 0; i--)
			{
				CollisionOccurred = false;
				index = 0;
				while (!CollisionOccurred && index < nrOfWaves)
				{
					if (index != curentIndex && otherWaves[index]->haveCollisionOccurred(*this->enemies[i]))
					{
						CollisionOccurred = true;
					}
					else
					{
						index++;
					}
				}
				if (!CollisionOccurred)
				{
					this->enemies[i]->update(direction);
				}
				else
				{
					this->enemies[i]->update();
				}
			}
		}
		else
		{
			for (int i = 0; i < this->nrOfEnemies; i++)
			{
				this->enemies[i]->update();
			}
		}
	}
}

Wave::~Wave()
{
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		delete this->enemies[i];
	}
	this->nrOfEnemies = 0;
	delete[] this->enemies;
	cout << "Deleting Wave" << endl;
}
