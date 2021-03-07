#include <sound_effect.hpp>

soundEffect::loadSoundEffectFile(std::string SEPath) {Buffer.loadFromFile(SEPath)}

void soundEffect::setSoundBuffer() {SoundEffect.setBuffer(Buffer);}

void soundEffect::playSE(std::string SEPath) 
{
    /* Load the file first */
    loadSoundEffectFile(SEPath);
    /* Set the Sound Buffer */
    setSoundBuffer();
    /* Play the loaded Sound Effect */
    SoundEffect.play();
}
