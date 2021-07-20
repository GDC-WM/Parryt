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
	this->mastShape.SetAsBox(this->WIDTH, this->HEIGHT);
	this->priority = 6;

	// fix shape to body
	this->bodyDef.type = b2_staticBody;
	this->fixtureDef.shape = &this->mastShape;
	this->fixtureDef.density = 3.0f;
	this->fixtureDef.friction = 0.7f;

	// load image
	MastTexture.loadFromFile("../resources/mast.png");
	this->mastSprite = sf::Sprite(MastTexture);

	// set scale and origin
	mastSprite.setScale(.20,.20);
	this->mastSprite.setOrigin(this->WIDTH, this->HEIGHT);

	// add 'x' platforms to the mast
	// set constants
	
	const float yMast = position.y;
	const float xMast = position.x + 12.5;
	// loop for 'x' amount of times
	for (int i = 0; i < nPlatforms; i++) {
		float hPlatform =  position.y - (yMast / nPlatforms);
		position.Set(xMast, hPlatform);
		printf("\n\nx:%f\n\ny:%f", position.x, position.y);
		auto object = std::make_shared<Platform>(position,5);
		gameState->addActor(object);
	}
}
// Testing; mast should not collide with player
const bool Mast::shouldCollide(const Actor &a) const {
	return false;
}

void Mast::draw(std::shared_ptr<sf::RenderWindow> window) {
	this->mastSprite.setPosition(this->getBody()->GetPosition().x,
	                          -this->getBody()->GetPosition().y);
	window->draw(this->mastSprite);
}