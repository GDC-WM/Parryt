#ifndef SPRITE_LOOP_HPP
#define SPRITE_LOOP_HPP

#include <SFML/Graphics.hpp>

class SpriteReader {
		public:
			SpriteReader(std::string spriteSheet);

			/**
			 * Step to the next image in the loop
			 *
			 * @return returns the next image
			 */
			sf::Sprite step(void);

			/**
			 * @param sprite is the sprite we wish to change position
			 * @param x is the x coordinate where we wish to move
			 * @param y is the y coordinate where we wish to move
			 */
			void setImgPosition(sf::Sprite sprite, int x, int y);

		private:
				sf::Texture spriteSheet;
};

#endif
