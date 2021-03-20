#ifndef MUSIC_HPP
#define MUSIC_HPP

#include <SFML/Audio.hpp>

/* Manages all of the music for the game */
class musicTrack{

    /* Use these functions to play, pause, stop, and open Music files */

    public:
        musicTrack(std::string musicPath);
        ~musicTrack();
        void playTrack();
        void stopTrack();
        void pauseTrack();

    private:
        sf::Music music;

};

#endif
