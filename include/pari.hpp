#ifndef PARI_HPP
#define PARI_HPP


#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <chrono>

#include "actor.hpp"
#include "character.hpp"
#include "sprite_sheet.hpp"


/**
 * The main character
 */
class Pari : public Character {
public:
	static constexpr float WIDTH = 0.5;

	static constexpr float HEIGHT = 1.9;

	Pari(b2Vec2 position);

	bool jump(void) override;

	void onCollision(Actor &a) override;

	void draw(std::shared_ptr<sf::RenderWindow> window) override;

	/**
	 * @return true if Pari is currently parrying
	 */
	const bool isParrying(void) const { return std::chrono::steady_clock::now() - this->parryStart < this->parryDuration; };

	/**
	 * @return true if Pari can pari (is not recharging)
	 */
	const bool canParry(void) const { return std::chrono::steady_clock::now() - this->parryStart > this->parryRechargeDuration; };

	/**
	 * Make Pari parry!
	 *
	 * @param angle The direction to parry in
	 * @return whether Pari was able to try to Pari (was not recharging)
	 */
	bool parry(float angle);


private:
	std::chrono::steady_clock::time_point parryStart;
	std::chrono::milliseconds parryDuration;
	std::chrono::milliseconds parryRechargeDuration;
	float parryAngle;

	sf::RectangleShape drawable;
	sf::Texture texture;
	b2PolygonShape shape;
	Loop standLoop { 22, 3, 400 };
	Loop runLoop { 0, 6, 170 };
	Loop jumpLoop { 28, 5, 170 };
	std::unique_ptr<SpriteSheet> spriteSheet;
	sf::Sprite sprite;
};


#endif
