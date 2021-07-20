#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "character.hpp"
#include "mast.hpp"
#include "platform.hpp"

#include "game_state.hpp"
#include "game_state_factory.hpp"


Mast::Mast(b2Vec2 position, std::shared_ptr<GameState> gameState, int nPlatforms) : Actor(position) {
	// set shape
	this->mastShape.SetAsBox(this->WIDTH, nPlatforms * 10);
	this->priority = 6;

	// fix shape to body
	this->bodyDef.type = b2_staticBody;
	this->fixtureDef.shape = &this->mastShape;

	// load image
	MastTexture.loadFromFile("../resources/mast.png");
	this->mastSprite = sf::Sprite(MastTexture);

	// set scale and origin
	this->mastSprite.setScale(glob::scale, glob::scale);
	this->mastSprite.setOrigin(this->WIDTH / 2, nPlatforms * 5);

	// add 'n' platforms to the mast
	for (int i = 1; i <= nPlatforms; i++) {
		gameState->addActor(std::make_shared<Platform>(b2Vec2(position.x, position.y + i * 10), 5));
	}
}


const bool Mast::shouldCollide(const Actor &a) const {
	return false;
}


void Mast::draw(std::shared_ptr<sf::RenderWindow> window) {
	this->mastSprite.setPosition(glob::convertVec(this->getBody()->GetPosition()));
}
