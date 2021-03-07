#include <SFML/Audio.hpp>
#include <iostream>

/* Manages all of the music for the game. Will most likely put Sound Effects in a different file. */
class soundEffect {

    /* Use these functions to play, pause, stop, and open music files */

    public:
        loadSoundEffect(std::string SEPath);   /* SE means Sound Effect */
        ~loadSoundEffect();
        void setSoundBuffer();
        void playSE();


    private:
        sf::SoundBuffer Buffer;
        sf::Sound SoundEffect;

        /*
        NOTE - Add Sound effects in the game by using this method:
        sf::SoundBuffer [SOUND_EFFECT_NAME];
        sf::Sound [SOUND_EFFECT_NAME];
        */
};
