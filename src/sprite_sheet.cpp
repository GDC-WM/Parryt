#include <SFML/Graphics.hpp>
#include <chrono>

#include "sprite_sheet.hpp"


SpriteSheet::SpriteSheet(const std::string &spriteSheet, const sf::Vector2i &spriteSize) {
	// load a sprite sheet
	this->texture.loadFromFile(spriteSheet);

	// calculate sprite dimensions
	this->sheetSize.x = this->texture.getSize().x / spriteSize.x;
	this->sheetSize.y = this->texture.getSize().y / spriteSize.y;

	// give sprite a rectangle
	this->spriteRect = sf::IntRect(sf::Vector2i(0,0), spriteSize);
	this->sprite = sf::Sprite(texture, this->spriteRect);
	this->sprite.setScale(0.08,0.08);
	this->sprite.setOrigin(spriteSize.x * .04, spriteSize.y * .04);
	this->startTime = std::chrono::steady_clock::now();

	this->oneShot = {0,0,0}; // default to no oneShot
}


sf::Sprite &SpriteSheet::getSprite(void) {
	int dt = std::chrono::duration_cast<std::chrono::milliseconds>
	         (std::chrono::steady_clock::now() - this->startTime).count();

	// check for oneshot
	Loop curLoop = dt < this->oneShot.frameTime * this->oneShot.frames? this->oneShot : this->baseLoop;

	// set frame
	int n = dt / curLoop.frameTime;
	int frame = curLoop.start + n % curLoop.frames;
	if (mirrored) frame += curLoop.frames;
	this->setFrame(frame);
	return (this->sprite);
}


void SpriteSheet::setLoop(const int &start, const int &frames, const int &frameTime) {
	this->setLoop(Loop{start, frames, frameTime});
}


void SpriteSheet::setLoop(const Loop &loop) {
	this->baseLoop = loop;
	this->oneShot = {0, 0, 0};
}


void SpriteSheet::setOneShot(const Loop &loop) {
	this->oneShot = loop;
	this->startTime = std::chrono::steady_clock::now();
}


void SpriteSheet::setFrame(const int &frame) {
	this->spriteRect.top = this->spriteRect.height * (frame / this->sheetSize.x); // rounds down
	this->spriteRect.left = this->spriteRect.width * (frame % this->sheetSize.x); // remainder
	this->sprite.setTextureRect(this->spriteRect);
}
