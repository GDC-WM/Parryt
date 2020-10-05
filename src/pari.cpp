#include <SFML/Graphics.hpp>

#include "pari.hpp"
#include <iostream>


Pari::Pari(double x, double y) : Character(x, y) {
	// fix shape to body
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 0.3f;

	// set drawable
	this->drawable.setFillColor(sf::Color::Green);
	this->drawable.setSize(sf::Vector2f(64, 64));

//placeholder to link base png as Pari
//        sf::Texture texture;
//        if(!texture.loadFromFile("/Users/*/./ParryT/WM-GDC-Parryt/src/Parryt-2.png")){std::cout<<"daaaang"<<std::endl; system("pause");}
//        sf::Sprite sprite;
//        sprite.setTexture(texture);
//        sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
}
