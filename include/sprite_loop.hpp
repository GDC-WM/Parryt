#ifndef SPRITE_LOOP_HPP
#define SPRITE_LOOP_HPP


#include <SFML/Graphics.hpp>


/**
 * Facilitates creating a sequence of sprites from a spritesheet.
 */
class SpriteLoop {
	public:
		/**
		 * @param spriteSheet filename
		 * @param divisionSize the vector size of a sprite in pixels (x,y) on the sprite sheet
		 * @param startFrame the number of the first frame on the sprite sheet in the animation
		 * @param frames the number of frames in the sequence
		 * @param refreshRate the rate that the animation runs at (frames per second)
		 */
		SpriteLoop(std::string spriteSheet, sf::Vector2f divisionSize, int startFrame, int frames, float refreshRate);

		/**
		 * @return the current sprite
		 */
		sf::Sprite &getSprite(void);

		/**
		 * Reset the animation to the first frame in the sequence.
		 */
		void reset(void);


	private:
		sf::Texture spriteSheet;
		sf::Sprite sprite;
		int startFrame;
		int frames;
		float refreshRate;

};


#endif
