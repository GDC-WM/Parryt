#include <SFML/Graphics.hpp>
#include <chrono>

#include "sprite_sheet.hpp"


SpriteSheet::SpriteSheet(const std::string &spriteSheet, const sf::Vector2i &spriteSize) {
	this->texture.loadFromFile(spriteSheet);
	this->sheetSize.x = this->texture.getSize().x / spriteSize.x;
	this->sheetSize.y = this->texture.getSize().y / spriteSize.y;

	this->spriteRect = sf::IntRect(sf::Vector2i(0,0), spriteSize);
	this->sprite = sf::Sprite(texture, this->spriteRect);
	this->sprite.setScale(0.08,0.08);
	this->startTime = std::chrono::system_clock::now();

	this->oneShot = {0,0,0}; // default to no oneShot
}


sf::Sprite &SpriteSheet::getSprite(void) {
	int dt = std::chrono::duration_cast<std::chrono::milliseconds>
			(std::chrono::system_clock::now() - this->startTime).count();

	// check for oneshot
	Loop curLoop = dt < this->oneShot.frameTime * this->oneShot.frames? this->oneShot : this->baseLoop;

	// set frame
	int n = dt / curLoop.frameTime;
	this->setFrame(curLoop.start + n % curLoop.frames);
	return (this->sprite);
}


void SpriteSheet::setLoop(const int &start, const int &frames, const int &frameTime) {
	this->baseLoop = {start, frames, frameTime};
	this->oneShot = {0, 0, 0};
}


void SpriteSheet::setLoop(const Loop &loop) {
	this->baseLoop = loop;
	this->oneShot = {0, 0, 0};
}


void SpriteSheet::setOneShot(const Loop &loop) {
	this->oneShot = loop;
	this->startTime = std::chrono::system_clock::now();
}


void SpriteSheet::setFrame(const int &frame) {
	this->spriteRect.top = this->spriteRect.height * (frame / this->sheetSize.x); // rounds down
	this->spriteRect.left = this->spriteRect.width * (frame % this->sheetSize.x); // remainder
	this->sprite.setTextureRect(this->spriteRect);
}
