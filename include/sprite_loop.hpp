#ifndef SPRITE_LOOP_HPP
#define SPRITE_LOOP_HPP


#include <SFML/Graphics.hpp>
#include <chrono>


struct Loop {
	int start, frames;
	float frameTime;

	//Loop{const int &start; const int &frames};
};


/**
 * Facilitates creating a sequence of sprites from a spritesheet.
 */
class SpriteLoop {
	public:
		/**
		 * @param spriteSheet filename
		 * @param spriteSize the vector size of a sprite in pixels (x,y) on the sprite sheet
		 * @param frameTime the time between each frame of the animation
		 */
		SpriteLoop(const std::string &spriteSheet, const sf::Vector2f &spriteSize);

		/**
		 * @return the current sprite
		 */
		sf::Sprite &getSprite(void) { return this->sprite; };

		void setLoop(const Loop &loop) { this->loop = loop; };

		/**
		 * Reset the animation to the first frame in the sequence.
		 */
		void reset(void);


	private:
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Vector2f spriteSize;
		Loop loop;
		int startFrame;
		int frames;
		float frameTime;
		std::chrono::system_clock::time_point startTime;

		void setFrame(const int &frame);
};


#endif
