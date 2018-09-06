#include "Health.h"

Health::Health(const int healthPoints)
{
	this->healthPoints = healthPoints;
}

Health::Health(const Health & originalHealth)
{
	this->healthPoints = originalHealth.healthPoints;
}

Health & Health::operator=(const Health & originalHealth)
{
	if (&originalHealth != this)
	{
		this->healthPoints = originalHealth.healthPoints;
	}
	return *this;
}

int Health::getHealthPoints() const
{
	return this->healthPoints;
}

void Health::reduceHealthPoints()
{
	this->healthPoints--;
}

bool Health::isAlive() const
{
	if (this->healthPoints > 0)
	{
		return true;
	}
	return false;
}

Health::~Health()
{
}
