#include "SFML/Audio.hpp"

/* Manages all of the music for the game. Will most likely put Sound Effects in a different file. */
class musicTrack{

    /* Use these functions to play, pause, stop, and open music files */

    public:
        musicTrack(std::string musicPath);
        ~musicTrack();
        void playTrack();
        void stopTrack();
        void pauseTrack();

    private:
        sf::Music music;

        /*
        NOTE - Add Sound effects in the game by using this method:
        sf::SoundBuffer [SOUND_EFFECT_NAME];
        sf::Sound [SOUND_EFFECT_NAME];
        */
};
