#include "Game.hpp"

Game::Game() :mPlayer(1)
{
	if (mBackgroundTex.loadFromFile("../Resources/background.jpg"))
	{
		// Handle error
	}
	mBackgroundSprite.setTexture(mBackgroundTex);
}

void Game::Update(float dt)
{
	// Make sure everything in the game is updated (if needed).
	mPlayer.Update(dt);
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Make sure everything in the game is drawn.
	target.draw(mBackgroundSprite, states);
	target.draw(mPlayer, states);
}