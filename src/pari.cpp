#include <SFML/Graphics.hpp>

#include "pari.hpp"
#include <iostream>


Pari::Pari(double x, double y) : Character(x, y, 64, 64, 10, 180, 200, 50) {
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(this->width, this->height));

//placeholder to link base png as Pari
//        sf::Texture texture;
//        if(!texture.loadFromFile("/Users/*/./ParryT/WM-GDC-Parryt/src/Parryt-2.png")){std::cout<<"daaaang"<<std::endl; system("pause");}
//        sf::Sprite sprite;
//        sprite.setTexture(texture);
//        sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
}
