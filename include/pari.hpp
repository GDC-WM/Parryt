#ifndef PARI_HPP
#define PARI_HPP


#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "character.hpp"
#include "sprite_sheet.hpp"
#include <chrono>


/**
 * The main character
 */
class Pari : public Character {
public:
	static constexpr float WIDTH = 0.5;

	static constexpr float HEIGHT = 1.9;

	Pari(b2Vec2 position);

	bool jump(void) override;

	void onCollision(Actor & a);

	void draw(std::shared_ptr<sf::RenderWindow> window) override;

	void setIsDeflecting(bool isDeflecting) { this->isDeflecting = isDeflecting; }

	void setDeflectStartTime(std::chrono::steady_clock::time_point deflectStartTime) { this-> deflectStartTime = deflectStartTime; }

	const bool getIsDeflecting() { return this->isDeflecting; }

	const std::chrono::steady_clock::time_point getDeflectStartTime(){return this->deflectStartTime;}


private:
	sf::RectangleShape drawable;
	sf::Texture texture;
	b2PolygonShape shape;
	Loop standLoop { 22, 3, 400 };
	Loop runLoop { 0, 6, 170 };
	Loop jumpLoop { 28, 3, 170 };
	std::unique_ptr<SpriteSheet> spriteSheet;
	sf::Sprite sprite;

protected:
	bool isDeflecting;
	std::chrono::steady_clock::time_point deflectStartTime;
};




#endif
