#ifndef SPRITE_LOOP_HPP
#define SPRITE_LOOP_HPP


#include <SFML/Graphics.hpp>
#include <chrono>


struct Loop {
	int start, frames, frameTime;
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
		SpriteLoop(const std::string &spriteSheet, const sf::Vector2i &spriteSize);

		/**
		 * @return the current sprite
		 */
		sf::Sprite &getSprite(void);

		/**
		 * Set the loop within the sprite sheet.
		 */
		void setLoop(const Loop &loop) { this->loop = loop; };

		/**
		 * Reset the animation to the first frame in the sequence.
		 */
		void reset(void);


	private:
		sf::Texture texture;
		sf::Sprite sprite;
		sf::IntRect spriteRect; // pixels
		sf::Vector2i sheetSize;  // rows/columns
		Loop loop;
		int startFrame;
		std::chrono::system_clock::time_point startTime;

		/**
		 * Set the frame within the frame loop.
		 */
		void setFrame(const int &frame);
};


#endif
