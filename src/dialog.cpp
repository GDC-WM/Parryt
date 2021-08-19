#include "dialog.hpp"

DialogSystem::DialogSystem() {

}

DialogSystem::~DialogSystem() {}

bool DialogSystem::ReturnBoolIsInDialog() {
	return isInDialog;
}

void DialogSystem::Advance(std::string FileName) {

	std::fstream input(FileName);
	getline(input,dialogContent);
	dialogText.setString(dialogContent);

}

void DialogSystem::End() {}

void DialogSystem::End() {}

void DialogSystem::Load_SetDialogText(std::string FontPath,std::string FileName) {

	dialogFont.loadFromFile(FontPath);
	dialogText.setFont(dialogFont);

	std::fstream input(FileName);
	getline(input,dialogContent);
	dialogText.setString(dialogContent);

}

void DialogSystem::SetDialogTextScale_Size(float xscale,float yscale, int charSize) {

	dialogText.setScale(xscale, yscale);
	dialogText.setCharacterSize(charSize);

}

void DialogSystem::SetDialogTextStyle_Color(textStyle style,SetColor textColor) {

	switch (style) {
		case Underline:
			dialogText.setStyle(sf::Text::Underlined);
			break;
		case Bold:
			dialogText.setStyle(sf::Text::Bold);
			break;
		case Underline_Bold:
			dialogText.setStyle(sf::Text::Underlined | sf::Text::Bold);
			break;
		default:
			break;
	}
	
	switch (textColor) {
		case White:
			dialogText.setFillColor(sf::Color::White);
			break;
		case Red:
			dialogText.setFillColor(sf::Color::Red);
			break;
		case Blue:
			dialogText.setFillColor(sf::Color::Blue);
			break;
		case Green:
			dialogText.setFillColor(sf::Color::Green);
			break;
		default:
			break;
	}

}

void DialogSystem::SetDialogTextPosition(float posx,float posy) {

	dialogText.setPosition(posx, posy);

}

void DialogSystem::SetDialogBoxStyle(int outlineThickness, SetColor FillColor, SetColor outlineColor) {

	dialogBox.setOutlineThickness(outlineThickness);

	switch (FillColor) {
		case White:
			dialogBox.setFillColor(sf::Color::White);
			break;
		case Red:
			dialogBox.setFillColor(sf::Color::Red);
			break;
		case Blue:
			dialogBox.setFillColor(sf::Color::Blue);
			break;
		case Green:
			dialogBox.setFillColor(sf::Color::Green);
			break;
		default:
			break;
	}

	switch (outlineColor) {
		case White:
			dialogBox.setOutlineColor(sf::Color::White);
			break;
		case Red:
			dialogBox.setOutlineColor(sf::Color::Red);
			break;
		case Blue:
			dialogBox.setOutlineColor(sf::Color::Blue);
			break;
		case Green:
			dialogBox.setOutlineColor(sf::Color::Green);
			break;
		default:
			break;
	}
	
}

void DialogSystem::SetDialogBoxSize(int sizex,int sizey) {

	dialogBox.setSize(sf::Vector2f(sizex,sizey));

}

void DialogSystem::SetDialogBoxPosition(float posx, float posy) {
	dialogBox.setPosition(sf::Vector2f(posx,posy));
}

void DialogSystem::DrawDialog(std::shared_ptr<sf::RenderWindow> window) {

	isInDialog = true;
	window->draw(dialogBox);
	window->draw(dialogText);

}
