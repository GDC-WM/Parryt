#include "music.hpp"


musicTrack::musicTrack(std::string musicPath) {music.openFromFile(musicPath);}

musicTrack::~musicTrack() {}

void musicTrack::stopTrack() {music.stop();}

void musicTrack::pauseTrack() {music.pause();}

void musicTrack::playTrack(){
    music.setVolume(50);
    music.play();
    music.setLoop(true);
}

/*
    Play music track like this:

	musicTrack ShipTrack("../resources/MainTheme.wav");
	ShipTrack.playTrack();
*/
