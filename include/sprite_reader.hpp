#ifndef SPRITE_READER_HPP
#define SPRITE_READER_HPP

#include <SFML/Graphics.hpp>

class SpriteReader {
		public:
			/**
			 * @param sprite is the image to switch to
			 */
			void stepToNextImage(sf::Sprite sprite);

			/**
			 * @param sprite is the sprite we wish to change position
			 * @param x is the x coordinate where we wish to move
			 * @param y is the y coordinate where we wish to move
			 */
			void setImgPosition(sf::Sprite sprite, int x, int y);

		private:
				sf::Texture texture;
};

#endif
