#include "dialogue.hpp"


dialogue::dialogue(std::string Text)
{

//set what the text is going to say
dialogueText.setString(Text);

dialogueText.setCharacterSize(24);
dialogueText.setOrigin(0,0);
}


dialogue::~dialogue()
{

}
