#pragma once
class Health
{
private:
	int healthPoints;
public:
	Health(const int healthPoints = 3);
	Health(const Health &originalHealth);
	Health& operator=(const Health &originalHealth);
	int getHealthPoints() const;
	void reduceHealthPoints();
	bool isAlive() const;
	~Health();
};

