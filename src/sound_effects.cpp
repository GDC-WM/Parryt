#include "sound_effects.hpp"

soundEffect::soundEffect(std::string SoundEffectPath) {Buffer.loadFromFile(SoundEffectPath);}

soundEffect::~soundEffect() {}

void soundEffect::setSoundBuffer() {SoundEffect.setBuffer(Buffer);}

void soundEffect::playSE() 
{
    setSoundBuffer();
    SoundEffect.play();
}

/* 
Use the Sound Effect like this:

	soundEffect Jump("../resources/MainTheme.wav");
	Jump.playSE();

*/