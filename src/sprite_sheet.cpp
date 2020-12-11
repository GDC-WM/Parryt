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
	this->startTime = std::chrono::steady_clock::now();
}


sf::Sprite &SpriteSheet::getSprite(void) {
	using ms = std::chrono::milliseconds;
	ms dt = std::chrono::duration_cast<ms>(std::chrono::steady_clock::now() - this->startTime);
	int n = dt.count() / this->loop.frameTime;
	this->setFrame(n % this->loop.frames);
	return (this->sprite);
}


void SpriteSheet::setFrame(const int &frame) {
	int globalFrame = this->loop.start + frame;
	this->spriteRect.top = this->spriteRect.height * (globalFrame / this->sheetSize.x); // rounds down
	this->spriteRect.left = this->spriteRect.width * (globalFrame % this->sheetSize.x); // remainder
	this->sprite.setTextureRect(this->spriteRect);
}
