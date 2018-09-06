#include "Game.h"

bool Game::isWavesDestroyed()
{
	bool isWavesDestroyed = true;
	for (int i = 0; i < this->nrOfWaves; i++)
	{
		if (this->waves[i]->isWaveDestroyed())
		{
			delete this->waves[i];
			for (int index = i + 1; index < this->nrOfWaves; index++)
			{
				this->waves[index - 1] = this->waves[index];
			}
			this->nrOfWaves --;
		}
		else
		{
			isWavesDestroyed = false;
		}
	}
	return isWavesDestroyed;
}

void Game::havePlayerCollided()
{
	bool haveCollided = false;
	for (int i = 0; i < this->nrOfWaves; i++)
	{
		if (this->waves[i]->haveCollisionOccurred(*this->player))
		{
			haveCollided = true;
		}
	}
	if (haveCollided)
	{
		this->newWaves();
		this->player->reduceHealth();
	}
}

void Game::haveProjectilesCollided()
{
	for (int i = 0; i < this->NROFPROJECTILES; i++)
	{
		if (this->projectiles[i]->isActive())
		{
			int index = -1, x = 0;
			while (index == -1 && x < this->nrOfWaves)
			{
				index = this->waves[x]->indexIfCollisionOccurred(*this->projectiles[i]);
				x++;
			}
			if (index != -1)
			{
				this->waves[x - 1]->reduceHealthOfEnemy(index);
				this->projectiles[i]->setPosition(0, 0);
			}
		}
	}
}

void Game::updateProjectiles()
{
	for (int i = 0; i < this->NROFPROJECTILES; i++)
	{
		if (this->projectiles[i]->isActive())
		{
			this->projectiles[i]->update();
		}
	}
}

void Game::updateWaves()
{
	if (this->lockalClock.getElapsedTime().asSeconds() >= timeDelay)
	{
		if (this->waves[this->nrOfWaves - 1]->getPositionOfEnemy(this->waves[this->nrOfWaves - 1]->getNrOfEnemies() - 1).y >= windowSize.y - (ENEMYIMAGESIZE.y * this->scale.y))
		{
			this->randomNr = rand() % 2;
		}
		else
		{
			this->randomNr = rand() % 3;
		}
		this->lockalClock.restart();
	}
	if (!this->isWavesDestroyed())
	{
		if (this->randomNr == 0)
		{
			if (this->nrOfWaves > 1)
			{
				for (int i = 0; i < this->nrOfWaves; i++)
				{
					this->waves[i]->update(sf::Vector2i(-1, 0), this->waves, this->nrOfWaves, i);
				}
			}
			else
			{
				this->waves[0]->update(sf::Vector2i(-1, 0));
			}
		}
		else if (this->randomNr == 1)
		{
			if (this->nrOfWaves > 1)
			{
				for (int i = 0; i < this->nrOfWaves; i++)
				{
					this->waves[i]->update(sf::Vector2i(1, 0), this->waves, this->nrOfWaves, i);
				}
			}
			else
			{
				this->waves[0]->update(sf::Vector2i(1, 0));
			}

		}
		else if (this->randomNr == 2)
		{
			if (this->nrOfWaves > 1)
			{
				for (int i = 0; i < this->nrOfWaves; i++)
				{
					this->waves[i]->update(sf::Vector2i(0, 1), this->waves, this->nrOfWaves, i);
				}
			}
			else
			{
				this->waves[0]->update(sf::Vector2i(0, 1));
			}
		}
	}
	else
	{
		this->newWaves();
	}
}

void Game::newWaves()
{
	for (int i = 0; i < this->nrOfWaves; i++)
	{
		delete this->waves[i];
	}
	for (int i = 0; i < this->DEAFULTNROFWAVES; i++)
	{
		this->waves[i] = new Wave("../Resources/Enemy.png", ENEMYIMAGESIZE, this->scale, 5, (ENEMYIMAGESIZE.y * i * this->scale.y) + (20 * i));
	}
	this->nrOfWaves = this->DEAFULTNROFWAVES;
	this->nrOfRounds++;
	MovingObject::increaseSpeed();
	this->timeDelay = DEAFULTSPEED / MovingObject::getSpeed();
}

