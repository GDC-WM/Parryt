#include <SFML/Audio.hpp>

/* Manages all of the sound effects for the game */
class soundEffect {

    /* Use these functions to play, pause, stop, and open music files */

    public:
        soundEffect(std::string SoundEffectPath);   /* SE means Sound Effect */
        ~soundEffect();
        void setSoundBuffer();
        void playSE();


    private:
        sf::SoundBuffer Buffer;
        sf::Sound SoundEffect;

/*
    Add Sound effects in the game by using this method:
    sf::SoundBuffer [SOUND_EFFECT_NAME];
    sf::Sound [SOUND_EFFECT_NAME];
*/
};
