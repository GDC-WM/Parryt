#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <chrono>

#include "sprite_loop.hpp"
#include "actor.hpp"
#include "character.hpp"


SpriteLoop::SpriteLoop(std::string spriteSheet, sf::Vector2f divisionSize, int startFrame, int frames, float frameTime){

	this->spriteSheet.loadFromFile(spriteSheet);
	this->sprite = sf::Sprite(this->spriteSheet, sf::IntRect(0, 0, 64,64));
	//sprite.setScale(0.08,0.08);
	std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();
	int iter = 0;

	//TODO: have it iterate over using the timer
	
		for(int i = startFrame; i < frames; i++){
			if(divisionSize.x*iter == this->spriteSheet.getSize().x){
				divisionSize.y+=divisionSize.y;
				iter = 0;
			}
			this->sprite.setOrigin(divisionSize.x*iter, divisionSize.y);
			iter++;
		}
}


void SpriteLoop::reset(void) {

}