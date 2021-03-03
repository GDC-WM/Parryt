#include "music.hpp"


Sounds::Sounds(std::string musicPath){
    music.openFromFile(musicPath);
}


Sounds::~Sounds()
{
    //Nothing
}


void Sounds::stopTrack(){
    sf::Music music;
    music.stop();
    
}

void Sounds::pauseTrack(){
    sf::Music music;
    music.pause();
    
}

void Sounds::playTrack(){
    music.setVolume(50);
    music.play();
}

