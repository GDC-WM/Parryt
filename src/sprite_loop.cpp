#include <SFML/Graphics.hpp>
#include <chrono>

#include "sprite_loop.hpp"


SpriteLoop::SpriteLoop(const std::string &spriteSheet, const sf::Vector2f &spriteSize) {
	this->texture.loadFromFile(spriteSheet);
	this->sprite = sf::Sprite(texture, sf::IntRect(0, 0, 64,64));
	this->sprite.setScale(0.08,0.08);
	std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();
	int iter = 0;

	/*
	for(int i = startFrame; i < frames; i++){
		if(divisionSize.x*iter == this->sprite.getSize().x){
			divisionSize.y+=divisionSize.y;
			iter = 0;
		}
		this->sprite.setOrigin(divisionSize.x*iter, divisionSize.y);
		iter++;
	}
	*/
}


void SpriteLoop::setFrame(const int &frame) {
}


void SpriteLoop::reset(void) {

}