Game::Game()
{
	if (this->backgroundTexture.loadFromFile("../Resources/Background.png"))
	{
		srand(static_cast<int>(time(0)));
		this->backgroundImage = sf::Sprite(this->backgroundTexture);
		this->backgroundImage.setTextureRect(sf::IntRect(0, 0, static_cast<int>(BACKGROUNDIMAGESIZE.x), static_cast<int>(BACKGROUNDIMAGESIZE.y)));
		this->backgroundImage.setPosition(0, 0);
		this->scale = sf::Vector2f(windowSize.x / BACKGROUNDIMAGESIZE.x, windowSize.y / BACKGROUNDIMAGESIZE.y);
		this->backgroundImage.setScale(this->scale);
		this->randomNr = rand() % 3;
		this->lockalClock;
		this->projectiles = new Projectile*[NROFPROJECTILES];
		for (int i = 0; i < NROFPROJECTILES; i++)
		{
			this->projectiles[i] = new Projectile("../Resources/Projectile.png", PROJECTILEIMAGESIZE, 0.0, 0.0, this->scale);
		}
		this->player = new Player("../Resources/Player.png", PLAYERIMAGESIZE , static_cast<float>((windowSize.x - ((PLAYERIMAGESIZE.x * this->scale.x) / 2)) / 2.0), static_cast<float>(windowSize.y - (PLAYERIMAGESIZE.y * this->scale.y)), this->scale, this->projectiles, this->NROFPROJECTILES);
		this->nrOfWaves = this->DEAFULTNROFWAVES;
		this->waves = new Wave*[this->nrOfWaves];
		for (int i = 0; i < this->nrOfWaves; i++)
		{
			this->waves[i] = new Wave("../Resources/Enemy.png", ENEMYIMAGESIZE, this->scale, 5, (ENEMYIMAGESIZE.y * i * this->scale.y) + (20 * i));
		}
		this->nrOfRounds = 1;
		this->isPaused = false;
		MovingObject::resetSpeed();
		this->timeDelay = DEAFULTSPEED / MovingObject::getSpeed();
		MovingObject::resetGlobalClock();
	}
	else
	{
		throw "Exception: Could not load texture";
	}
}

void Game::togglePaused()
{
	if (this->isPaused)
	{
		MovingObject::resetGlobalClock();
		this->isPaused = false;
	}
	else
	{
		this->isPaused = true;
	}
}

bool Game::getIsPaused() const
{
	return this->isPaused;
}

void Game::update()
{
	if (!this->isPaused)
	{
		MovingObject::resetGlobalClock();
		this->player->update();
		this->updateProjectiles();
		this->updateWaves();
		this->havePlayerCollided();
		this->haveProjectilesCollided();
	}
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->backgroundImage, states);
	this->player->draw(target, states);
	for (int i = 0; i < this->NROFPROJECTILES; i++)
	{
		if (this->projectiles[i]->isActive())
		{
			this->projectiles[i]->draw(target, states);
		}
	}
	for (int i = 0; i < this->nrOfWaves; i++)
	{
		this->waves[i]->draw(target, states);
	}
}

int Game::getNrOfRounds() const
{
	return this->nrOfRounds;
}

bool Game::isGameOver() const
{
	if (this->player->isAlive())
	{
		return false;
	}
	else
	{
		return true;
	}
}

Game::~Game()
{
	for (int i = 0; i < this->NROFPROJECTILES; i++)
	{
		delete this->projectiles[i];
	}
	delete[] this->projectiles;
	delete this->player;
	for (int i = 0; i < this->nrOfWaves; i++)
	{
		delete this->waves[i];
	}
	delete[] this->waves;
}