#ifndef MAST_HPP
#define MAST_HPP


#include <box2d/box2d.h>

#include "actor.hpp"

class Platform;
class GameState;

class Mast : public Actor {
public:
	// set Width and Height of mast
	static constexpr float WIDTH = 1.9;
	static constexpr float HEIGHT = 0.1;

	Mast(b2Vec2 position, std::shared_ptr<GameState> gameState, int nPlatforms);

	const bool shouldCollide(const Actor &a) const override;

	virtual void draw(std::shared_ptr<sf::RenderWindow> window) override;

private:
	b2PolygonShape mastShape;
	b2Vec2 coords;
	sf::RectangleShape drawable;
	sf::Texture MastTexture;
	sf::Sprite mastSprite;
};


#endif
