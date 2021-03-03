#include "music.hpp"


Sounds::Sounds(std::string musicPath) {music.openFromFile(musicPath);}

Sounds::~Sounds() {}

void Sounds::stopTrack() {music.stop();}

void Sounds::pauseTrack() {music.pause();}

void Sounds::playTrack(){
    music.setVolume(50);
    music.play();
    music.setLoop(true);
}

