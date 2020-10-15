#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "character.hpp"
#include "pari.hpp"


Pari::Pari(double x, double y) : Character(x, y) {
	this->shape.SetAsBox(this->WIDTH, this->HEIGHT);
	// fix shape to body
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 0.3f;

	// set drawable
	this->drawable.setOrigin(this->WIDTH, this->HEIGHT);
	this->drawable.setFillColor(sf::Color::Green);
	this->drawable.setSize(sf::Vector2f(this->WIDTH * 2, this->HEIGHT * 2));

//placeholder to link base png as Pari
//        sf::Texture texture;
//        if(!texture.loadFromFile("/Users/*/./ParryT/WM-GDC-Parryt/src/Parryt-2.png")){std::cout<<"daaaang"<<std::endl; system("pause");}
//        sf::Sprite sprite;
//        sprite.setTexture(texture);
//        sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
}
