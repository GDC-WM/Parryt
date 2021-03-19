#ifndef SPRITE_SHEET_HPP
#define SPRITE_SHEET_HPP


#include <SFML/Graphics.hpp>
#include <chrono>


//TODO: move this into seperate file, make it a class?
struct Loop {
	int start, frames, frameTime;
	Loop mirror() {
		Loop mirrorLoop = *this;
		mirrorLoop.start += frames;
		return mirrorLoop;
	};

	bool operator==(Loop l) {
		return l.start == this->start
		    && l.frames == this->frames
		    && l.frameTime == this->frameTime;
	}

	bool operator!=(Loop l) { return !operator==(l); }
};


/**
 * Facilitates creating an animation from a spritesheet.
 */
class SpriteSheet {
public:
	/**
	 * @param spriteSheet filename
	 * @param spriteSize the vector size of a sprite in pixels (x,y) on the sprite sheet
	 */
	SpriteSheet(const std::string &spriteSheet, const sf::Vector2i &spriteSize);

	/**
	 * First updates the sprite to the proper frame, then returns
	 *
	 * @return the sprite
	 */
	sf::Sprite &getSprite(void);

	/**
	 * @return the current loop.
	 */
	const Loop &getLoop(void) { return this->baseLoop; };

	/**
	 * Set the loop within the sprite sheet.
	 *
	 * @param loop new loop
	 */
	void setLoop(const Loop &loop);

	/**
	 * Set the loop within the sprite sheet.
	 *
	 * @param start the frame number of the first frame in the sequence
	 * @param frames the number of frames in the sequence
	 * @param frameTime the time between each frame of the animation
	 */
	void setLoop(const int &start, const int &frames, const int &frameTime);

	/**
	 * Run a loop one time, then return to the last loop.
	 *
	 * @param loop oneshot loop
	 */
	void setOneShot(const Loop &loop);

	/**
	 * Reset the animation to the first frame in the sequence.
	 */
	void restart(void) { this->startTime = std::chrono::steady_clock::now(); };


private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::IntRect spriteRect; // pixels
	sf::Vector2i sheetSize; // rows/columns
	Loop baseLoop;
	Loop oneShot;
	std::chrono::steady_clock::time_point startTime;

	/**
	 * Set the frame of the animation
	 *
	 * @param frame number ordered left to right, top to bottom
	 */
	void setFrame(const int &frame);
};


#endif
