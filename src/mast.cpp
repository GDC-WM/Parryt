#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "character.hpp"
#include "mast.hpp"
#include "platform.hpp"



Mast::Mast(b2Vec2 position) : Actor(position) {

    this->bodyDef.type = b2_staticBody;
    
    this->mastShape.SetAsBox(1, this->HEIGHT);

    // load image
    MastTexture.loadFromFile("../resources/mast.png");
    this->mastSprite = sf::Sprite(MastTexture);
    
    // set scale and origin
    mastSprite.setScale(glob::scale,glob::scale);
	this->mastSprite.setOrigin(1, 1);

}

void Mast::draw(std::shared_ptr<sf::RenderWindow> window) {
	this->mastSprite.setPosition(this->getBody()->GetPosition().x,
	                          -this->getBody()->GetPosition().y);
	window->draw(this->mastSprite);
}