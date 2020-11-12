#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "sprite_loop.hpp"
#include "actor.hpp"
#include "character.hpp"



SpriteLoop::SpriteLoop(std::string spriteSheet, sf::Vector2f divisionSize, int startFrame, int frames, float frameTime){

spriteSheet.loadFromFile(spriteSheet);
this->sprite = sf::Sprite(texture, sf::IntRect(0, 0, 64,64));
sprite.setScale(0.08,0.08);
this->sprite.setOrigin( , );

//TODO have it iterate over using the timer
int iter = 0;
    for(int i = startFrame; i < frames; i++){
        if(divisionSize.x*iter == spriteDim){
            divisionSize.y+=divisionSize.y;
        }
        this->sprite.setOrigin(divisionSize.x*iter, divisionSize.y);
        iter++;
    }
}

void SpriteLoop::reset(void) {

}