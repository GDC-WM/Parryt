#ifndef SPRITE_LOOP_HPP
#define SPRITE_LOOP_HPP


#include <SFML/Graphics.hpp>
#include <chrono>


struct Loop { int start, frames, frameTime; };


/**
 * Facilitates creating a sequence of sprites from a spritesheet.
 */
class SpriteLoop {
	public:
		/**
		 * @param spriteSheet filename
		 * @param spriteSize the vector size of a sprite in pixels (x,y) on the sprite sheet
		 */
		SpriteLoop(const std::string &spriteSheet, const sf::Vector2i &spriteSize);

		/**
		 * @return the current sprite
		 */
		sf::Sprite &getSprite(void);

		/**
		 * Set the loop within the sprite sheet.
		 *
		 * @param loop new loop
		 */
		void setLoop(const Loop &loop) { this->loop = loop; };

		/**
		 * Set the loop within the sprite sheet.
		 *
		 * @param start the frame number of the first frame in the sequence
		 * @param frames the number of frames in the sequence
		 * @param frameTime the time between each frame of the animation
		 */
		void setLoop(const int &start, const int &frames, const int &frameTime) { this->loop = {start, frames, frameTime}; };

		/**
		 * Reset the animation to the first frame in the sequence.
		 */
		void reset(void);


	private:
		sf::Texture texture;
		sf::Sprite sprite;
		sf::IntRect spriteRect; // pixels
		sf::Vector2i sheetSize; // rows/columns
		Loop loop;
		std::chrono::system_clock::time_point startTime;

		/**
		 * Set the frame within the frame loop.
		 *
		 * @param frame number ordered left to right, top to bottom
		 */
		void setFrame(const int &frame);
};


#endif
