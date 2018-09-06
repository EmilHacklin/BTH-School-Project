#pragma once
#include"Player.h"
#include"Wave.h"
#include"Projectile.h"

const sf::Vector2f BACKGROUNDIMAGESIZE = sf::Vector2f(2560.0, 1440.0);

class Game : public sf::Transformable ,public sf::Drawable
{
private:
	sf::Texture backgroundTexture;
	sf::Sprite backgroundImage;
	sf::Vector2f scale;
	sf::Clock lockalClock;
	int randomNr;
	float timeDelay;
	Player *player;
	Projectile* *projectiles;
	Wave* *waves;
	int nrOfWaves;
	int nrOfRounds;
	bool isPaused;
	const int DEAFULTNROFWAVES = 3;
	const int NROFPROJECTILES = 20;
	bool isWavesDestroyed();
	void havePlayerCollided();
	void haveProjectilesCollided();
	void updateProjectiles();
	void updateWaves();
	void newWaves();
public:
	Game() throw(...);
	void togglePaused();
	bool getIsPaused() const;
	virtual void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	int getNrOfRounds() const;
	bool isGameOver() const;
	~Game();
};

