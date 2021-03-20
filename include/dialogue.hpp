#ifndef DIALOGUE_HPP
#define DIALOGUE_HPP

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class dialogue
{

    public:
        dialogue(std::string Text);
        ~dialogue();
    private:
        sf::Text dialogueText;
        sf::RectangleShape dialogueBox;
        
};

#endif
