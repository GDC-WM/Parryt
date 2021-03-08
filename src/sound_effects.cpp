#include "sound_effects.hpp"
#include "character.hpp"
#include "pari.hpp"

soundEffect::soundEffect(std::string SEPath) {Buffer.loadFromFile(SEPath);}

soundEffect::~soundEffect() {}

void soundEffect::setSoundBuffer() {SoundEffect.setBuffer(Buffer);}

void soundEffect::playSE() 
{
    /* Set the Sound Buffer */
    setSoundBuffer();
    /* Play the loaded Sound Effect */
    SoundEffect.play();
}

/* 

Use the Sound Effect like this:

	soundEffect Jump("../resources/MainTheme.wav");
	Jump.playSE();

*/